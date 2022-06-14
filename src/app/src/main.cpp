#include "mainwindow.h"
#include <QApplication>
#include "logger.h"

int main(int argc, char *argv[])
{
    loggerPrint();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
