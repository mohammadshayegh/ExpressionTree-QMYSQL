#-------------------------------------------------
#
# Project created by QtCreator 2018-01-04T11:12:05
#
#-------------------------------------------------

QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = treeW
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp\
    stack.cpp \
    expressiontree.cpp \
    traversal.cpp \
    node.cpp \
    charidentifier.cpp \
    database.cpp

HEADERS  += dialog.h\
    stack.h \
    expressiontree.h \
    traversal.h \
    node.h \
    charidentifier.h \
    database.h


FORMS    += dialog.ui

win32: LIBS += -L$$PWD/../mysql-connector-c-6.1.11-win32/lib/ -llibmysql

INCLUDEPATH += $$PWD/../mysql-connector-c-6.1.11-win32/include
DEPENDPATH += $$PWD/../mysql-connector-c-6.1.11-win32/include
