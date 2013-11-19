#-------------------------------------------------
#
# Project created by QtCreator 2013-11-18T10:42:07
#
#-------------------------------------------------

QT       += core

INCLUDEPATH += /usr/include/ImageMagick
LIBS += -lMagick++ -lMagickCore

TARGET = GFImageResizer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    resolution.cpp \
    resolutions.cpp

HEADERS += \
    resolution.hpp \
    resolutions.hpp