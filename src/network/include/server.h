/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QList>
#include <QStringList>

#include "connection.h"

namespace gene
{

    /*! \class Server
     *  \brief Server side manipulation.
     *  \author Yuri 'Ree' Borisoff
     *  \author Mailto: yuri.borisoff@gmail.com
     *  \version 1.0
     *  \date    2010-2010
     *
     *  Class that provides server side routines. Accepting and manipulating connections
    */


class Server : public QTcpServer
{
    Q_OBJECT
public:
    /*!
        *  \enum Server::BroadcastPolicy
        Denotes policy for inclusion or exclusion nodes for broadcast requests
    */
    enum BroadcastPolicy
    {
        BroadcastAll,     /*!< Broadcast to all nodes.*/
        BroadcastInclude, /*!< Broadcast only to listed nodes.*/
        BroadcastExlude   /*!< Do not broadcast only to listed nodes.*/
    };

    /*!
        * Creates server object. Sets listen port to \a listenPort.
    */
    explicit Server(int listenPort, QObject *parent = 0);

    /*!
        * Sets \a requests supported by server.
    */
    void setRequests(const QList<RequestPtr> &requests);

    /*!
        * If \a listening is true, the server listens incoming connection; otherwise it stop listening.
    */
    void setListening(bool listening);

    /*!
      * Checks if \a userName is connected.
      * \n It uses \a name parameter in Connection.
    */
    bool isPlayerConnected(const QString &userName) const;

public slots:
    /*!
      * Broadcast the \a request with given parameters \a params.
      * To \a nodes that satisfy \a policy by parametr \a cp
      *
    */
    void broadcast(const QString &request, const QVariant &params,
                   BroadcastPolicy policy = BroadcastAll,
                   const QStringList &nodes = QStringList(),
                   const QString &cp = "name");

signals:
    /*!
      * Signal is emmited when server is started with \a ip adress and listen \a port.
    */
    void serverStarted(const QString &ip, int port);
    /*!
      * Signal is emmited when connection \a name is closed.
    */
    void playerLeft(const QString &name);
    /*!
      * Signal is emmited when server encountered an \a error.
    */
    void serverError(const QString &error);

private slots:
    void connectionError(QAbstractSocket::SocketError socketError);
    void disconnectSocket();

private:
    virtual void    incomingConnection  (int socketDescriptor);
            void    removeConnection    (Connection *connection);
            void    setupConnection     (Connection *connection);

private:
    QList<Connection *> m_connections;
    QList<RequestPtr> m_requestsForConnection;
    int m_listenPort;
};

}

#endif

