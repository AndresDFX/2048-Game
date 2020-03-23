#-------------------------------------------------
#
# Project created by QtCreator 2020-03-11T13:19:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    core/tree.cpp \
        gui/mainwindow.cpp \
    core/tile.cpp \
    core/board.cpp \
    core/game.cpp \
    gui/qgameboard.cpp \
    gui/qtile.cpp \
    gui/qresetbutton.cpp \
    core/observer.cpp \
    core/subject.cpp \
    gui/qgameoverwindow.cpp

HEADERS  += gui/mainwindow.h \
    core/tile.h \
    core/board.h \
    core/game.h \
    core/tree.h \
    gui/qgameboard.h \
    gui/qtile.h \
    gui/qresetbutton.h \
    core/observer.h \
    core/subject.h \
    gui/qgameoverwindow.h \
    gui/qwinwindow.h
