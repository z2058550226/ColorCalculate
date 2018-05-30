#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QIcon icon(":/icon/izumikonata.jpg");
    w.setWindowIcon(icon);
    w.setIconSize(QSize(20,20));
    w.show();

    return a.exec();
}
