#include "trainingwindow.h"
#include "ui_trainingwindow.h"

trainingwindow::trainingwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::trainingwindow)
{
    ui->setupUi(this);
    connect(ui->sprint, SIGNAL(clicked(bool)), this, SLOT(sprint_mode()));
    connect(ui->enter_word, SIGNAL(clicked(bool)), this, SLOT(wEnter_mode()));
}

void trainingwindow::sprint_mode()
{
    sprint = new MainWindow;
    sprint->show();
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
