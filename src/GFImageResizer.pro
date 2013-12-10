CONFIG += debug_and_release
CONFIG(debug, debug|release) {
  BUILD_DIRECTORY = ../build/debug
  DESTDIR = ../bin/debug
  OBJECTS_DIR = $${BUILD_DIRECTORY}
  MOC_DIR = $${BUILD_DIRECTORY}
  RCC_DIR = $${BUILD_DIRECTORY}
}
CONFIG(release, debug|release) {
  BUILD_DIRECTORY = ../build/release
  DESTDIR = ../bin/release
  OBJECTS_DIR = $${BUILD_DIRECTORY}
  MOC_DIR = $${BUILD_DIRECTORY}
  RCC_DIR = $${BUILD_DIRECTORY}
}
     

QT       += core widgets

TARGET = GFImageResizer
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
