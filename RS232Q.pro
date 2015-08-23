#-------------------------------------------------
#
# Project created by QtCreator 2015-08-21T22:57:10
#
#-------------------------------------------------
CONFIG += c++11
QT       += core gui
QT += widgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RS232Q
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    out.cpp \
    port.cpp

HEADERS  += mainwindow.h \
    out.h \
    port.h

FORMS    += mainwindow.ui
