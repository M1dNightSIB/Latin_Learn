#include "wordenter.h"
#include "ui_wordenter.h"

WordEnter::WordEnter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordEnter)
{
    ui->setupUi(this);

    QFile file(":/data/words.txt");
    file.open(QFile::ReadOnly);

    QString file_data = file.readAll();

    QStringList list = file_data.split("\n");
    list.pop_back();//delete ""

    for(int i = 0; i < list.size(); i++)
    {
        words.push_back(list[i]);
    }

    index = qrand() % (words.size());
    ui->word->setText(words[index]);

    connect(ui->accept, SIGNAL(clicked(bool)), this, SLOT(check_result()));

}

void WordEnter::check_result()
{
    int ans_index = 0;

    if(index % 2 == 0)
    {
        ans_index = index + 1;
    }
    else if(index % 2 != 0)
    {
        ans_index = index - 1;
    }


}

WordEnter::~WordEnter()
{
    delete ui;
}
