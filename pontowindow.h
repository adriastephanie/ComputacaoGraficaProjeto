#ifndef PONTOWINDOW_H
#define PONTOWINDOW_H

#include <QMainWindow>

namespace Ui {
class PontoWindow;
}

class PontoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PontoWindow(QWidget *parent = nullptr);
    ~PontoWindow();
    void desenhar_ponto(int x, int y);

private slots:
    void on_pushButton_clicked();

private:
    Ui::PontoWindow *ui;
};

#endif // PONTOWINDOW_H
