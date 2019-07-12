#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
private slots:
    void digits_numbers();
    void on_pushButton_point_clicked();
    void on_pushButton_AC_clicked();
    void on_pushButton_sqrt_clicked();
    void actions_with_numbers();
    void on_pushButton_equally_clicked();
    void on_pushButton_pow_clicked();
    void on_pushButton_undo_clicked();
    void on_pushButton_do_clicked();
};

#endif // CALCULATOR_H
