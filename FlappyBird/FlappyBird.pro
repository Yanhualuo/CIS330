#-------------------------------------------------
#
# Project created by QtCreator 2017-2-22
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlappyBird
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameelement.cpp \
    background.cpp \
    bird.cpp \
    ground.cpp \
    overboard.cpp \
    pipe.cpp \
    readyboard.cpp \
    scoreboard.cpp \
    titleboard.cpp

HEADERS  += \
    gameelement.hpp \
    mainwindow.hpp \
    pipe.hpp \
    overboard.hpp \
    ground.hpp \
    background.hpp \
    bird.hpp \
    readyboard.hpp \
    scoreboard.hpp \
    titleboard.hpp

RESOURCES += \
    resource/image.qrc

OTHER_FILES +=