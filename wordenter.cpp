#include "wordenter.h"
#include "ui_wordenter.h"

WordEnter::WordEnter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordEnter)
{
    ui->setupUi(this);
    QFile file(":/data/words.txt");
    file.open(QFile::ReadOnly);
    connect(ui->back_btn, SIGNAL(clicked(bool)), this, SLOT(back()));
    QString file_data = file.readAll();

    QStringList list = file_data.split("\n");
    list.pop_back();//delete ""

    for(int i = 0; i < list.size(); i++)
    {
        words.push_back(list[i]);
    }
    set_next_word();
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    connect(ui->accept, SIGNAL(clicked(bool)), this, SLOT(check_result()));
    right.setColor(QPalette::WindowText, Qt::green);
    not_right.setColor(QPalette::WindowText, Qt::red);
    deflt.setColor(QPalette::WindowText, Qt::black);
}

void WordEnter::set_next_word()
{
    ui->result->setText("");
    ui->lineEdit->clear();
    ui->result->setPalette(deflt);
    index = qrand() % (words.size());
    ui->word->setText(words[index]);
}

void WordEnter::back()
{
    this->close();
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

    if(ui->lineEdit->text().toLower() == words[ans_index])
    {
        ui->result->setText("Верно");
        ui->result->setPalette(right);
        QTimer::singleShot(SINGLE_SHOT_DELAY, this, SLOT(set_next_word()));
    }
    else
    {
        ui->result->setText("Не верно");
        ui->result->setPalette(not_right);
        QTimer::singleShot(SINGLE_SHOT_DELAY, this, SLOT(set_next_word()));
    }
}


WordEnter::~WordEnter()
{
    delete ui;
}
