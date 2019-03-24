#include <iostream>
using namespace std;
int mAr(char* S1vy, double* Vy1S)
{
    for (int i = 0; i<99; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            S1vy[j] = {0};
        }
        cin >> S1vy;
        //Прекращение ввода фразой end
        if ((S1vy[0]=='e')&&(S1vy[1] == 'n')&&(S1vy[2] == 'd')&&(S1vy[3] == '\0'))
        {
            if ((i==0)||(i==1))
            {
                cout << "No need for action!";
                exit(0);
            }
            else break;
        }

        Vy1S[i] = atof(S1vy);
    }
    int n=0;
    while ((Vy1S[n] != 0)||(Vy1S[n+1] != 0)) //Нахождение количества эл-тов массива
    {
        n++;
    }
    return n;
}
void mAr(double* Vy1S, int n, char* S1vy)
{
    double R = Vy1S[0]; //Присвоение значения 1-го эл-та массива для написания формулы поиска результата
    for (int i = 0; i<(n-1); i++)
    {
        for (int j = 0; j < n; j++)
        {
            S1vy[j] = {0};
        }
        cin >> S1vy;
        switch (S1vy[0])
        {
            case '+':
            {
                R = R + Vy1S[i+1];
                break;
            }
            case '-':
            {
                R = R - Vy1S[i+1];
                break;
            }
            case '*':
            {
                R = R * Vy1S[i+1];
                break;
            }
            case '/':
            {
                if  (Vy1S[i+1] == 0)
                {
                    cout << "\nYou cant divide by zero.";
                    exit(0);
                }
                R=R/Vy1S[i+1];
                break;
            }
        }


    }
    //Вывод результата
    cout << "\nResult: " << R;
}
int main()
{
    //Инициализация массива
    char *S1vy = new char[10];
    double *Vy1S = new double[99];
    //Ввод переменных
    cout << "Input constants:\nFor example: 1.75 0.21 9 end";
    int n = mAr(S1vy, Vy1S);   //Ввод переменных и подсчет количества элементов
    cout << "Input actions:\nFor example: + - * /";   //Ввод действий и нахождение результата
    mAr(Vy1S, n, S1vy);    //Функция подсчета результата и его вывода на экран
}
