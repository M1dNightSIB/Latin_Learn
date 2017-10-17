#include "latinrus.h"
#include "ui_latinrus.h"

LatinRus::LatinRus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LatinRus)
{
    ui->setupUi(this);
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
            latin.push_back(list[i]);
        }
        else if(i % 2 != 0)
        {
            rus.push_back(list[i]);
        }
    }

    file.close();

    pal_btn = new QPalette;
    pal_clk = new QPalette;

}

void LatinRus::back()
{
    this->close();
}

LatinRus::~LatinRus()
{
    delete ui;
}
