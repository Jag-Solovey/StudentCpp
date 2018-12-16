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
        {break;};

        Vy1S[i] = atoi(&S1vy[0]);
    }
    //Присвоение значения 1-го эл-та массива для написания формулы поиска результата
    int R = Vy1S[0];
    //Ввод действий и нахождение результата
    cout << "Input actions:\nFor example: + - * /";
    for (int i = 0, k, x; i<=k; i++)
    {
        //Нахождение количества эл-тов
        k=0;
        while ((Vy1S[x] != 0)&(Vy1S[x+1] != 0))
        {
            k++;
            x++;
        }
        x=0;
        k=k-1;
        for (int j = 0; j < 16; j++)
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