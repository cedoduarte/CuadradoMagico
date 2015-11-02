#-------------------------------------------------
#
# Project created by QtCreator 2015-11-01T16:36:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CuadradoMagico
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    NumeroEnteroDelegate.cpp

HEADERS  += Widget.h \
    NumeroEnteroDelegate.h

FORMS    += Widget.ui

QMAKE_CXXFLAGS += -std=gnu++14
