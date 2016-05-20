QT += core
QT += network
QT += gui
QT += widgets

CONFIG += c++11

TARGET = sockets
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ami.cpp \
    ptt.cpp \
    amimsg.cpp \
    amiaction.cpp \
    amiclient.cpp

HEADERS += \
    ami.h \
    ptt.h \
    amimsg.h \
    amiaction.h \
    amiclient.h
