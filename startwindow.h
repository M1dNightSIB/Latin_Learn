#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "mainwindow.h"
#include <QMainWindow>

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private:
    Ui::StartWindow *ui;

private slots:

};

#endif // STARTWINDOW_H
