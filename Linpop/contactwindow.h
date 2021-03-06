#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QModelIndex>

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QCloseEvent>

namespace Ui {
class ContactWindow;
}

class ConversationWindow;
class NetworkObject;
class NetworkClient;
class Database;

class ContactWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    ContactWindow(NetworkObject *obj);
    ConversationWindow *createEmptyConversationWindow();
    ~ContactWindow();

    Database    *getDatabase();
    void removeConv(ConversationWindow *w);
    NetworkObject* getNetworkObject();
    ConversationWindow *getConvById(const QString &id);

    int hasConvByClient(NetworkClient *client);
    void clientQuit(NetworkClient *client);

    void setLoginWindow(QWidget *);
    void addContact(QString name, QString ip);
    void deleteContact();
    void setContact(QString name, QString ip);
    QString TestPing(QString ip);
    QString getName(QString text = "");
    QString getIp(QString text = "");
    QString generateID();
    NetworkClient *createAndConnectNetworkClientOnIP(QString ip);
    QString getLogin();
    QString getPassword();
    void    setLogin(QString);
    void    initContactWindow(Database *,QString, QString);
private slots:

    void on_actionDisconnect_triggered();

    void on_actionExit_triggered();

    void on_actionAdd_Contact_triggered();

    void on_actionSettings_triggered();

    void on_actionHistory_triggered();

    void on_listContact_customContextMenuRequested(const QPoint &pos);
    
    void on_pushButton_clicked();

    void on_listContact_doubleClicked();

    void on_actionAbout_triggered();

    void on_boutonAddContact_clicked();

private:
    Ui::ContactWindow *ui;
    QWidget           *lw;
    NetworkObject       *_network_object;
    QList<ConversationWindow *> listConversationWindow;
    QString            login;
    QString            pwd;
    Database  *db;


private:
    void createActions();
    void createTrayIcon();
    void setIcon();
    void closeEvent(QCloseEvent *); // Overriding the window's close event


    QSystemTrayIcon *_trayIcon;
    QMenu *_trayIconMenu;

    QAction *_open;
    QAction *_close;

private slots:
    void trayIconClicked(QSystemTrayIcon::ActivationReason);
};

#endif // CONTACTWINDOW_H
