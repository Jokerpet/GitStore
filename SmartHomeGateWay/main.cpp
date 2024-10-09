#include "localcontrolpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LocalControlPage w;
    w.show();

    return a.exec();
}
