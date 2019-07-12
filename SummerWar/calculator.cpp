#include "calculator.h"
#include "ui_calculator.h"
#include <QIOStream>
#include <QString>
#include <QStack>
#include <qmath.h>
using namespace std;
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
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(actions_with_numbers()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(actions_with_numbers()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(actions_with_numbers()));
    connect(ui->pushButton_division, SIGNAL(clicked()), this, SLOT(actions_with_numbers()));
}

Calculator::~Calculator()
{
    delete ui;
}
void Calculator::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();
    QString str=QString(QChar(key));
    if(key==Qt::Key_0)
        ui->pushButton_0->clicked();
    else if(key==Qt::Key_1)
        ui->pushButton_1->clicked();
    else if(key==Qt::Key_2)
        ui->pushButton_2->clicked();
    else if(key==Qt::Key_3)
        ui->pushButton_3->clicked();
    else if(key==Qt::Key_4)
        ui->pushButton_4->clicked();
    else if(key==Qt::Key_5)
        ui->pushButton_6->clicked();
    else if(key==Qt::Key_6)
        ui->pushButton_6->clicked();
    else if(key==Qt::Key_7)
        ui->pushButton_7->clicked();
    else if(key==Qt::Key_8)
        ui->pushButton_8->clicked();
    else if(key==Qt::Key_9)
        ui->pushButton_9->clicked();
    else if(key==Qt::Key_Delete)
        ui->pushButton_AC->clicked();
    else if(key==Qt::Key_Plus)
        ui->pushButton_plus->clicked();
    else if(key==Qt::Key_Minus)
        ui->pushButton_minus->clicked();
    else if(key==Qt::Key_Enter)
        ui->pushButton_equally->clicked();
    else if(key==42)
        ui->pushButton_mult->clicked();
    else if(key==47)
        ui->pushButton_divide->clicked();
    else if(key==46)
        ui->pushButton_point->clicked();
void Calculator::digits_numbers()
{
    QPushButton *button = (QPushButton*)sender();
    QString all_numbers;
    if (!pow_click)
    {
        ui->pow_show->setText(ui->pow_show->text()+ "   ")
        all_numbers = (ui->result_show->text()+button->text()).toQString();
        ui->result_show->setText(all_numbers, 'g', 50);
    }
    else {
        ui->result_show->setText(ui->result_show->text()+ " ");
        all_numbers = (ui->pow_show->text()+button->text()).toQString();
        ui->pow_show->setText(all_numbers, 'g', 50);
    }
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
    ui->pow_show->setText("");
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
        plus_click = true;
        minus_click = true;
        mult_click = true;
        division_click = true;
    }
}
void Calculator::on_pushButton_pow_clicked()
{
    if(!pow_click)
    {
    dot_click = false;
    pow_click = true;
    }
}
void Calculator::actions_with_numbers()
{
    QPushButton *button = (QPushButton*)sender();
    if(!plus_click)
    {
        ui->result_show->setText(ui->result_show->text()+ "+");
        ui->pow_show->setText(ui->pow_show->text()+ "    ");
        plus_click = true;
        minus_click = true;
        mult_click = true;
        division_click = true;
        dot_click = false;
        sqrt_click = false;
        pow_click = false;
    }
    else if (!minus_click)
    {
        ui->result_show->setText(ui->result_show->text()+ "-");
        ui->pow_show->setText(ui->pow_show->text()+ "  ");
        plus_click = true;
        minus_click = true;
        mult_click = true;
        division_click = true;
        dot_click = false;
        sqrt_click = false;
        pow_click = false;
    }
    else if (!mult_click)
    {
        ui->result_show->setText(ui->result_show->text()+ "*");
        ui->pow_show->setText(ui->pow_show->text()+ "    ");
        plus_click = true;
        minus_click = true;
        mult_click = true;
        division_click = true;
        dot_click = false;
        sqrt_click = false;
        pow_click = false;
    }
    else if (!division_click)
    {
        ui->result_show->setText(ui->result_show->text()+ "/");
        ui->pow_show->setText(ui->pow_show->text()+ "  ");
        plus_click = true;
        minus_click = true;
        mult_click = true;
        division_click = true;
        dot_click = false;
        sqrt_click = false;
        pow_click = false;
    }
}

