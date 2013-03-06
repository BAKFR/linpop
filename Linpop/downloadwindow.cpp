#include "downloadwindow.h"
#include "ui_downloadwindow.h"
#include "filetransfertdownload.h"

#include "conversationwindow.h"
#include <QFileDialog>

/*
 * When ft_download is NULL, we wait for user choice.
 * When ft_download is set, file is downloading (or waiting for download)
 */

DownloadWindow::DownloadWindow(ConversationWindow *parent, NetworkObject *net_obj, NetworkClient *target, const QString &filename, qulonglong size) :
    QDialog(parent),
    ui(new Ui::DownloadWindow), ft_download(NULL), _conv_id(parent->getIDConv()), _net_obj(net_obj), _size(size)
{
    setAttribute(Qt::WA_DeleteOnClose);

    _target = target;

    ui->setupUi(this);
    ui->label_fileName->setText(filename + " (" + QString::number(size) + " octets)");
    ui->progressBar->setVisible(false);
    ui->label_error->setVisible(false);
    ui->label_complete->setVisible(false);
}

DownloadWindow::~DownloadWindow()
{
    delete ui;
    ft_download->deleteLater();
}

void    DownloadWindow::onDownloadStart()
{
    ui->progressBar->setVisible(true);
    ui->label_question->setVisible(false);
}

void    DownloadWindow::onDownloadError(const QString &msg)
{
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
    ui->progressBar->setVisible(false);
    ui->label_question->setVisible(false);
    ui->label_error->setVisible(true);
    ui->label_error->setText(ui->label_error->text() + "\n" + msg);
}

void    DownloadWindow::onDownloadProgress(qulonglong current_size, qulonglong total_size)
{
    ui->label_question->setVisible(false);
    int v = 100 * current_size / total_size;
    ui->progressBar->setValue(v > 100 ? 100 : v);
}

void    DownloadWindow::onDownloadComplete()
{
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
    ui->label_complete->setVisible(true);
}

void DownloadWindow::on_buttonBox_accepted()
{
    // user choose to start download !

    QFileDialog *file_window = new QFileDialog(this, "Select a file to upload");
    file_window->setAcceptMode(QFileDialog::AcceptSave);
    if (file_window->exec() == 1) {
        //A file is choosen.

        ft_download = new FileTransfertDownload(_net_obj, _conv_id, _target, file_window->selectedFiles().at(0), _size);
        connect(ft_download, SIGNAL(start()), this, SLOT(onDownloadStart()));
        connect(ft_download, SIGNAL(complete()), this, SLOT(onDownloadComplete()));
        connect(ft_download, SIGNAL(error(QString)), this, SLOT(onDownloadError(QString)));
        connect(ft_download, SIGNAL(progress(qulonglong, qulonglong)), this, SLOT(onDownloadProgress(qulonglong, qulonglong)));

        ui->label_question->setVisible(false);
        ui->buttonBox->setStandardButtons(QDialogButtonBox::Abort);
    }
    delete file_window;
}

void DownloadWindow::on_buttonBox_rejected()
{
    if (!ft_download) {
        //user refuse download.
        FileTransfertDownload::reject(_net_obj, _conv_id, _target);
    }

    //in all case, we quit.
    deleteLater();
}
