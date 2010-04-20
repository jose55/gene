/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#include "client.h"

#include <GLog>

namespace gene
{

Client::Client(QObject *parent)
    :QObject(parent)
{
    m_connection = new Connection(this);

    connect(m_connection, SIGNAL(connected()), SLOT(connectSocket()));
    connect(m_connection, SIGNAL(disconnected()), SLOT(disconnectSocket()));
    connect(m_connection, SIGNAL(error(QAbstractSocket::SocketError)),
            SLOT(connectionError(QAbstractSocket::SocketError)));
    connect(m_connection, SIGNAL(readyRead()), m_connection, SLOT(processResponse()));

}

Client::~Client()
{
}

void Client::connectToHost(const QString& ip, int port)
{
    m_connection->abort();
    m_connection->connectToHost(ip, port);
    LOG_INFO(QString("Establishing connection on ip %1 port %2").arg(ip, port));
}

void Client::connectionError(QAbstractSocket::SocketError socketError)
{
    LOG_INFO(QString("Error connecting to host: %1").arg(m_connection->errorString()));
    emit clientConnected(false);
}

void Client::disconnectSocket()
{
    LOG_INFO(QString("Disconnected from host"));
    emit clientConnected(false);
}

void Client::connectSocket()
{
    LOG_INFO(QString("Connected to host"));
    emit clientConnected(true);
}

void Client::addRequest(RequestPtr request)
{
    m_connection->addRequest(request);
}

void Client::sendRequest(const QString& request, const QVariant &params)
{
    m_connection->send(request, params);
}

}
