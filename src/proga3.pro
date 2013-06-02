#-------------------------------------------------
#
# Project created by QtCreator 2010-12-08T21:07:16
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = proga3
TEMPLATE = app
    -std=c++0x \
    -Woverloaded-virtual \
    -Wundef
#CONFIG += plugin
#TEMPLATE = lib

SOURCES += main.cpp\
        mainwindow.cpp \
    fieldgraph.cpp \
    proga3plugin.cpp

HEADERS  += mainwindow.h \
    fieldgraph.h \
    proga3plugin.h

FORMS    += mainwindow.ui
TRANSLATIONS = ../translations/ru_RU.ts
