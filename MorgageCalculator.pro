#-------------------------------------------------
#
# Project created by QtCreator 2016-06-21T20:05:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MorgageCalculator
TEMPLATE = app


SOURCES += main.cpp\
        MorgageCalculator.cpp \
    MainDialog.cpp \
    Planner.cpp \
    MortgagePiece.cpp \
    libs.cpp

HEADERS  += MorgageCalculator.h \
    MainDialog.h \
    Planner.h \
    MortgagePiece.h \
    libs.h

FORMS    += MorgageCalculator.ui \
    MainDialog.ui \
    Planner.ui \
    MortgagePiece.ui
