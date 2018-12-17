#include <iostream>
using namespace std;

int main()
{
    //Инициализация массива
    char *S1vy = new char[10];
    int *Vy1S = new int[99];
    //Ввод переменных
    cout << "Input constants:\nFor example: 7 4 5 end";
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
           if (i==0) exit(0);
           else break;
        }

        Vy1S[i] = atoi(&S1vy[0]);
    }
    delete S1vy;
    int n=0;
    //Нахождение количества эл-тов массива
    while ((Vy1S[n+1] != 0)||(Vy1S[n+2] != 0))
    {
        n++;
    }
    //Присвоение значения 1-го эл-та массива для написания формулы поиска результата
    int R = Vy1S[0];
    //Ввод действий и нахождение результата
    cout << "Input actions:\nFor example: + - * /";
    for (int i = 0; i<n-1; i++)
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
                  R=R/Vy1S[i+1];
                  break;
                }
        }


    }
    //Вывод результата
    cout << "\nResult: " << R;
}