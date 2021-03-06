#include "uploadwindow.h"
#include "ui_uploadwindow.h"
#include "conversationwindow.h"

#include "contactwindow.h"

#include <QFileInfo>
#include <QDebug>

UploadWindow::UploadWindow(ConversationWindow *parent, const QString &file) :
    QDialog(parent),
    _conv_win(parent),
    ui(new Ui::UploadWindow)
{
    QFileInfo   info(file);

    ft_upload = new FileTransfertUpload(info, parent->getContactWindow()->getNetworkObject(), parent);
    connect(ft_upload, SIGNAL(clientError(QString)), this, SLOT(onClientError(QString)));
    connect(ft_upload, SIGNAL(complete(int,int,int)), this, SLOT(onUploadComplete(int,int,int)));
    connect(ft_upload, SIGNAL(error(QString)), this, SLOT(onUploadError(QString)));
    connect(ft_upload, SIGNAL(progress(int,int,int)), this, SLOT(onUploadProgress(int, int, int)));

    ui->setupUi(this);
    ui->label_data->setText(QString(" 0 / ") + QString::number(ft_upload->getTotal()));
    ui->label_fileName->setText(info.fileName() + " (" + QString::number(info.size()) + " octets)");
    ui->label_success->setVisible(false);
    ui->label_error->setVisible(false);
}

UploadWindow::~UploadWindow()
{
    delete ft_upload;
    delete ui;
    _conv_win->setUploadWindow(NULL);
}

void    UploadWindow::onUploadComplete(int nb_ok, int nb_error, int nb_total)
{
    onUploadProgress(nb_ok, nb_error, nb_total);
    //ui->info_layout->setVisible(false);
    ui->label_success->setVisible(true);
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
}

void    UploadWindow::onUploadProgress(int nb_ok, int nb_error, int nb_total)
{
    QString text = QString::number(nb_ok) + " / " + QString::number(nb_total);
    if (nb_error) {
        text += " (" + QString::number(nb_error) + " upload fails)";
    }
    ui->label_data->setText(text);
}

void    UploadWindow::onUploadError(const QString &error)
{
    ui->label_2->setVisible(false);
    ui->label_data->setVisible(false);
    ui->label_error->setVisible(true);
    ui->label_error->setText(ui->label_error->text() + "\n" + error);
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
}

void    UploadWindow::onClientError(const QString &)
{
    //TODO display error ?
}

void UploadWindow::onAcceptFile(int port, NetworkClient *client)
{
    if (ft_upload)
        ft_upload->receiveAcceptFile(client, port);
}
