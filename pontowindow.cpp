#include "pontowindow.h"
#include "ui_pontowindow.h"
#include <QLabel>
#include <QTextEdit>
#include <QPainter>

//cria um objeto QImage chamado img_ponto
//especifica largura e a altura da imagem
QImage img_ponto(500, 500, QImage::Format_RGB888);

PontoWindow::PontoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PontoWindow)
{
    ui->setupUi(this);
}

PontoWindow::~PontoWindow()
{
    delete ui;
}

void PontoWindow::desenhar_ponto(int x, int y) {
    // Redimensiona a imagem
     QPainter painter(&img_ponto);

    // Define a cor do ponto como verde
    painter.setPen(QColor(Qt::green));

    // Desenha o ponto na posição (x, y)
    painter.drawPoint(x, y);

    // Atualiza a exibição da imagem na label
    ui->label_3->setPixmap(QPixmap::fromImage(img_ponto));
    // Limpa os campos de texto
    ui->textEdit->clear();
    ui->textEdit_2->clear();

    // Foca no textEdit
    ui->textEdit->setFocus();
}


void PontoWindow::on_pushButton_clicked()
{
    int x = ui->textEdit->toPlainText().toInt();
    int y = ui->textEdit_2->toPlainText().toInt();
    desenhar_ponto(x, y);
    ui->label_3->setPixmap(QPixmap::fromImage(img_ponto));
}

void PontoWindow::on_btnZoomIn_clicked() {
    QPixmap pixmap = ui->label_3->pixmap(Qt::ReturnByValue);
    pixmap = pixmap.scaled(pixmap.width() * 1.2, pixmap.height() * 1.2);
    ui->label_3->setPixmap(pixmap);

    ui->label_3->setFixedSize(pixmap.size());
}

void PontoWindow::on_btnZoomOut_clicked() {
    QPixmap pixmap = ui->label_3->pixmap(Qt::ReturnByValue);
    pixmap = pixmap.scaled(pixmap.width() * 0.8, pixmap.height() * 0.8);
    ui->label_3->setPixmap(pixmap);

    ui->label_3->setFixedSize(pixmap.size());
}

void PontoWindow::on_btnUp_clicked() {
    QPoint currentPosition = ui->label_3->pos();
    ui->label_3->move(currentPosition.x() , currentPosition.y() - 10) ; // Move 10 pixels para a direita

    ui->label_3->update();
}

void PontoWindow::on_btnDown_clicked() {
    QPoint currentPosition = ui->label_3->pos();
    ui->label_3->move(currentPosition.x() , currentPosition.y() + 10) ; // Move 10 pixels para a direita

    ui->label_3->update();
}

void PontoWindow::on_btnLeft_clicked() {
    QPoint currentPosition = ui->label_3->pos();
    ui->label_3->move(currentPosition.x() - 10, currentPosition.y()); // Move 10 pixels para a esquerda

    ui->label_3->update();
}

void PontoWindow::on_btnRight_clicked() {
    QPoint currentPosition = ui->label_3->pos();
    ui->label_3->move(currentPosition.x() + 10, currentPosition.y()); // Move 10 pixels para a direita

    ui->label_3->update();
}


