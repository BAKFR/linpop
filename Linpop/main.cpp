#include <QApplication>
#include "loginwindow.h"
#include "networkobject.h"
#include "conversationwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   ContactWindow w;
   w.show();
   NetworkObject no(&w);
    no.initialize(5000);
    ConversationWindow cw;
    cw.show();

    return a.exec();
}
