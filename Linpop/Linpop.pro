#-------------------------------------------------
#
# Project created by QtCreator 2013-03-04T02:33:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Linpop
TEMPLATE = app


SOURCES += main.cpp\
        loginwindow.cpp \
    contactwindow.cpp \
    addcontactwindow.cpp \
    historywindow.cpp \
    uploadwindow.cpp \
    downloadwindow.cpp \
    conversationwindow.cpp \
    addcontactchatwindow.cpp

HEADERS  += loginwindow.h \
    contactwindow.h \
    addcontactwindow.h \
    historywindow.h \
    uploadwindow.h \
    downloadwindow.h \
    conversationwindow.h \
    addcontactchatwindow.h

FORMS    += loginwindow.ui \
    contactwindow.ui \
    addcontactwindow.ui \
    historywindow.ui \
    uploadwindow.ui \
    downloadwindow.ui \
    conversationwindow.ui \
    addcontactchatwindow.ui
