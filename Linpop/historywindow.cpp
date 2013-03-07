#include "historywindow.h"
#include "ui_historywindow.h"


HistoryWindow::HistoryWindow(Database *_db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HistoryWindow)
{
    ui->setupUi(this);
    this->db = _db;
    this->getText();
}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}

void    HistoryWindow::getText()
{
    QList<QString > tmp = this->db->getHistory();

    ui->textHistory->setHtml("");
    for (unsigned int i = 0; i < tmp.size(); i++)
    {
        if (i == 0)
            ui->textHistory->setHtml(tmp[i]);
        ui->textHistory->setHtml(ui->textHistory->toHtml() + "\r\n" + tmp[i]);
    }
}

