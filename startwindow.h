#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "trainingwindow.h"
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
    trainingwindow *training;
    WordsWindow *word_book;

private slots:
    void trainwindow_mode();
    void word_book_window();
};

#endif // STARTWINDOW_H
