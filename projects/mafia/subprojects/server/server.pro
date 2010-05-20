TEMPLATE = app
CONFIG += debug_and_release
CONFIG(release, debug|release):TARGET = mafiaServer
else:TARGET = mafiaServerd
QT += network
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build
DESTDIR = ../../bin
INCLUDEPATH = ../../../../include \
    ../../include
HEADERS += mafiaserverwidget.h
SOURCES += mafiaserverwidget.cpp \
    main.cpp
FORMS += mafiaserverwidget.ui
