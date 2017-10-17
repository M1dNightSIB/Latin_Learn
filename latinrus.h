#ifndef LATINRUS_H
#define LATINRUS_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QString>
#include <QPalette>
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
private slots:
    void back();
};

#endif // LATINRUS_H
