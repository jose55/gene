TEMPLATE = app
CONFIG += debug_and_release
CONFIG(release, debug|release) {
TARGET = mafia
LIBS += -L../../bin -lnetwork
}
CONFIG(debug, debug|release) {
TARGET = mafiad
LIBS += -L../../bin -lnetworkd
}
QT += network
MOC_DIR = generated
RCC_DIR = build
UI_DIR = generated
OBJECTS_DIR = build
DESTDIR = ../../bin
INCLUDEPATH = ../../include \
    generated \
    include \
	$$(THIRD_PARTY)
SOURCES += src/main.cpp \
    src/ui/mainwindow.cpp \
    src/logic/engine.cpp \
    src/ui/startserverdialog.cpp \
    src/ui/joindialog.cpp
HEADERS += include/ui/mainwindow.h \
    include/logic/engine.h \
    src/logic/engine.h \
    src/ui/mainwindow.h \
    src/ui/startserverdialog.h \
    src/ui/joindialog.h
FORMS += ui/mainwindow.ui \
    ui/startserverdialog.ui \
    ui/joindialog.ui
