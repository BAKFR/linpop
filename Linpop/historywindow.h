#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QMainWindow>

namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit HistoryWindow(QWidget *parent = 0);
    ~HistoryWindow();
    
private:
    Ui::HistoryWindow *ui;
};

#endif // HISTORYWINDOW_H
