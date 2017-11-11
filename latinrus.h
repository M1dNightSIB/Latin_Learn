#ifndef LATINRUS_H
#define LATINRUS_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QTime>
#include <QString>
#include <QTimer>
#include <QPalette>

#define SINGLE_SHOT_DELAY 1200

namespace Ui {
class LatinRus;
}

class LatinRus : public QWidget
{
    Q_OBJECT

public:
    explicit LatinRus(QWidget *parent = 0);
    ~LatinRus();

private:
    Ui::LatinRus *ui;
    QVector <QString> latin, rus;
    QPalette *pal_btn, *pal_clk;
    int lat_index = 0;
    int btn_ans_index = 0;
    void set_right(int ans);
private slots:
    void back();
    void generate_quest();
    void check_ans1();
    void check_ans2();
    void check_ans3();
    void check_ans4();


};

#endif // LATINRUS_H
