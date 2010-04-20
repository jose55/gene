TEMPLATE = lib
CONFIG += dll \
    debug_and_release
CONFIG(release, debug|release):TARGET = network
else:TARGET = networkd
QT += network
QT -= gui
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build
DESTDIR = ../../bin
INCLUDEPATH = include \
    ../../include
HEADERS += include/tcpwriter.h \
    include/request.h \
    include/connection.h \
    include/server.h \
    include/client.h
SOURCES += src/tcpwriter.cpp \
    src/connection.cpp \
    src/server.cpp \
    src/client.cpp
