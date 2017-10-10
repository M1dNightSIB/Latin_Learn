#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    connect(ui->train_btn, SIGNAL(clicked(bool)), this, SLOT(train_mode()));
    connect(ui->word_btn, SIGNAL(clicked(bool)), this, SLOT(words_mode()));
}

void StartWindow::train_mode()
{
    train = new MainWindow;
    train->show();
}

void StartWindow::words_mode()
{
    words = new WordsWindow;
    words->show();
}

StartWindow::~StartWindow()
{
    delete ui;
}
