#ifndef TRAYICON_H
#define TRAYICON_H

#include <QSystemTrayIcon>
#include <QWidget>

#include <QMenu>
#include <QCloseEvent>

#include "contactwindow.h"

class Trayicon : public QMainWindow
{
private:
    QAction *_open;
    QAction *_close;

    QSystemTrayIcon *_trayicon;
    QMenu           *_trayiconMenu;

private slots:
    void    trayIconClicked(QSystemTrayIcon::ActivationReason);

public:
    Trayicon(QWidget *link);
    ~Trayicon();

public:
    void    createTrayicon();
    void    createAction();
    void    setIcon();
    void    closeEvent(QCloseEvent *);
};

#endif // TRAYICON_H
