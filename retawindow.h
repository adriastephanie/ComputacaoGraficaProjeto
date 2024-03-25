#ifndef RETAWINDOW_H
#define RETAWINDOW_H
#include <QLabel>


#include <QMainWindow>

namespace Ui {
class RetaWindow;
}

class RetaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RetaWindow(QWidget *parent = nullptr);
    ~RetaWindow();
    void dda_line(float x1, float y1, float x2, float y2);

private slots:
    void on_pushButton_clicked();

    void on_btnLeft_clicked();

    void on_btnUp_clicked();

    void on_btnDown_clicked();

    void on_btnRight_clicked();

    void on_btnZoomIn_clicked();

    void on_btnZoomOut_clicked();

private:
    Ui::RetaWindow *ui;
};

#endif // RETAWINDOW_H
