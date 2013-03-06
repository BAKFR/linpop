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
    QString     dbName = "/Users/Siegfried/Projects/PTraining2/newLinpop/linpop/bdd_linpop.db";

    Database    db = Database(dbName);
    User        user1 = User("Philippe", "PWNEDBYNOOB");
    Contact     contact = Contact();
    Member      member = Member();

    contact.setInfo(1, 1, "Maman", "192.168.1.1");
    member.setInfo(4, 1, "Pauline", "192.168.55.32", 3);

    db.openDatabase();
//    db.addUser(user1);
//    db.addContact(contact);
//    db.addMember(member);

    QString     userName = "KAKA";
    QString     password = "PWNEDBYNOOB";

    User        *testUser = db.getUser(userName, password);
    if (testUser != NULL)
    {
        std::cout << testUser->getUserName().toStdString() << std::endl;
        std::cout << testUser->getPassword().toStdString() << std::endl;
        std::cout << testUser->getIdUser() << std::endl;
    }
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
