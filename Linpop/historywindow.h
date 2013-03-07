#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QMainWindow>
#include "database.h"

namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit HistoryWindow(Database *, QWidget *parent = 0);
    ~HistoryWindow();

    void    getText();
    
private:
    Ui::HistoryWindow *ui;
    Database          *db;
};

#endif // HISTORYWINDOW_H
