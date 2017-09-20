#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&timer, SIGNAL(timeout()), this, SLOT(timer_tick()));
    connect(ui->ans_1, SIGNAL(clicked(bool)), this, SLOT(check_ans1()));
    connect(ui->ans_2, SIGNAL(clicked(bool)), this, SLOT(check_ans2()));
    connect(ui->ans_3, SIGNAL(clicked(bool)), this, SLOT(check_ans3()));
    connect(ui->ans_4, SIGNAL(clicked(bool)), this, SLOT(check_ans4()));

    time = QString("%1:%2").arg(sec_counter, 2).arg(millisec_counter, 2);
    pal_btn = new QPalette;
    pal_clk = new QPalette;

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
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    set_buttons();
}


void MainWindow::set_buttons()
{

    pal_btn->setColor(QPalette::Window, Qt::white);
    ui->ans_1->setPalette(*pal_btn);
    ui->ans_2->setPalette(*pal_btn);
    ui->ans_3->setPalette(*pal_btn);
    ui->ans_4->setPalette(*pal_btn);

    if(check_timer() == 1)
    {
        index = qrand() % (latin.size() - 1);

        ui->quest->setText(latin[index]);

        int trash1, trash2, trash3, trash4;

        while(1)
        {
            trash1 = qrand() %(rus.size() - 1);
            trash2 = qrand() % (rus.size() - 1);
            trash3 = qrand() % (rus.size() - 1);
            trash4 = qrand() % (rus.size() - 1);

            if(trash1 != index && trash2 != index && trash3 != index && trash4 != index)
            {
                if(trash1 != trash2 && trash2 != trash3 && trash1 != trash3 &&
                        trash4 != trash1 && trash4 != trash2 && trash4 != trash3)
                    break;
            }
        }

        btn_ans_index = qrand() % 3;

        switch(btn_ans_index)
        {
        case 0:
            ui->ans_1->setText(rus[index]);
            break;
        case 1:
            ui->ans_2->setText(rus[index]);
            break;
        case 2:
            ui->ans_3->setText(rus[index]);
            break;
        case 3:
            ui->ans_4->setText(rus[index]);
            break;
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


}

void MainWindow::timer_tick()
{
    if(millisec_counter == 0)
    {
        sec_counter--;
        millisec_counter = 100;
    }

    millisec_counter--;

    if(sec_counter <= 10)
    {
        pal_clk->setColor(QPalette::WindowText, Qt::red);
        ui->clock->setPalette(*pal_clk);
    }

    check_timer();

    time = QString("%1:%2").arg(sec_counter, 2).arg(millisec_counter, 2);
    ui->clock->display(time);
}

int MainWindow::check_timer()
{
    if(sec_counter == 0 && millisec_counter == 0)
    {
        timer.stop();
        return 0;
    }
    else
    {
        return 1;
    }
}

void MainWindow::btn_click()
{
    /*pal_btn->setColor(QPalette::Window, Qt::green);
    ui->ans_1->setPalette(*pal_btn);

    pal_btn->setColor(QPalette::Window, Qt::red);
    ui->ans_2->setPalette(*pal_btn);
    ui->quest->setText("МИНУС МАТЬ");
    */
}
void MainWindow::set_right(int ans)
{
    pal_btn->setColor(QPalette::Window, Qt::red);

    switch (ans)
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

    if(ans != btn_ans_index)
    {
        timer.stop();
    }
    else
    {
        timer.start(10);
        set_buttons();
    }
}

void MainWindow::check_ans1()
{
    int num = 0;
    if(check_timer())
        set_right(num);
}

void MainWindow::check_ans2()
{
    int num = 1;
    if(check_timer())
        set_right(num);
}

void MainWindow::check_ans3()
{
    int num = 2;
    if(check_timer())
        set_right(num);
}

void MainWindow::check_ans4()
{
    int num = 3;
    if(check_timer())
        set_right(num);
}




MainWindow::~MainWindow()
{
    delete ui;
}
