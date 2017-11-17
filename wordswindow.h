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
    int index = -1;
    void push_to_list();
    int select_flag = 0;

private slots:
    void  select_item();
    void back();
    void change_selected_word();
    void delete_selected_word();

};

#endif // WORDSWINDOW_H
