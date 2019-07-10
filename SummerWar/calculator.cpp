#include "calculator.h"
#include "ui_calculator.h"
bool dot_click = false;
bool sqrt_click = false;
bool pow_click = false;
Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
}

Calculator::~Calculator()
{
    delete ui;
}
void Calculator::digits_numbers()
{
    QPushButton *button = (QPushButton*)sender();
    double all_numbers;
    QString Label;
    all_numbers = (ui->result_show->text()+button->text()).toDouble();
    Label = QString::number(all_numbers);
    ui->result_show->setText(Label, 'g', 15);
}
void Calculator::on_pushButton_point_clicked()
{
    if (!dot_click)
    {
        ui->result_show->setText(ui->result_show->text()+ ".");
        dot_click = true;
        sqrt_click = true;
    }
}

void Calculator::on_pushButton_AC_clicked()
{
    ui->result_show->setText("0");
    dot_click = false;
    sqrt_click = false;
    pow_click = false;
}

void Calculator::on_pushButton_sqrt_clicked()
{
    if (!sqrt_click)
    {
        ui->result_show->setText(ui->result_show->text()+ "√");
        sqrt_click = true;
        dot_click = false;
    }
}
