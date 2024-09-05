#ifndef ARCHIVER_H
#define ARCHIVER_H

#include <QFileDialog>
#include <QMainWindow>
#include <QTemporaryDir>
#include <karchive.h>
#include <karchivefile.h>
#include <karchivedirectory.h>
#include <k7zip.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Archiver; }
QT_END_NAMESPACE

class Archiver : public QMainWindow
{
    Q_OBJECT

public:
    Archiver(QWidget *parent = nullptr);
    ~Archiver();

private slots:
    void create();
    void open();
    void addFiles();
    void deleteFiles();
    void extractFiles();

private:
    Ui::Archiver *ui;
    K7Zip* m_openedArchive = nullptr;
    void closeArchive();
    void createOrOpen(bool);
    void updateFileList();
    bool writeFile(QString);
};
#endif // ARCHIVER_H
