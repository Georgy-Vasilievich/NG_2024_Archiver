#ifndef ARCHIVER_H
#define ARCHIVER_H

#include <QFileDialog>
#include <QMainWindow>
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
};
#endif // ARCHIVER_H
