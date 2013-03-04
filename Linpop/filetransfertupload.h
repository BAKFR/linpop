#ifndef FILETRANSFERTUPLOAD_H
#define FILETRANSFERTUPLOAD_H

#include <QFileInfo>

class FileTransfertUpload
{
public:
    FileTransfertUpload(const QFileInfo &info);
    ~FileTransfertUpload();

    void stop();

private:
    QFileInfo   info;
};

#endif // FILETRANSFERTUPLOAD_H
