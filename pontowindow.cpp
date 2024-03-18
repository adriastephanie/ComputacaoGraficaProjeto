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
