#include <QApplication>
#include "loginwindow.h"
#include "networkobject.h"
#include "conversationwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NetworkObject no;
    no.initialize(5000);


    ContactWindow w(&no);
    no.setContactWindow(&w);
    w.show();

    ConversationWindow cw(&w);
    cw.show();

    return a.exec();
}
