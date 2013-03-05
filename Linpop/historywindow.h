#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QMainWindow>
//#include "database.h"

namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QMainWindow
{
    Q_OBJECT
    //Database    _db;
    int         _iduser;
    
public:
    explicit HistoryWindow(QWidget *parent = 0);
    //explicit HistoryWindow(QWidget *parent = 0, Database db, int idUser);
    ~HistoryWindow();
    void        show(int idContact);
    void        show();
    
private:
    Ui::HistoryWindow *ui;
};

#endif // HISTORYWINDOW_H
