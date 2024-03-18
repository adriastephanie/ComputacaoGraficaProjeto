#include "retawindow.h"
#include "ui_retawindow.h"
#include <QLabel>
#include <QTextEdit>
#include <QPainter>

QImage img(500, 500, QImage::Format_RGB888);

RetaWindow::RetaWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RetaWindow)
{
    ui->setupUi(this);
}

RetaWindow::~RetaWindow()
{
    delete ui;
}


void RetaWindow::dda_line(float x1, float y1, float x2, float y2) {
    // biblioteca que vai criar o objeto e desennhar
    QPainter painter(&img);
    // só define a cor da caneta do QPainter como verde
    painter.setPen(QColor(Qt::green));
    // vai calcular as diferenças em x e y entre os pontos inicial e final
    float dx = x2 - x1;
    float dy = y2 - y1;
    // vai definir o número de pixels para desenhar a linha
    float steps = abs(dx);

    if (abs(dy) > abs(dx)) {
        steps = abs(dy);
    }

    float xinc = dx / steps;
    float yinc = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i < steps; i++) {
        // Desenhar o pixel na posição (x, y)
        painter.drawPoint(x, y);

        x = x + xinc;
        y = y + yinc;
    }

    // Atualizar a exibição da imagem na label
    ui->label_2->setPixmap(QPixmap::fromImage(img));
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->textEdit->setFocus();
}

void RetaWindow::on_pushButton_clicked()
{
    //interface do usuário - ui
    //textEdit é o carinha do input da mainwindow.ui
    // toPlainText() retorna o texto da edição de texto como texto simples.
    //.toInt() método converte a string retornada pelo toPlainText()
    int x1 = ui->textEdit->toPlainText().toInt();
    int y1 = ui->textEdit_2->toPlainText().toInt();
    int x2 = ui->textEdit_3->toPlainText().toInt();
    int y2 = ui->textEdit_4->toPlainText().toInt();
    dda_line(x1, y1, x2, y2);
    ui->label_2->setPixmap(QPixmap::fromImage(img));
}

