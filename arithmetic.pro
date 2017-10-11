#-------------------------------------------------
#
# Project created by QtCreator 2017-10-07T00:03:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = arithmetic
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    formula/Fraction.cpp \
    formula/Generate.cpp \
    language/Language.cpp

HEADERS  += mainwindow.h \
    formula/ASMDOperation.h \
    formula/Fraction.h \
    formula/Generate.h \
    formula/Operation.h \
    formula/OperationFactory.h \
    language/Language.h \
    ui_mainwindow.h \
    language/English.h \
    language/Languages.h \
    language/Chinese.h \
    language/Chinese_t.h

FORMS    += mainwindow.ui

RESOURCES += \
    myicon.qrc
RC_ICONS = arithmetic.ico

DISTFILES += \
    formula/Main.exe
