#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    connect(ui->train_btn, SIGNAL(clicked(bool)), this, SLOT(trainwindow_mode()));
    connect(ui->word_btn, SIGNAL(clicked(bool)), this, SLOT(word_book_window()));
}

void StartWindow::trainwindow_mode()
{
    training = new trainingwindow;
    training->show();
}

void StartWindow::word_book_window()
{
    word_book = new WordsWindow;
    word_book->show();
}

StartWindow::~StartWindow()
{
    delete ui;
}
