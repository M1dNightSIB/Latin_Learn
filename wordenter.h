#ifndef WORDENTER_H
#define WORDENTER_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QFile>

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

private slots:
    void check_result();
};

#endif // WORDENTER_H
