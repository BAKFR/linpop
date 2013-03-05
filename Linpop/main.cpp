#include <QApplication>
#include "loginwindow.h"
#include "networkobject.h"
#include "conversationwindow.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow  lw;

    // TEST DATABASE ON
    Database    db = Database("./../bdd_linpop_test.bdd", "Mirozh", "qwerty", 1);
    User        user1 = User(1, "Mirozh", "qwerty");

    db.openDatabase();
    db.addUser(user1);
    db.closeDatabase();
    std::cout << std::flush;
    // TEST DATABASE OFF

    lw.show();
   //ContactWindow w;
  // w.show();
   //NetworkObject no(&w);
    //no.initialize(5000);

    //ContactWindow w(&no);
    //ConversationWindow conv;
    //no.setContactWindow(&w);
    //w.show();
    //conv.show();
   // NetworkObject no;
   // no.initialize(5000);


   // ContactWindow w(&no);
    //no.setContactWindow(&w);
   // w.show();

   // ConversationWindow cw(&w);
   // cw.show();

    return a.exec();
}
