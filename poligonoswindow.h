#ifndef POLIGONOSWINDOW_H
#define POLIGONOSWINDOW_H

#include <QMainWindow>

namespace Ui {
class poligonosWindow;
}

class poligonosWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit poligonosWindow(QWidget *parent = nullptr);
    ~poligonosWindow();
    void desenhar_poligono(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

private slots:
    void on_pushButton_clicked();

private:
    Ui::poligonosWindow *ui;
};

#endif // POLIGONOSWINDOW_H
