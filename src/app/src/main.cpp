#include <string>
#include <iostream>

#include "mainwindow.h"
#include <QApplication>

#include <config.h>
#include "logger.h"

int main(int argc, char *argv[])
{
    core::Config config("./config/config.json");
    if (config.hasValue("loggerLevel"))
        core::Logger::getInstance()->setLoggerLevel(config.getValue("loggerLevel"));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
