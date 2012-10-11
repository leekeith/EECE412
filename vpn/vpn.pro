#-------------------------------------------------
#
# Project created by QtCreator 2012-10-10T16:49:59
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vpn
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        mainwindow.cpp \
    connectionmanager.cpp \
    logging.cpp

HEADERS  += mainwindow.h \
    connectionmanager.h \
    logging.h

FORMS    += mainwindow.ui
