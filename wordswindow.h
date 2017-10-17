#ifndef WORDSWINDOW_H
#define WORDSWINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QFile>
#include <QLineEdit>
#include <QVector>
#include <QString>
#include <QStringList>
#include <QDebug>

namespace Ui {
class WordsWindow;
}

class WordsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WordsWindow(QWidget *parent = 0);
    ~WordsWindow();

private:
    Ui::WordsWindow *ui;
    QVector<QString> latin, rus;

private slots:
    void back();
    void select_latin_item();
    void select_rus_item();

};

#endif // WORDSWINDOW_H
