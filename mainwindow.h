#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "retawindow.h"
#include "pontowindow.h"
#include "poligonoswindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//Essas linhas declaram três slots (métodos) que serão associados aos eventos de clique nos botões na interface gráfica
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    //declara uma variável chamada novaJanela que é um ponteiro para um objeto da classe PontoWindow
    PontoWindow *novaJanela;
    RetaWindow *novaJanela1;
    poligonosWindow *novaJanela2;
};
#endif // MAINWINDOW_H
