/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>
#include <QSharedPointer>
#include <QDataStream>

class QTcpSocket;

namespace gene
{

/*! \interface IRequest
 *  \brief Interface for all network requests
 *  \author Yuri 'Ree' Borisoff
 *  \author Mailto: yuri.borisoff@gmail.com
 *  \version 1.0
 *  \date    2010-2010
 *
*/

class IRequest : public QObject
{
    Q_OBJECT
public:
    /*!
        * Returns string indicating request name.
    */
    virtual         QString requestString() const = 0;

    virtual         ~IRequest() {}

public slots:
    /*!
        * Send the request with given parameters \a params
    */
    virtual         void send (QTcpSocket *socket, const QVariant &params) = 0;

    /*!
        * Broadcast the request with given parameters \a params
    */
    virtual         void broadcast  (QTcpSocket *socket, const QVariant &params) = 0;

    /*!
        * Process the request with input stream \a in.
        * \n Send response to \a socket.
        * \n Mostly server-side function.
    */
    virtual         void processRequest     (QTcpSocket *socket, QDataStream &in) = 0;

    /*!
        * Process the request with input stream \a in.
        * \n Send response to \a socket.
        * \n Mostly client-side function.
    */
    virtual         void processResponse    (QDataStream &in) = 0;

protected:
    explicit        IRequest(QObject *parent = 0) : QObject(parent) {}
};

/*! \typedef RequestPtr
    * Shared pointer for Request interface
*/
typedef QSharedPointer<IRequest>   RequestPtr;

}
#endif // REQUEST_H
