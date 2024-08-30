#include "archiver.h"
#include "ui_archiver.h"

Archiver::Archiver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Archiver)
{
    ui->setupUi(this);
}

Archiver::~Archiver()
{
    delete ui;
}

