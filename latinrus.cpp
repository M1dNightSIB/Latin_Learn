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
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    generate_quest();
    connect(ui->ans_1, SIGNAL(clicked(bool)), this, SLOT(check_ans1()));
    connect(ui->ans_2, SIGNAL(clicked(bool)), this, SLOT(check_ans2()));
    connect(ui->ans_3, SIGNAL(clicked(bool)), this, SLOT(check_ans3()));
    connect(ui->ans_4, SIGNAL(clicked(bool)), this, SLOT(check_ans4()));
}

void LatinRus::generate_quest()
{
    pal_btn->setColor(QPalette::Window, Qt::white);
    ui->ans_1->setPalette(*pal_btn);
    ui->ans_2->setPalette(*pal_btn);
    ui->ans_3->setPalette(*pal_btn);
    ui->ans_4->setPalette(*pal_btn);

    lat_index = qrand() % (latin.size() - 1);
    ui->word->setText(latin[lat_index]);

    btn_ans_index = qrand() % 3;

    switch(btn_ans_index)
    {
    case 0:
        ui->ans_1->setText(rus[lat_index]);
        break;
    case 1:
        ui->ans_2->setText(rus[lat_index]);
        break;
    case 2:
        ui->ans_3->setText(rus[lat_index]);
        break;
    case 3:
        ui->ans_4->setText(rus[lat_index]);
        break;
    }

    int trash1, trash2, trash3, trash4;

    while(1)
    {
        trash1 = qrand() %(rus.size() - 1);
        trash2 = qrand() % (rus.size() - 1);
        trash3 = qrand() % (rus.size() - 1);
        trash4 = qrand() % (rus.size() - 1);

        if(trash1 != lat_index && trash2 != lat_index && trash3 != lat_index && trash4 != lat_index)
        {
            if(trash1 != trash2 && trash2 != trash3 && trash1 != trash3 &&
                    trash4 != trash1 && trash4 != trash2 && trash4 != trash3)
                break;
        }
    }

    for(int i = 0; i <= 3; i++)
    {
        if(i == btn_ans_index)
        {
            continue;
        }

        switch (i)
        {
        case 0:
            ui->ans_1->setText(rus[trash1]);
            break;
        case 1:
            ui->ans_2->setText(rus[trash2]);
            break;
        case 2:
            ui->ans_3->setText(rus[trash3]);
            break;
        case 3:
            ui->ans_4->setText(rus[trash4]);
            break;
        default:
            break;
        }
    }

}

void LatinRus::set_right(int ans)
{
    pal_btn->setColor(QPalette::Window, Qt::red);
    switch(ans)
    {
    case 0:
        ui->ans_1->setPalette(*pal_btn);
        break;
    case 1:
        ui->ans_2->setPalette(*pal_btn);
        break;
    case 2:
        ui->ans_3->setPalette(*pal_btn);
        break;
    case 3:
        ui->ans_4->setPalette(*pal_btn);
        break;
    default:
        break;
    }

    pal_btn->setColor(QPalette::Window, Qt::green);
    switch (btn_ans_index)
    {
    case 0:
        ui->ans_1->setPalette(*pal_btn);
        break;
    case 1:
        ui->ans_2->setPalette(*pal_btn);
        break;
    case 2:
        ui->ans_3->setPalette(*pal_btn);
        break;
    case 3:
        ui->ans_4->setPalette(*pal_btn);
        break;
    default:
        break;
    }

    QTimer::singleShot(SINGLE_SHOT_DELAY, this, SLOT(generate_quest()));

}

void LatinRus::check_ans1()
{
    int num = 0;
    set_right(num);
}

void LatinRus::check_ans2()
{
    int num = 1;
    set_right(num);
}

void LatinRus::check_ans3()
{
    int num = 2;
    set_right(num);
}

void LatinRus::check_ans4()
{
    int num = 3;
    set_right(num);
}

void LatinRus::back()
{
    this->close();
}

LatinRus::~LatinRus()
{
    delete ui;
}
