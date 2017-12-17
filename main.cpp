#include "startwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleF(":/style/style.qss");
    styleF.open(QFile::ReadOnly | QIODevice::Text);

    QString style = styleF.readAll();

    qApp->setStyleSheet(style);

    StartWindow mainFrame;
    mainFrame.show();
    return a.exec();
}
