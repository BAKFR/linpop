#include "downloadwindow.h"
#include "ui_downloadwindow.h"
#include "filetransfertdownload.h"

#include "conversationwindow.h"

/*
 * When ft_download is NULL, we wait for user choice.
 * When ft_download is set, file is downloading (or waiting for download)
 */

DownloadWindow::DownloadWindow(ConversationWindow *parent, NetworkObject *net_obj, const QString &filename, int size) :
    QDialog(parent),
    ui(new Ui::DownloadWindow), ft_download(NULL)
{
    ui->setupUi(this);
    ui->label_fileName->setText(filename + " (" + QString::number(size) + " octets)");
    ui->progressBar->setVisible(false);
    ui->label_error->setVisible(false);
    ui->label_complete->setVisible(false);
}

DownloadWindow::~DownloadWindow()
{
    delete ui;
    delete ft_download;
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

void    DownloadWindow::onDownloadProgress(int current_size, int total_size)
{
    ui->label_question->setVisible(false);
    ui->progressBar->setValue(100 * current_size / total_size);
}

void    DownloadWindow::onDownloadComplete()
{
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
    ui->label_complete->setVisible(true);
}

void DownloadWindow::on_buttonBox_accepted()
{
    // user choose to start download !

    ft_download = new FileTransfertDownload();              //TODO: response YES
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Abort);
}

void DownloadWindow::on_buttonBox_rejected()
{
    if (ft_download) {
        //user abort download
        ft_download->stop();
    } else {
        //user refuse download.

                                                            //TODO: response NO
    }
}
