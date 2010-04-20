/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#ifndef CONNECTION_H
#define CONNECTION_H

#include <QTcpSocket>

#include "request.h"

namespace gene
{

    /*! \class Connection
     *  \brief Perform tcp reading/writing
     *  \author Yuri 'Ree' Borisoff
     *  \author Mailto: yuri.borisoff@gmail.com
     *  \version 1.0
     *  \date    2010-2010
     *
     *  Provide QTcpSocket extention.
    */

class Connection : public QTcpSocket
{
Q_OBJECT
public:
    /*!
        * Constructs an object
    */
    explicit Connection(QObject *parent = 0);

    /*!
        * Copy constructor
    */
    Connection(const Connection &connection);

    /*!
        * Add \a request support to connection
    */
    void addRequest(RequestPtr request);

    /*!
        * Returns the value for connection parameter \a paramName
    */
    QVariant param(const QString& paramName) const;

    /*!
        * Sets parameter \a paramName to the given \a params
    */
    void setParam(const QString& paramName, const QVariant &param);

public slots:
    /*!
        * Send the \a request with given parameters \a params
    */
    void send(const QString& request, const QVariant &params);

    /*!
        * Broadcast the \a request with given parameters \a params
    */
    void broadcast(const QString &request, const QVariant &params);

    /*!
        * Process the incoming data (server side).
    */
    void processRequest();

    /*!
        * Process the incoming data (client side).
    */
    void processResponse();

private:
    bool readHeader(QDataStream &stream);

private:
    QMap<QString, RequestPtr> m_requests;
    QMap<QString, QVariant>   m_params;
};

}

#endif // CONNECTION_H
