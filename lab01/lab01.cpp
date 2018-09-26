#include <iostream>
#include <cmath>
using namespace std;
//Функция логарифма
double log (double x, double d)
{
    return log(d)/log(x);
}
int main() {
    int d, f = 1;
    float num1, num2, x;
    //Цикл для выполнения повторного использования калькулятора
    while (f == 1) {
        cout << "\nHello, user! What are the numbers?\n";

        cin >> num1;
        //Защита от дурака. Что в нее входит: если происходит ошибка ввода,
        //то значения игнорируются и обнуляются до тех пор, пока не будет введено корректное значение
        while (cin.fail()) {
            cin.clear();
            cin.ignore(6666, '\n');
            cin >> num1;
        }
        cin >> num2;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(6666, '\n');
            cin >> num2;
        }
        cout << "\nNumber 1: " << num1 << "\nNumber 2: " << num2
             << "\nWhat do you want to do?\n1. +\n2. -\n3. *\n4. /\n5. ^\n6. sqrt\n7.log\n";
        //Если человек введет d<1 или d>7, то программа просто перезапустится
        cin >> d;
        cout << "Your answer: " << d;
        //Сумма
        if (d == 1) {
            x = num1 + num2;
            cout << "\nResult: " << x;
        }
        //Разность
        if (d == 2) {
            x = num1 - num2;
            cout << "\nResult: " << x;
        }
        //Произведение
        if (d == 3) {
            x = num1 * num2;
            cout << "\nResult: " << x;
        }
        //Деление, с учетом возможности введенного 0
        if (d == 4) {
            if (num2 == 0) {
                cout << "\nYou cant divide by zero.";
            } else {
                x = num1 / num2;
                cout << "\nResult: " << x;
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
            //Проверка того, что выбран существующий вариант
            if (d < 1 || d > 2) {
                cout << "\nThere is no such option! :D";
            } else {
                cout << "\nResult: " << x;
            }
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
            if (d < 1 || d > 2) {
                cout << "\nThere is no such option! :D";
            } else {
                cout << "\nResult: " << x;
            }
        }
        if (d ==7) {
            cout << "\nWith which of the numbers do the operation? \n1. " << num1 << "\n2. " << num2 <<
            "\nAnd enter the base\n";
            cin >> d;
            cin >> x;
            if (d == 1) {
                d = num1;
                cout << "\nResult: " << log(x,d);
            } else if (d == 2) {
                d = num2;
                cout << "\nResult: " << log(x,d);
            } else if (d < 1 || d > 2) {
                cout << "\nThere is no such option! :D";
            }
        }
        cout << "\nDo you want to try again? \n1. yes\n2. no\n";
        cin >> f;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(6666, '\n');
            cin >> f;
        }
    }
    //Выполнил Соловьев Сергей КЭ-106
    return 0;
}
