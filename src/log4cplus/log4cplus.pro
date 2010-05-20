TEMPLATE = lib
CONFIG += staticlib \
    debug_and_release
CONFIG -= qt
CONFIG(release, debug|release):TARGET = log4cpp
else:TARGET = log4cppd

MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build
DESTDIR = ../../lib
INCLUDEPATH = include
HEADERS += include/log4cplus/win32debugappender.h \
    include/log4cplus/win32consoleappender.h \
    include/log4cplus/tstring.h \
    include/log4cplus/syslogappender.h \
    include/log4cplus/streams.h \
    include/log4cplus/socketappender.h \
    include/log4cplus/nullappender.h \
    include/log4cplus/ndc.h \
    include/log4cplus/loglevel.h \
    include/log4cplus/loggingmacros.h \
    include/log4cplus/logger.h \
    include/log4cplus/layout.h \
    include/log4cplus/hierarchylocker.h \
    include/log4cplus/hierarchy.h \
    include/log4cplus/fstreams.h \
    include/log4cplus/fileappender.h \
    include/log4cplus/consoleappender.h \
    include/log4cplus/configurator.h \
    include/log4cplus/config.hxx \
    include/log4cplus/appender.h
LIBS += lws2_32
SOURCES += src/win32debugappender.cxx \
    src/win32consoleappender.cxx \
    src/timehelper.cxx \
    src/threads.cxx \
    src/syncprims.cxx \
    src/stringhelper.cxx \
    src/socket-win32.cxx \
    src/socketbuffer.cxx \
    src/socketappender.cxx \
    src/socket.cxx \
    src/sleep.cxx \
    src/rootlogger.cxx \
    src/property.cxx \
    src/pointer.cxx \
    src/patternlayout.cxx \
    src/objectregistry.cxx \
    src/nullappender.cxx \
    src/ndc.cxx \
    src/logloguser.cxx \
    src/loglog.cxx \
    src/loglevel.cxx \
    src/loggingevent.cxx \
    src/loggerimpl.cxx \
    src/logger.cxx \
    src/layout.cxx \
    src/hierarchylocker.cxx \
    src/hierarchy.cxx \
    src/global-init.cxx \
    src/filter.cxx \
    src/fileappender.cxx \
    src/factory.cxx \
    src/consoleappender.cxx \
    src/configurator.cxx \
    src/appenderattachableimpl.cxx \
    src/appender.cxx
