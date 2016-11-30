#-------------------------------------------------
#
# Project created by QtCreator 2016-11-15T00:28:04
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    snake.cpp \
    snakebody.cpp \
    food.cpp \
    gameover.cpp

HEADERS  += mainwindow.h \
    snake.h \
    snakebody.h \
    food.h \
    gameover.h

FORMS    += mainwindow.ui \
    gameover.ui

RESOURCES += \
    resources.qrc
