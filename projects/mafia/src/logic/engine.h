/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

namespace gene
{
    class Server;
    class Client;
}

typedef gene::Server Server;
typedef gene::Client Client;

class Engine : public QObject
{
Q_OBJECT
public:
    explicit Engine(QObject *parent = 0);
    virtual ~Engine();

signals:

public slots:


public:
    void start(int listenPort);
    void stop();

    void join();
    void leave();

private:
    Server *m_server;
    Client *m_client;
};

#endif // ENGINE_H
