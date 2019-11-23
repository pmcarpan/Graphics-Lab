#-------------------------------------------------
#
# Project created by QtCreator 2019-08-13T17:02:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graphics_lab
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

CONFIG += c++11

SOURCES += \
        bezieralgorithms.cpp \
        beziermenu.cpp \
        circlealgorithms.cpp \
        circlemenu.cpp \
        drawsignalemitter.cpp \
        durationemitter.cpp \
        ellipsealgorithms.cpp \
        ellipsemenu.cpp \
        gridmenu.cpp \
        gridmodel.cpp \
        gridtableview.cpp \
        linealgorithms.cpp \
        linemenu.cpp \
        main.cpp \
        menuforlines.cpp \
        polygonalgorithms.cpp \
        polygonemitter.cpp \
        polygonmenu.cpp \
        transformationalgorithms.cpp \
        transformationmenu.cpp \
        widget.cpp

HEADERS += \
        bezieralgorithms.h \
        beziermenu.h \
        circlealgorithms.h \
        circlemenu.h \
        drawsignalemitter.h \
        durationemitter.h \
        ellipsealgorithms.h \
        ellipsemenu.h \
        gridmenu.h \
        gridmodel.h \
        gridtableview.h \
        linealgorithms.h \
        linemenu.h \
        menuforlines.h \
        polygonalgorithms.h \
        polygonemitter.h \
        polygonmenu.h \
        transformationalgorithms.h \
        transformationmenu.h \
        widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
