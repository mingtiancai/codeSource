#include "mainwindow.h"
#include <QApplication>
#include "logger.h"

int main(int argc, char *argv[])
{
    core::Logger log;
    log.run();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
