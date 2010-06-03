/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#include "engine.h"

#include <GServer>

Engine::Engine(QObject *parent) :
    QObject(parent)
    ,m_server(0)
    ,m_client(0)
{
}

Engine::~Engine()
{

}

void Engine::start(int listenPort)
{
    m_server = new Server(listenPort, this);
}

void Engine::stop()
{

}

void Engine::join()
{

}

void Engine::leave()
{

}
