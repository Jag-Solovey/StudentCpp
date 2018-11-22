#include <iostream>
#include <cmath>
using namespace std;
//Функция логарифма
double log (double x, double d)
{
    return log(d)/log(x);
}
//Защита от дурака. Что в нее входит: если происходит ошибка ввода,
//то значения игнорируются и обнуляются до тех пор, пока не будет введено корректное значение
float checking (float x)
{
    cin >> x;
    while(cin.fail())
    {
        cout << "Nice joke, but I do not work like that. Try again!\n ";
        cin.clear();
        cin.ignore(6666,'\n');
        cin >> x;
    }
    return x;
}
//Проверка того, что выбран существующий вариант
int checking (int d, float x)
{
    if (d < 1 || d > 2)
    {
        cout << "\nThere is no such option! :D";
    }
    else
    {
        cout << "\nResult: " << x;
    }
}
int checking (int d)
{
    cin >> d;
    while(d < 1 || d > 7)
    {
        cout << "Nice joke, but I do not work like that. Try again!\n ";
        cin.clear();
        cin.ignore(6666,'\n');
        cin >> d;
    }
    return d;
}
int main()
{
    int d, f = 1;
    float num1, num2, x;
    //Цикл для выполнения повторного использования калькулятора
    while (f == 1) {
        cout << "\nHello, user! What are the numbers?\n";
        num1 = checking(x);
        num2 = checking(x);
        cout << "\nNumber 1: " << num1 << "\nNumber 2: " << num2
             << "\nWhat do you want to do?\n1. +\n2. -\n3. *\n4. /\n5. ^\n6. sqrt\n7.log\n";
        d = checking(d);
        cout << "Your answer: " << d;
        //Сумма
        if (d == 1) {
            x = num1 + num2;
        }
        //Разность
        if (d == 2) {
            x = num1 - num2;
        }
        //Произведение
        if (d == 3) {
            x = num1 * num2;
        }
        //Деление, с учетом возможности введенного 0
        if (d == 4) {
            if (num2 == 0) {
                cout << "\nYou cant divide by zero.";
            } else {
                x = num1 / num2;
            }
        }
        //Квадрат
        if (d == 5) {
            cout << "\nWith which of the numbers do the operation? \n1. " << num1 << "\n2. " << num2;
            //Последние два действия я сделал с выбором числа, с которым нужно произвести подсчет
            cin >> d;
            if (d == 1) {
                x = num1 * num1;
            } else if (d == 2) {
                x = num2 * num2;
            }
            checking(d, x);
            d = 5;
        }
        //Поиск корня
        if (d == 6) {
            cout << "\nWith which of the numbers do the operation? \n1. " << num1 << "\n2. " << num2;
            cin >> d;
            if (d == 1) {
                x = sqrt(num1);
            } else if (d == 2) {
                x = sqrt(num2);
            }
            checking(d, x);
            d = 6;
        }
        //Логарифм
        if (d == 7) {
            cout << "\nWith which of the numbers do the operation? \n1. " << num1 << "\n2. " << num2 <<
                 "\nAnd enter the base\n";
            d = checking(d);
            x = checking(x);
            if (d == 1) {
                d = num1;
                x = log(x, d);
            } else if (d == 2) {
                d = num2;
                x = log(x, d);
            }
            checking(d, x);
            d = 7;
        }
        if (d == 1 || d == 2 || d == 3 || d == 4)
        {
            cout << "\nResult: " << x;
        }
        cout << "\nDo you want to try again? \n1. yes\n2. no\n";
        f = checking(f);
    }
    //Выполнил Соловьев Сергей КЭ-106
    return 0;
}
