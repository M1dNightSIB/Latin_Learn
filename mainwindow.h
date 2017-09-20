#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QVector>
#include <QFile>

#define DELAY 10

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString time;
    QTimer timer;
    QPalette *pal_btn, *pal_clk;
    double sec_counter = 30,
        millisec_counter = 0;

    QVector <QString> latin, rus;
    int check_timer();
    int index;
    int btn_ans_index;
    void set_buttons();
    void set_right(int ans);


private slots:
    void timer_tick();
    void btn_click();
    void check_ans1();
    void check_ans2();
    void check_ans3();
    void check_ans4();
};

#endif // MAINWINDOW_H
