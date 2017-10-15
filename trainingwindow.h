#ifndef TRAININGWINDOW_H
#define TRAININGWINDOW_H

#include <QWidget>
#include "mainwindow.h"
#include "wordenter.h"
#include "wordswindow.h"

namespace Ui {
class trainingwindow;
}

class trainingwindow : public QWidget
{
    Q_OBJECT

public:
    explicit trainingwindow(QWidget *parent = 0);
    ~trainingwindow();

private:
    Ui::trainingwindow *ui;
    MainWindow *sprint;
    WordEnter *wEnter;

private slots:
    void sprint_mode();
    void wEnter_mode();
};

#endif // TRAININGWINDOW_H
