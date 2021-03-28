#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ventana_juego(this, nullptr)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_juego_button_clicked()
{
    ventana_juego.show();
    ventana_juego.start();
    this->setDisabled(true);
    this->hide();
}


void MainWindow::on_exit_button_clicked()
{
    this->close();
}

