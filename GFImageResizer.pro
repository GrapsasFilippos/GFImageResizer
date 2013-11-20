#-------------------------------------------------
#
# Project created by QtCreator 2013-11-18T10:42:07
#
#-------------------------------------------------

QT       += core widgets

TARGET = GFImageResizer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    resolution.cpp \
    resolutions.cpp \
    GUI/mainwindow.cpp \
    geometry.cpp

HEADERS += \
    resolution.hpp \
    resolutions.hpp \
    GUI/mainwindow.hpp \
    geometry.hpp
