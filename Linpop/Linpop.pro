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
    corcommandmessagedeconnection.cpp \
    corcommandmessagepong.cpp \
    corcommandmessagejoin.cpp \
    corcommandmessageacceptfile.cpp \
    corcommandmessageinvitation.cpp \
    corcommandmessageping.cpp \
    corcommandmessagesend.cpp \
    corcommandmessagetransfertfile.cpp \
    inputcommandmessageacceptfile.cpp \
    inputcommandmessagetransfertfile.cpp \
    inputcommandmessageping.cpp \
    inputcommandmessagejoin.cpp \
    inputcommandmessagesend.cpp \
    inputcommandmessagedeconnection.cpp \
    inputcommandmessageinvitation.cpp \
    inputcommandmessagepong.cpp

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
    ProtocolCommandType.h \
    ProtocolCommandExecutionMode.h \
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
    corcommandmessagedeconnection.h \
    corcommandmessagepong.h \
    corcommandmessagejoin.h \
    corcommandmessageacceptfile.h \
    corcommandmessageinvitation.h \
    corcommandmessageping.h \
    corcommandmessagesend.h \
    corcommandmessagetransfertfile.h \
    inputcommandmessageacceptfile.h \
    inputcommandmessagetransfertfile.h \
    inputcommandmessageping.h \
    inputcommandmessagejoin.h \
    inputcommandmessagesend.h \
    inputcommandmessagedeconnection.h \
    inputcommandmessageinvitation.h \
    inputcommandmessagepong.h

FORMS    += loginwindow.ui \
    contactwindow.ui \
    addcontactwindow.ui \
    historywindow.ui \
    uploadwindow.ui \
    downloadwindow.ui \
    conversationwindow.ui \
    addcontactchatwindow.ui
