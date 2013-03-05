#ifndef FILETRANSFERTUPLOAD_H
#define FILETRANSFERTUPLOAD_H

#include <QFileInfo>

class NetworkObject;
class ConversationWindow;

class FileTransfertUpload
{
public:
    FileTransfertUpload(const QFileInfo &info, NetworkObject *interpretor, ConversationWindow *conv);
    ~FileTransfertUpload();

    void stop();

private:
    QFileInfo   info;
    int         _total;
    int         _completed;
    int         _errors;
};

#endif // FILETRANSFERTUPLOAD_H