void Sqrt_or_pow(stack<char>& actions, stack<double>& numbers)
{
    char ch = 251;
    double ptr = numbers.top();
    numbers.pop();
    if (actions.top() == '^')
    {
        ptr = pow(numbers.top(),ptr);
        numbers.pop();
        actions.pop();
        numbers.push(ptr);
    }
    if (actions.top() == ch)
    {
        ptr = sqrt(ptr);
        actions.pop();
        numbers.push(ptr);
    }
}
void Mult_or_division(stack<char>& actions, stack<double>& numbers)
{
    double ptr = numbers.top();
    numbers.pop();
    if (actions.top() == '*')
    {
        ptr = ptr*numbers.top();
        numbers.pop();
        actions.pop();
        numbers.push(ptr);
    }
    if ((ptr != 0)&&(actions.top() == '/'))
    {
        ptr = numbers.top() / ptr;
        numbers.pop();
        actions.pop();
        numbers.push(ptr);
    }
    if ((ptr == 0)&&(actions.top() == '/'))
    {
        ui->result_show->setText( "Error");
        exit(0);
    }
}
void Plus_or_minus(stack <char>& actions, stack <double>& numbers)
{
    double ptr_number = numbers.top();
    numbers.pop();
    char ptr_action = actions.top();
    actions.pop();
    if (((actions.top() == '+')&&(ptr_action == '+'))||((actions.top() == '-')&&(ptr_action == '-'))||((actions.top() == '\001')&&(ptr_action == '+')))
    {
        ptr_number = numbers.top() + ptr_number;
        numbers.pop();
        numbers.push(ptr_number);
    }
    if (((actions.top() == '+')&&(ptr_action == '-'))||((actions.top() == '-')&&(ptr_action == '+'))||((actions.top() == '\001')&&(ptr_action == '-')))
    {
        ptr_number = numbers.top() - ptr_number;
        numbers.pop();
        numbers.push(ptr_number);
    }
}
void Calculator::on_pushButton_equally_clicked()
{
    ui->result_show->setText(ui->result_show->text()+ "=");
    char* all_expression = new char[50];
    char* pow_show = new char[50];
    char* num_pow = new char[25];
    char* number = new char[25];
    all_expression = (ui->result_show->text()).toChar;
    pow_show = (ui->pow_show->text()).toChar;
    QStack <double> numbers;
    QStack <char> actions;
    char ch = 251;
    actions.push(1);
    int i = 0;
    while (all_expression[i] != '=')
    {
        int k = 0;
        int j = i;
        while ((all_expression[j] != '+')&&(all_expression[j] != '*')&&(all_expression[j] != '-')&&(all_expression[j] != '/')&&(all_expression[i] != '=')&&(pow_show[j] == ' ')&&(all_expression[j] != ch))
        {
            number[k] = all_expression[j];
            j++;
            i = j;
            k++;
        }
        double a = atof(number);
        numbers.push(a);
        if (pow_show[j] != ' ')
                {
                    actions.push('^');
                    j = i;
                    k=0;
                    while (pow_show[j] != ' ')
                    {
                        num_pow[k] = pow_show[j];
                        k++;
                        j++;
                        i=j;
                    }
                    a = atof(num_pow);
                    numbers.push(a);
                }
        if (actions.top()== '^') Sqrt_or_pow(actions, numbers);
        if ((actions.top()== ch)&&(all_expression[i] != '^')) Sqrt_or_pow(actions, numbers);
        if (((actions.top()== '*')||(actions.top()== '/'))&&((all_expression[i] != '^')||(all_expression[i] != ch)))
        {
            Mult_or_division(actions, numbers);
        }
        if (all_expression[i] == '=') break;
        actions.push(all_expression[i]);
        for (int k=0; k<=sizeof number; k++)
        {
            number[k]=' ';
        }
        i++;
    }
    while (numbers.top() == 0)
    {
        numbers.pop();
    }
    while (actions.top() == '\000')
    {
        actions.pop();
    }
    while (actions.top() != '\001')
    {
        Plus_or_minus(actions, numbers);
    }
    QString m = numbers.top();
    ui->result_show->setText(m, 'g', 50);
    ui->pow_show->setText("");
    while (!(numbers.empty())&&!(actions.empty()))
    {
        actions.pop();
        numbers.pop();
    }
    delete [] number;
    delete [] all_expression;
    delete [] pow_show;
    delete [] num_pow;
}


