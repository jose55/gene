/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#include "tcpwriter.h"

#include <QTcpSocket>

#include "request.h"

namespace gene{

gene::TcpWriter::TcpWriter(QTcpSocket *socket):
    m_socket(socket),
    m_out(&m_block, QIODevice::WriteOnly)
{
    m_out.setVersion(QDataStream::Qt_4_4);
}

TcpWriter::TcpWriter(QTcpSocket *socket, IRequest *request) :
        m_socket(socket),
        m_out(&m_block, QIODevice::WriteOnly)
{
    m_out.setVersion(QDataStream::Qt_4_4);
    m_out << (quint16)0 << request->requestString();
}

TcpWriter::~TcpWriter()
{
    m_out.device()->seek(0);
    m_out << (quint16)(m_block.size() - sizeof(quint16));
    m_socket->write(m_block);
}

}
