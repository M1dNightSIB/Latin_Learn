#include "wordswindow.h"
#include "ui_wordswindow.h"

WordsWindow::WordsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordsWindow)
{
    ui->setupUi(this);

    ui->latin_list->setDragEnabled(false);


    connect(ui->back_btn, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->latin_list, SIGNAL(clicked(QModelIndex)), this, SLOT(select_item()));
    //connect(ui->save_btn, SIGNAL(clicked(bool)), this, SLOT(change_selected_word()));
   // connect(ui->del_btn, SIGNAL(clicked(bool)), this, SLOT(delete_selected_word()));

    QFile file(":/data/words.txt");
    file.open(QFile::ReadOnly);

    QString file_data = file.readAll();

    QStringList list = file_data.split("\n");
    list.pop_back();//delete ""

    for(int i = 0; i < list.size(); i++)
    {
        if(i % 2 == 0)
        {
            latin.push_back(list[i]);
        }
        else if(i % 2 != 0)
        {
            rus.push_back(list[i]);
        }
    }
    file.close();

    push_to_list();
}
/*
void WordsWindow::select_item()
{
    if(select_flag == 0 || ui->latin_list->currentRow() != index)
    {
        select_flag = 1;
        index = ui->latin_list->currentRow();
        ui->latin_edit->setText(latin[index]);
        ui->rus_edit->setText(rus[index]);
    }
    else if(select_flag == 1)
    {
        select_flag = 0;
        ui->latin_list->item(index)->setSelected(false);
        ui->latin_edit->clear();
        ui->rus_edit->clear();
    }
}
*/
void WordsWindow::push_to_list()
{
    ui->latin_list->clear();
    for(int i = 0; i < latin.size(); i++)
    {
        QString buf = latin[i] + " - " + rus[i];
        ui->latin_list->addItem(buf);
    }
}
/*
void WordsWindow::delete_selected_word()
{
    latin.erase(latin.begin() + index);
    rus.erase(rus.begin() + index);

    ui->latin_edit->clear();
    ui->rus_edit->clear();

    push_to_list();
    select_flag = 0;

    write_to_file();
}

void WordsWindow::change_selected_word()
{
    QString latin_from_vec, rus_from_vec;
    latin_from_vec = ui->latin_edit->text();
    rus_from_vec = ui->rus_edit->text();

    latin[index] = latin_from_vec;
    rus[index] = rus_from_vec;

    ui->latin_edit->clear();
    ui->rus_edit->clear();

    push_to_list();
    select_flag = 0;

    write_to_file();
}
*/
/*
void WordsWindow::write_to_file() //запись в файл
{
    QFile file(":/data/words.txt");
    file.open(QFile::WriteOnly | QIODevice::Text);
    QTextStream stream(&file);
    for(int i = 0; i < latin.size(); i++)
    {
        stream << latin[i] << '\n' << rus[i] << '\n';
    }
    file.close();
}
*/
void WordsWindow::back()
{
    this->close();
}


WordsWindow::~WordsWindow()
{
    delete ui;
}
