/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#include "server.h"

#include <QHostAddress>
#include <QNetworkInterface>
#include <QStringList>

namespace gene
{

Server::Server(int listenPort, QObject *parent)
    : QTcpServer(parent)
    ,m_listenPort(listenPort)
{
}

void Server::setRequests(const QList<RequestPtr> &requests)
{
    m_requestsForConnection = requests;
}

void Server::incomingConnection(int socketDescriptor)
{
    Connection *connection = new Connection(this);
    connection->setSocketDescriptor(socketDescriptor);

    setupConnection(connection);
    connect(connection, SIGNAL(disconnected()), SLOT(disconnectSocket()));
    connect(connection, SIGNAL(error(QAbstractSocket::SocketError)),
            SLOT(connectionError(QAbstractSocket::SocketError)));
    connect(connection, SIGNAL(readyRead()), connection, SLOT(processRequest()));

    connect(connection, SIGNAL(logMessage(const QString&)), this, SIGNAL(logMessage(const QString&)));

    m_connections.push_back(connection);
}

void Server::setupConnection(Connection *connection)
{
    foreach(RequestPtr request, m_requestsForConnection)
    {
        connection->addRequest(request);
    }
}

void Server::removeConnection(Connection *connection)
{
    if (m_connections.contains(connection))
    {
        emit playerLeft(connection->param("name").toString());
        m_connections.removeAll(connection);
    }
    connection->deleteLater();
}


void Server::connectionError(QAbstractSocket::SocketError /*socketError*/)
{
    Connection *connection = qobject_cast<Connection *>(sender());
    if (connection)
        removeConnection(connection);
}

void Server::disconnectSocket()
{
    Connection *connection = qobject_cast<Connection *>(sender());
    if (connection)
        removeConnection(connection);
}

void Server::setListening(bool listening)
{
   if (!listening)
    {
        close();
    } else
    {
        if (!listen(QHostAddress::Any, m_listenPort))
        {
            emit serverError(errorString());
        } else
        {
            QString ipAddress;
            QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
            // use the first non-localhost IPv4 address
            for (int i = 0; i < ipAddressesList.size(); ++i) {
                if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                 ipAddressesList.at(i).toIPv4Address())
                 ipAddress = ipAddressesList.at(i).toString();
            }
            // if we did not find one, use IPv4 localhost
            if (ipAddress.isEmpty())
                ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
            emit serverStarted(ipAddress, serverPort());
        }
    }
}

bool Server::isPlayerConnected(const QString &userName) const
{
    foreach(Connection *connection, m_connections)
    {
        if (connection->param("name").toString() == userName)
          return true;
    }
    return false;
}

void Server::broadcast(const QString &request, const QVariant &params,
                       Server::BroadcastPolicy policy, const QStringList &nodes, const QString &cp)
{
    foreach(Connection *connection, m_connections)
    {
        switch (policy)
        {
        case BroadcastAll:
            connection->broadcast(request, params);
            break;
        case BroadcastInclude:
            if (nodes.contains(connection->param(cp).toString()))
            {
                connection->broadcast(request, params);
            }
            break;
        case BroadcastExlude:
            if (!nodes.contains(connection->param(cp).toString()))
            {
                connection->broadcast(request, params);
            }
            break;
        }
    }
}

}
