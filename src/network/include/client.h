/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#ifndef CLIENT_H
#define CLIENT_H

#include "connection.h"

namespace gene
{
    /*! \class Client
     *  \brief Client side manipulation.
     *  \author Yuri 'Ree' Borisoff
     *  \author Mailto: yuri.borisoff@gmail.com
     *  \version 1.0
     *  \date    2010-2010
     *
     *  Class that provides client side routines
    */

class Client : public QObject
{
    Q_OBJECT
public:
    Client(QObject *parent = 0);
    virtual ~Client();

public:
    /*!
        * Adds \a request support to client.
    */
    void addRequest(RequestPtr request);

    /*!
        * Sends \a request with given parameters \a params
    */
    void sendRequest(const QString& request, const QVariant &params);

public slots:
    /*!
        * Connect to host with given \a ip and \a port
    */
    void connectToHost(const QString& ip, int port);

private slots:
    void connectionError(QAbstractSocket::SocketError socketError);
    void disconnectSocket();
    void connectSocket();

signals:
    /*!
        * The signal is emitted whenever connection state is changed.
        * \n\a connected argument is connection state.
    */
    void clientConnected(bool connected);

private:
    Connection *m_connection;
};

}

#endif // CLIENT_H
