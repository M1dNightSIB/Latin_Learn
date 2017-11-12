#ifndef RUS_LAT_H
#define RUS_LAT_H

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
class Rus_Lat;
}

class Rus_Lat : public QWidget
{
    Q_OBJECT

public:
    explicit Rus_Lat(QWidget *parent = 0);
    ~Rus_Lat();

private:
    Ui::Rus_Lat *ui;
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

#endif // RUS_LAT_H
