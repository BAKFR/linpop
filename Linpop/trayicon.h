#ifndef TRAYICON_H
#define TRAYICON_H

#include <QSystemTrayIcon>
#include <QWidget>
#include <QApplication>

#include <QMenu>
#include <QCloseEvent>

#include "contactwindow.h"

namespace Ui{
    class Trayicon;
}

class Trayicon : public QWidget
{
    Q_OBJECT

private:
    QAction *_open;
    QAction *_close;

    QSystemTrayIcon *_trayicon;
    QMenu           *_trayiconMenu;

public Q_SLOTS:
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
