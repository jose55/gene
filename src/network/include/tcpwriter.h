/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#ifndef TCPWRITER_H
#define TCPWRITER_H

#include <QByteArray>
#include <QDataStream>

class QTcpSocket;

namespace gene{

    /*! \class TcpWriter
     *  \brief Helper class for writing data to QTcpSocket
     *  \author Yuri 'Ree' Borisoff
     *  \author Mailto: yuri.borisoff@gmail.com
     *  \version 1.0
     *  \date    2010-2010
     *
     *  Prepere data to write it to QTcpSocket.
     *  Perform writing in destructor.
     *  Uses \a Qt_4_4 version of data format
    */

class IRequest;

class TcpWriter
{
public:
    /*!
        Constructor. Create buffer and bind it to QTcpSocket.
        \param socket - QTcpSocket for writing.
    */
    explicit TcpWriter(QTcpSocket *socket);

    /*!
      Constructor. Create buffer, bind it to QTcpSocket and automaticly writes request name to it.
      \param socket - QTcpSocket for writing.
      \param request - Request for writing.
    */
    TcpWriter(QTcpSocket *socket, IRequest *request);

    //! Destructor. Writes data to socket.
    ~TcpWriter();

    /*!
        * Writes the given \a value to the specified \a stream. \n
        * Type \a T must provide operator <<.
    */
    template <typename T> friend TcpWriter & operator << (TcpWriter &stream, const T& value);
private:
    QTcpSocket *m_socket;
    QByteArray m_block;
    QDataStream m_out;
};

template <typename T> inline TcpWriter & operator << (TcpWriter &stream, const T& value)
{
    stream.m_out << value;
    return stream;
}

}

#endif // TCPWRITER_H
