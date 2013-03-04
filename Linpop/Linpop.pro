#-------------------------------------------------
#
# Project created by QtCreator 2013-03-04T02:33:43
#
#-------------------------------------------------

QT       += core gui network

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
    addcontactchatwindow.cpp \
    networkserver.cpp \
    networkobject.cpp \
    networkclient.cpp \
    circularbuffer.cpp \
    protocolinterpretor.cpp \
    protocolcommandparamconv.cpp \
    protocolcommandparamuser.cpp \
    protocolcommandparamtext.cpp \
    protocolcommandparamfile.cpp \
    protocolcommandparameter.cpp \
    protocolcommand.cpp \
    corprotocolinputcommandbuilder.cpp \
    protocolinputcommandbuilder.cpp \
    protocoloutputcommandfactory.cpp \
    outputcommandmessagetransfertfile.cpp \
    outputcommandmessageacceptfile.cpp \
    outputcommandmessagedeconnection.cpp \
    outputcommandmessagejoin.cpp \
    outputcommandmessageinvitation.cpp \
    outputcommandmessageping.cpp \
    outputcommandmessagepong.cpp \
    outputcommandmessagesend.cpp \
    filetransfertupload.cpp \
    mainwindow.cpp \
    contextualmenupopup.cpp

HEADERS  += loginwindow.h \
    contactwindow.h \
    addcontactwindow.h \
    historywindow.h \
    uploadwindow.h \
    downloadwindow.h \
    conversationwindow.h \
    addcontactchatwindow.h \
    networkserver.h \
    networkobject.h \
    networkclient.h \
    circularbuffer.h \
    protocolinterpretor.h \
    protocolcommandparamconv.h \
    protocolcommandparamuser.h \
    protocolcommandparamtext.h \
    protocolcommandparamfile.h \
    protocolcommandparameter.h \
    protocolcommand.h \
    corprotocolinputcommandbuilder.h \
    protocolinputcommandbuilder.h \
    protocoloutputcommandfactory.h \
    outputcommandmessagetransfertfile.h \
    outputcommandmessageacceptfile.h \
    outputcommandmessagedeconnection.h \
    ouputcommandmessagesend.h \
    outputcommandmessagesend.h \
    outputcommandmessagejoin.h \
    outputcommandmessageinvitation.h \
    outputcommandmessagepong.h \
    outputcommandmessageping.h \
    filetransfertupload.h \
    protocolcommandtype.h \
    protocolcommandexecutionmode.h \
    mainwindow.h \
    contextualmenupopup.h

FORMS    += loginwindow.ui \
    contactwindow.ui \
    addcontactwindow.ui \
    historywindow.ui \
    uploadwindow.ui \
    downloadwindow.ui \
    conversationwindow.ui \
    addcontactchatwindow.ui \
    mainwindow.ui \
    contextualmenupopup.ui
