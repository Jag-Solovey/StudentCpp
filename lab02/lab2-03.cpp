#include <iostream>
using namespace std;

int main()
{
    char *S1vy = new char[66]; //Массив для ввода
    double *Vy1S = new double[2]; //Массив для чисел
    cout << "Enter expression, please!\nFor example: 55+55";
    cin.getline(S1vy,66); //Ввод массива
    int i = 0;
    for (i;i<66;i++) //Проверка на пробелы
    {
        if ((S1vy[i] == ' ')&&(S1vy[i + 1] != ' '))
        {
            cout << "Input error, try again :)";
            exit(0);
        }
    }
    cout << "\nInput the expression: " << S1vy;
    i = 0;
    while ((S1vy[i] != '+')&&(S1vy[i] != '-')&&(S1vy[i] != '*')&&(S1vy[i] != '/')) //Поиск индекса массива, хранящий действие над числами
        i++;
    int p = i; //Сохранение индекса
    int j = i+2; //Скачек через действие
    while (S1vy[j] != '\0') //Поиск окончания строки
        j++;
    char *S2vy = new char[66]; //Массив для выделения первого числа
    int k = 0;
    while (k != i)
    {
        S2vy[k]=S1vy[k];
        k++;
    }
    Vy1S[0] = atof(S2vy); //Присвоение значения первого числа
    delete [] S2vy;
    char *S3vy = new char[66]; //Массив для выделения второго числа
    k = k+1;
    i = 0;
    while (k <= j)
    {
        S3vy[i] = S1vy[k];
        k++;
        i++;
    }
    Vy1S[1] = atof(S3vy); //Присвоение значения второго числа
    delete [] S3vy;
    int R = 0;
    switch (S1vy[p]) //Действие с числами
    {
        case '+':
        {
            R = Vy1S[0] + Vy1S[1];
            break;
        }
        case '-':
        {
            R = Vy1S[0] - Vy1S[1];
            break;
        }
        case '*':
        {
            R = Vy1S[0] * Vy1S[1];
            break;
        }
        case '/':
        {
            if  (Vy1S[1] == 0)
            {
                cout << "\nYou cant divide by zero.";
                exit(0);
            }
            R = Vy1S[0]/Vy1S[1];
            break;
        }
    }
    cout << "\nResult:" << R;
}