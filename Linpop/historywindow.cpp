#include "historywindow.h"
#include "ui_historywindow.h"

/*HistoryWindow::HistoryWindow(QWidget *parent, Database db, int idUser) :
    QMainWindow(parent),
    _db(db),
    _idUser(idUser),
    ui(new Ui::HistoryWindow)
{
    ui->setupUi(this);
}*/
HistoryWindow::HistoryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HistoryWindow)
{
    ui->setupUi(this);
}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}

void        HistoryWindow::show(int idContact)
{
    idContact = idContact;
    //_db.getConversation(this->idUser, idContact);
}

void        HistoryWindow::show()
{
    //_db.getConversations(this->idUser);
}
