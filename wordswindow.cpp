#include "wordswindow.h"
#include "ui_wordswindow.h"

WordsWindow::WordsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordsWindow)
{
    ui->setupUi(this);

    ui->latin_list->setDragEnabled(false);
    ui->rus_list->setDragEnabled(false);

    connect(ui->latin_list, SIGNAL(currentRowChanged(int)), this, SLOT(select_latin_item()));
    connect(ui->rus_list, SIGNAL(currentRowChanged(int)), this, SLOT(select_rus_item()));
    connect(ui->back_btn, SIGNAL(clicked(bool)), this, SLOT(back()));

    QFile file(":/data/words.txt");
    file.open(QFile::ReadOnly);

    QString file_data = file.readAll();

    QStringList list = file_data.split("\n");
    list.pop_back();//delete ""

    for(int i = 0; i < list.size(); i++)
    {
        if(i % 2 == 0)
        {
            ui->latin_list->addItem(list[i]);
        }
        else if(i % 2 != 0)
        {
            ui->rus_list->addItem(list[i]);
        }
    }

    file.close();
}

void WordsWindow::back()
{
    this->close();
}

void WordsWindow::select_latin_item()
{
    int counter = 0;
    for(int i = 0; i < ui->latin_list->count(); i++)
    {
        if(ui->latin_list->item(i)->isSelected())
            break;
        counter++;
    }

    qDebug() << counter;
}

void WordsWindow::select_rus_item()
{
}

WordsWindow::~WordsWindow()
{
    delete ui;
}
