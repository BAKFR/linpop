#ifndef UPLOADWINDOW_H
#define UPLOADWINDOW_H

#include <QDialog>

namespace Ui {
class UploadWindow;
}

class UploadWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit UploadWindow(QWidget *parent = 0);
    ~UploadWindow();
    
private:
    Ui::UploadWindow *ui;
};

#endif // UPLOADWINDOW_H
