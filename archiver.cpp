#include "archiver.h"
#include "ui_archiver.h"

Archiver::Archiver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Archiver)
{
    ui->setupUi(this);
    connect(ui->b_create, &QPushButton::clicked, this, &Archiver::create);
    connect(ui->b_open, &QPushButton::clicked, this, &Archiver::open);
    connect(ui->b_add, &QPushButton::clicked, this, &Archiver::addFiles);
    connect(ui->b_delete, &QPushButton::clicked, this, &Archiver::deleteFiles);
    connect(ui->b_extract, &QPushButton::clicked, this, &Archiver::extractFiles);
}

Archiver::~Archiver()
{
    delete ui;
    closeArchive();
}

void Archiver::create()
{
    createOrOpen(true);
}

void Archiver::open()
{
    createOrOpen(false);
}

void Archiver::addFiles()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select file", "", "All files (*)");

    if (fileName.isEmpty())
        return;

    QFile file;

    file.setFileName(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QFileInfo fileInfo(fileName);
        QString baseName(fileInfo.completeBaseName());
        m_openedArchive->writeFile(baseName, file.readAll());
        file.close();
        updateFileList();
    }
}

void Archiver::deleteFiles()
{

}

void Archiver::extractFiles()
{

}

void Archiver::closeArchive()
{
    if (m_openedArchive != NULL) {
        m_openedArchive->close();
        delete m_openedArchive;
        m_openedArchive = nullptr;
    }
}

void Archiver::createOrOpen(bool create)
{
    QString fileName;
    if (create)
        fileName = QFileDialog::getSaveFileName(this, "Select file", "", "7-Zip archives (*.7z)");
    else
        fileName = QFileDialog::getOpenFileName(this, "Select file", "", "7-Zip archives (*.7z)");

    if (fileName.isEmpty())
        return;

    closeArchive();

    m_openedArchive = new K7Zip(fileName);

    m_openedArchive->open(QIODevice::ReadWrite);

    updateFileList();

    ui->b_add->setEnabled(true);
    ui->b_delete->setEnabled(true);
    ui->b_extract->setEnabled(true);
}

void Archiver::updateFileList()
{
    ui->l_files->clear();
    const KArchiveDirectory *root = m_openedArchive->directory();

    for (QString entry : root->entries())
        ui->l_files->addItem(entry);
}

