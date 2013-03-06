#include "trayicon.h"

Trayicon::Trayicon(QWidget *link):
    QMainWindow(link)
{
    this->createAction();
    this->createTrayicon();
    this->setIcon();
    this->_trayicon->show();
}

Trayicon::~Trayicon()
{
}

void    Trayicon::createAction()
{
    this->_open = new QAction(tr("&Open"), this);
    connect(this->_open, SIGNAL(triggered()), this, SLOT(show()));

    this->_open = new QAction(tr("&Quit"), this);
    connect(this->_close, SIGNAL(triggered()), this, SLOT(show()));
}

void    Trayicon::createTrayicon()
{
    this->_trayiconMenu = new QMenu(this);

    this->_trayiconMenu->addAction(this->_open);
    this->_trayiconMenu->addSeparator();
    this->_trayiconMenu->addAction(this->_close);

    this->_trayicon = new QSystemTrayIcon(this);
    this->_trayicon->setContextMenu(this->_trayiconMenu);

    connect(
                this->_trayicon,
                SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                this,
                SLOT(this->trayIconClicked(QSystemTrayIcon::ActivationReason))
                );
}

void    Trayicon::setIcon()
{
    //this->_trayicon->setIcon("./iconTest.png");
}

void    Trayicon::trayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger)
        this->show();
}

void    Trayicon::closeEvent(QCloseEvent *event)
{
    if (this->_trayicon->isVisible())
    {
        //this->_trayicon->showMessage(tr("toto!"));
        //this->_trayicon->showMessage(tr("C'est encore la!"));
        this->hide();
        event->ignore();
    }
}
