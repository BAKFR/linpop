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
    ui->label_success->setVisible(false);
    ui->label_error->setVisible(false);
}

UploadWindow::~UploadWindow()
{
    delete ft_upload;
    delete ui;
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
    ui->info_layout->widget()->setVisible(false);
    ui->label_error->setVisible(true);
    ui->label_error->setText(ui->label_error->text() + "\n" + error);
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
}

void    UploadWindow::onClientError(const QString &)
{
    //TODO display error ?
}

void UploadWindow::on_buttonBox_rejected()
{
    if (ft_upload != NULL)
        ft_upload->stop();
}
