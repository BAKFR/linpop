#include "uploadwindow.h"
#include "ui_uploadwindow.h"

#include <QFileInfo>
#include <QDebug>

UploadWindow::UploadWindow(QWidget *parent, const QString &file) :
    QDialog(parent),
    ui(new Ui::UploadWindow)
{
    QFileInfo   info(file);

    ft_upload = new FileTransfertUpload(info);
    ui->setupUi(this);
    ui->label_fileName->setText(info.fileName() + " (" + QString::number(info.size()) + " octets)");
}

UploadWindow::~UploadWindow()
{
    delete ft_upload;
    delete ui;
}

void    UploadWindow::onUploadComplete(int nb_ok, int nb_error, int nb_total)
{
    //TODO: MAJ
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
}

void    UploadWindow::onUploadProgress(int nb_ok, int nb_error, int nb_total)
{
    //TODO MAJ
}

void    UploadWindow::onUploadError(const QString &error)
{
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
    //TODO MAJ
}

void    UploadWindow::onClientError(const QString &error)
{
    //TODO MAJ
}

void UploadWindow::on_buttonBox_rejected()
{
    if (ft_upload != NULL)
        ft_upload->stop();
}
