#include "calculator.h"
#include "ui_calculator.h"
bool dot_click = false;
bool sqrt_click = false;
bool pow_click = false;
bool plus_click = false;
bool minus_click = false;
bool division_click = false;
bool mult_click = false;
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
    QString all_numbers;
    all_numbers = (ui->result_show->text()+button->text()).toQString();
    ui->result_show->setText(all_numbers, 'g', 50);
    plus_click = false;
    minus_click = false;
    division_click = false;
    mult_click = false;
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
void Calculator::actions_with_numbers()
{
    QPushButton *button = (QPushButton*)sender();
    if(!plus_click)
    {
        ui->result_show->setText(ui->result_show->text()+ "+");
        plus_click = true;
        minus_click = true;
        mult_click = true;
        division_click = true;
        dot_click = false;
        sqrt_click = false;
    }
    else if (!minus_click)
    {
        ui->result_show->setText(ui->result_show->text()+ "-");
        plus_click = true;
        minus_click = true;
        mult_click = true;
        division_click = true;
        dot_click = false;
        sqrt_click = false;
    }
    else if (!mult_click)
    {
        ui->result_show->setText(ui->result_show->text()+ "*");
        plus_click = true;
        minus_click = true;
        mult_click = true;
        division_click = true;
        dot_click = false;
        sqrt_click = false;
    }
    else if (!division_click)
    {
        ui->result_show->setText(ui->result_show->text()+ "/");
        plus_click = true;
        minus_click = true;
        mult_click = true;
        division_click = true;
        dot_click = false;
        sqrt_click = false;
    }
}
