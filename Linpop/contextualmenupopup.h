#ifndef CONTEXTUALMENUPOPUP_H
#define CONTEXTUALMENUPOPUP_H

#include <QWidget>

namespace Ui {
class ContextualMenuPopup;
}

class ContextualMenuPopup : public QWidget
{
    Q_OBJECT
    
public:
    explicit ContextualMenuPopup(QWidget *parent = 0);
    ~ContextualMenuPopup();

    void    InitMenu(QPoint globalpos, QWidget *);

public Q_SLOTS:
    void    History();
    void    SetContact();
    void    DeleteContact();

private:
    Ui::ContextualMenuPopup *ui;
    QAction *history;
    QAction *setting;
    QAction *del;
    QPoint  globalpoint;
};

#endif // CONTEXTUALMENUPOPUP_H
