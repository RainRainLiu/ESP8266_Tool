#-------------------------------------------------
#
# Project created by QtCreator 2016-12-11T19:44:44
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ESP8266_Tool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myserialport.cpp

HEADERS  += mainwindow.h \
    myserialport.h

FORMS    += mainwindow.ui

RESOURCES += \
    esp8266_tool.qrc

