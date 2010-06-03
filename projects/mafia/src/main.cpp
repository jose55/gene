/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#include <QtGui/QApplication>
#include <QTranslator>

#include "ui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("server_ru");
    a.installTranslator(&translator);

    MainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}
