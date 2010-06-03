/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#include "connection.h"

#include <QStringList>

#include <GLog>

namespace gene
{

Connection::Connection(QObject *parent)
    :QTcpSocket(parent)
{
}

void Connection::send(const QString& request, const QVariant &params)
{
    if (m_requests.contains(request))
    {
        m_requests.value(request)->send(this, params);
    } else
    {
        LOG_WARNING(QString("Request %1 is missing").arg(request));
    }
}

void Connection::broadcast(const QString &request, const QVariant &params)
{
    if (m_requests.contains(request))
    {
        m_requests.value(request)->broadcast(this, params);
    } else
    {
        LOG_WARNING(QString("Request %1 is missing").arg(request));
    }
}

void Connection::processRequest()
{
    QDataStream stream(this);
    stream.setVersion(QDataStream::Qt_4_4);

    while (readHeader(stream))
    {
        QString requestType;
        stream >> requestType;

        if (m_requests.contains(requestType))
        {
            m_requests.value(requestType)->processRequest(this, stream);
        }  else
        {
            LOG_WARNING(QString("Invalid incoming request %1").arg(requestType));
        }
    }
}

void Connection::processResponse()
{
    QDataStream stream(this);
    stream.setVersion(QDataStream::Qt_4_4);

    while (readHeader(stream))
    {
        QString responseType;
        stream >> responseType;

        if (m_requests.contains(responseType))
        {
            m_requests.value(responseType)->processResponse(stream);
        } else
        {
            LOG_WARNING(QString("Invalid incoming response %1").arg(responseType));
        }
    }
}

bool Connection::readHeader(QDataStream &stream)
{
    quint16 blockSize(0);
    int bytes(0);
    if ((bytes = bytesAvailable()) < static_cast<int>(sizeof(quint16)))
        return false;
    stream >> blockSize;
    if (((bytes = bytesAvailable()) < static_cast<int>(blockSize)))
        return false;

    return true;
}

QVariant Connection::param(const QString& paramName) const
{
    QVariant pm;
    if (m_params.contains(paramName))
    {
        pm = m_params.value(paramName);
    } else
    {
        LOG_ERROR(QString("Invalid parameter name %1").arg(paramName));
    }
    return pm;
}

void Connection::setParam(const QString& paramName, const QVariant &param)
{
    m_params[paramName] = param;
}

void Connection::addRequest(RequestPtr request)
{
    QString requestId = request->requestString();
    if (!m_requests.contains(requestId))
    {
        m_requests.insert(requestId, request);
    } else
    {
        LOG_WARNING(QString("Request %1 already exists").arg(requestId));
    }
}

}

