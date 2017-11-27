#include "rus_lat.h"
#include "ui_rus_lat.h"

Rus_Lat::Rus_Lat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rus_Lat)
{
    ui->setupUi(this);
    connect(ui->go_back, SIGNAL(clicked(bool)), this, SLOT(back()));

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

    connect(ui->ans_9, SIGNAL(clicked(bool)), this, SLOT(check_ans1()));
    connect(ui->ans_10, SIGNAL(clicked(bool)), this, SLOT(check_ans2()));
    connect(ui->ans_11, SIGNAL(clicked(bool)), this, SLOT(check_ans3()));
    connect(ui->ans_12, SIGNAL(clicked(bool)), this, SLOT(check_ans4()));
}


void Rus_Lat::back()
{
    this->close();
}

void Rus_Lat::generate_quest()
{
    pal_btn->setColor(QPalette::Window, Qt::white);
    ui->ans_9->setPalette(*pal_btn);
    ui->ans_10->setPalette(*pal_btn);
    ui->ans_11->setPalette(*pal_btn);
    ui->ans_12->setPalette(*pal_btn);

    lat_index = qrand() % (latin.size() - 1);
    ui->word_3->setText(rus[lat_index]);

    btn_ans_index = qrand() % 4;

    switch(btn_ans_index)
    {
    case 0:
        ui->ans_9->setText(latin[lat_index]);
        break;
    case 1:
        ui->ans_10->setText(latin[lat_index]);
        break;
    case 2:
        ui->ans_11->setText(latin[lat_index]);
        break;
    case 3:
        ui->ans_12->setText(latin[lat_index]);
        break;
    }

    int trash1, trash2, trash3, trash4;

    while(1)
    {
        trash1 = qrand() %(latin.size() - 1);
        trash2 = qrand() % (latin.size() - 1);
        trash3 = qrand() % (latin.size() - 1);
        trash4 = qrand() % (latin.size() - 1);

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
            ui->ans_9->setText(latin[trash1]);
            break;
        case 1:
            ui->ans_10->setText(latin[trash2]);
            break;
        case 2:
            ui->ans_11->setText(latin[trash3]);
            break;
        case 3:
            ui->ans_12->setText(latin[trash4]);
            break;
        default:
            break;
        }
    }
}

void Rus_Lat::set_right(int ans)
{
    pal_btn->setColor(QPalette::Window, Qt::red);
    switch(ans)
    {
    case 0:
        ui->ans_9->setPalette(*pal_btn);
        break;
    case 1:
        ui->ans_10->setPalette(*pal_btn);
        break;
    case 2:
        ui->ans_11->setPalette(*pal_btn);
        break;
    case 3:
        ui->ans_12->setPalette(*pal_btn);
        break;
    default:
        break;
    }

    pal_btn->setColor(QPalette::Window, Qt::green);
    switch (btn_ans_index)
    {
    case 0:
        ui->ans_9->setPalette(*pal_btn);
        break;
    case 1:
        ui->ans_10->setPalette(*pal_btn);
        break;
    case 2:
        ui->ans_11->setPalette(*pal_btn);
        break;
    case 3:
        ui->ans_12->setPalette(*pal_btn);
        break;
    default:
        break;
    }

    QTimer::singleShot(SINGLE_SHOT_DELAY, this, SLOT(generate_quest()));

}

void Rus_Lat::check_ans1()
{
    int num = 0;
    set_right(num);
}

void Rus_Lat::check_ans2()
{
    int num = 1;
    set_right(num);
}

void Rus_Lat::check_ans3()
{
    int num = 2;
    set_right(num);
}

void Rus_Lat::check_ans4()
{
    int num = 3;
    set_right(num);
}

Rus_Lat::~Rus_Lat()
{
    delete ui;
}
