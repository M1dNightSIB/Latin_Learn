#include "trainingwindow.h"
#include "ui_trainingwindow.h"

trainingwindow::trainingwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::trainingwindow)
{
    ui->setupUi(this);
    connect(ui->sprint, SIGNAL(clicked(bool)), this, SLOT(sprint_mode()));
    connect(ui->enter_word, SIGNAL(clicked(bool)), this, SLOT(wEnter_mode()));
    connect(ui->back_btn, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->lat_rus, SIGNAL(clicked(bool)), this, SLOT(latin_rus_mode()));
}

void trainingwindow::sprint_mode()
{
    sprint = new MainWindow;
    sprint->show();
}

void trainingwindow::back()
{
    this->close();
}

void trainingwindow::latin_rus_mode()
{
    lat_rus = new LatinRus;
    lat_rus->show();
}

void trainingwindow::wEnter_mode()
{
    wEnter = new WordEnter;
    wEnter->show();
}

trainingwindow::~trainingwindow()
{
    delete ui;
}
