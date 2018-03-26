#-------------------------------------------------
#
# Project created by QtCreator 2018-03-23T23:07:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11


TARGET = qffect
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qeditor.cpp \
    effectmanager.cpp \
    effectcommand.cpp \
    ieffect.cpp \
    exif.cpp \
    effects/mono/monoeffect.cpp \
    effects/sepia/sepiaeffect.cpp

HEADERS += \
        mainwindow.h \
    qeditor.h \
    effectmanager.h \
    effectcommand.h \
    ieffect.h \
    exif.h\
    effects/mono/monoeffect.h \
    effects/sepia/sepiaeffect.h

FORMS += \
        mainwindow.ui
