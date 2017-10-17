#ifndef WORDENTER_H
#define WORDENTER_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QFile>
#include <QPalette>
#include <QTime>
#include <QTimer>
#include <QDebug>


namespace Ui {
class WordEnter;
}

class WordEnter : public QWidget
{
    Q_OBJECT

public:
    explicit WordEnter(QWidget *parent = 0);
    ~WordEnter();

private:
    Ui::WordEnter *ui;
    int index;
    QVector <QString> words;
    QPalette right, not_right, deflt;

private slots:
    void back();
    void check_result();
    void set_next_word();
};

#endif // WORDENTER_H
