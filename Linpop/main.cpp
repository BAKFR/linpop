#include <QApplication>
#include "loginwindow.h"
#include "networkobject.h"
#include "conversationwindow.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow  lw;

    lw.show();

    return a.exec();
}
