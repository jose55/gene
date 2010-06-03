TEMPLATE = lib
CONFIG += dll \
    debug_and_release

LIBS += -L../../lib -llog4cpp -lws2_32

CONFIG(release, debug|release){
TARGET = network
}
else{
TARGET = networkd
}
QT += network
QT -= gui
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build

DLLDESTDIR = ../../bin

DESTDIR = ../../lib
INCLUDEPATH = include \
    ../../include \
    ../log4cplus/include
HEADERS += include/tcpwriter.h \
    include/request.h \
    include/connection.h \
    include/server.h \
    include/client.h
SOURCES += src/tcpwriter.cpp \
    src/connection.cpp \
    src/server.cpp \
    src/client.cpp


