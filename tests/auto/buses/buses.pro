#-------------------------------------------------
#
# Project created by QtCreator 2017-01-23T18:42:39
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_channelstest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_busestest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

include(../../../ObjectBus/ObjectBusInl.pri)
