#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //criam novas instâncias das janelas
    novaJanela = new PontoWindow(this);
    novaJanela1 = new RetaWindow(this);
    novaJanela2 = new poligonosWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //método show() é um método fornecido pela classe QWidget
    //para exibir o widget na tela
    novaJanela->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    novaJanela1->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    novaJanela2->show();
}

