#ifndef ARCHIVER_H
#define ARCHIVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Archiver; }
QT_END_NAMESPACE

class Archiver : public QMainWindow
{
    Q_OBJECT

public:
    Archiver(QWidget *parent = nullptr);
    ~Archiver();

private:
    Ui::Archiver *ui;
};
#endif // ARCHIVER_H
