QT += core
QT -= gui

CONFIG += c++11

TARGET = Project_3A_Anansa
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    body.cpp \
    odesolver.cpp \
    system.cpp \
    potential.cpp

HEADERS += \
    body.h \
    odesolver.h \
    system.h \
    potential.h
