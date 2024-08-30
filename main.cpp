#include "archiver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Archiver w;
    w.show();
    return a.exec();
}
