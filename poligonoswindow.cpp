#include "poligonoswindow.h"
#include "ui_poligonoswindow.h"
#include <QLabel>
#include <QTextEdit>
#include <QPainter>
#include <QPolygon>
#include <QPoint>

QImage img_poli(500, 500, QImage::Format_RGB888);

poligonosWindow::poligonosWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::poligonosWindow)
{
    ui->setupUi(this);
}

poligonosWindow::~poligonosWindow()
{
    delete ui;
}
void poligonosWindow::desenhar_poligono(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    // Cria um objeto usando QPainter para desenhar na imagem
    QPainter painter(&img_poli);
    // Define a cor do ponto como vermelho
    painter.setPen(QColor(Qt::green));
    // Cria um objeto usando QPolygon com nome de poligono
    QPolygon poligono;
    poligono << QPoint(x1, y1) << QPoint(x2, y2) << QPoint(x3, y3);

    // Adiciona o ponto opcional de x4, y4, se fornecido em tela
    if (x4 != -1 && y4 != -1) {
        poligono << QPoint(x4, y4);
    }

    // Se o ponto opcional não foi fornecido, verifique se o polígono tem pelo menos 3 pontos
    if ((x4 == -1 || y4 == -1) && poligono.size() < 3) {
        // Se o polígono tiver menos de 3 pontos, não desenhe
        return;
    }

    // Desenha o polígono na imagem
    painter.drawPolygon(poligono);
    ui->label_2->setPixmap(QPixmap::fromImage(img_poli));
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();

    // Verifica se x4 e y4 foram fornecidos em tela
    if (x4 != -1 && y4 != -1) {
        ui->textEdit_5->clear();
        ui->textEdit_6->clear();
        ui->textEdit_7->clear();
        ui->textEdit_8->clear();
    }
    ui->textEdit->setFocus();
}


void poligonosWindow::on_pushButton_clicked()
{
    int x1 = ui->textEdit->toPlainText().toInt();
    int y1 = ui->textEdit_2->toPlainText().toInt();
    int x2 = ui->textEdit_3->toPlainText().toInt();
    int y2 = ui->textEdit_4->toPlainText().toInt();
    int x3 = ui->textEdit_5->toPlainText().toInt();
    int y3 = ui->textEdit_6->toPlainText().toInt();
    int x4 = ui->textEdit_7->toPlainText().toInt();
    int y4 = ui->textEdit_8->toPlainText().toInt();
    desenhar_poligono(x1, y1, x2, y2, x3, y3, x4, y4);
    ui->label_2->setPixmap(QPixmap::fromImage(img_poli));
}


void poligonosWindow::on_btnZoomIn_clicked() {
    QPixmap pixmap = ui->label_2->pixmap(Qt::ReturnByValue);
    pixmap = pixmap.scaled(pixmap.width() * 1.2, pixmap.height() * 1.2);
    ui->label_2->setPixmap(pixmap);

    ui->label_2->setFixedSize(pixmap.size());
}

void poligonosWindow::on_btnZoomOut_clicked() {
    QPixmap pixmap = ui->label_2->pixmap(Qt::ReturnByValue);
    pixmap = pixmap.scaled(pixmap.width() * 0.8, pixmap.height() * 0.8);
    ui->label_2->setPixmap(pixmap);

    ui->label_2->setFixedSize(pixmap.size());
}

void poligonosWindow::on_btnUp_clicked() {
    QPoint currentPosition = ui->label_3->pos();
    ui->label_3->move(currentPosition.x() , currentPosition.y() - 10) ; // Move 10 pixels para a direita

    ui->label_3->update();
}

void poligonosWindow::on_btnDown_clicked() {
    QPoint currentPosition = ui->label_2->pos();
    ui->label_2->move(currentPosition.x() , currentPosition.y() + 10) ; // Move 10 pixels para a direita

    ui->label_2->update();
}

void poligonosWindow::on_btnLeft_clicked() {
    QPoint currentPosition = ui->label_2->pos();
    ui->label_2->move(currentPosition.x() - 10, currentPosition.y()); // Move 10 pixels para a esquerda

    ui->label_2->update();
}

void poligonosWindow::on_btnRight_clicked() {
    QPoint currentPosition = ui->label_2->pos();
    ui->label_2->move(currentPosition.x() + 10, currentPosition.y()); // Move 10 pixels para a direita

    ui->label_2->update();
}


// void poligonosWindow::desenhar_poligono(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
//     // Cria um objeto QPainter para desenhar na imagem
//     QPainter painter(&img_poli);
//     // Define a cor do ponto como vermelho
//     painter.setPen(QColor(Qt::green));
//     // Desenha o ponto na posição (x, y)
//     painter.drawLine(x1, y1, x2, y2);
//     painter.drawLine(x2, y2, x3, y3);
//     painter.drawLine(x3, y3, x4, y4);
//     painter.drawLine(x4, y4, x1, y1);
//     // Atualiza a exibição da imagem na label
//     ui->label_2->setPixmap(QPixmap::fromImage(img_poli));

// }


