#ifndef TRAYICON_H
#define TRAYICON_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QWidget>
#include <QApplication>

#include <QMenu>
#include <QCloseEvent>

#include "contactwindow.h"

class Trayicon : public QMainWindow
{
    Q_OBJECT

public:
    explicit Trayicon(QWidget *parent = 0);
    ~Trayicon();

private:
    void createAction();
    void createTrayicon();
    void setIcon();
    void closeEvent(QCloseEvent *); // Overriding the window's close event

    QSystemTrayIcon *_trayicon;
    QMenu *_trayiconMenu;

    QAction *_open;
    QAction *_close;

    QWidget *_c;
private slots:
    void trayIconClicked(QSystemTrayIcon::ActivationReason);
};

#endif // TRAYICON_H
