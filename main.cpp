#include "startwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartWindow mainFrame;
    mainFrame.show();


    return a.exec();
}
