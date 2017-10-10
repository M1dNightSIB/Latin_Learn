#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "mainwindow.h"
#include "wordswindow.h"
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
    MainWindow *train;
    WordsWindow *words;

private slots:
    void train_mode();
    void words_mode();
};

#endif // STARTWINDOW_H
