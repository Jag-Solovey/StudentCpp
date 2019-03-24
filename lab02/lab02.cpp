#include <iostream>
using namespace std;
int mAr(char* S1vy, int* Vy1S)
{
    for (int i = 0; i<99; i++) //Ввод переменных
    {
        for (int j = 0; j < 16; j++)
        {
            S1vy[j] = {0};
        }
        cin >> S1vy;
        //Прекращение ввода фразой end
        if ((S1vy[0]=='e')&&(S1vy[1] == 'n')&&(S1vy[2] == 'd')&&(S1vy[3] == '\0'))
        {
            //Условие того, что введено 0 символов или только 1
            if ((i==0)||(i==1))
            {
                cout << "No need for action!";
                exit(0);
            }
            else break;
        }

        Vy1S[i] = atoi(S1vy);
    }
    int n=0;
    while ((Vy1S[n] != 0)||(Vy1S[n+1] != 0))   //Нахождение количества эл-тов массива
    {
        n++;
    }
    return n;
}
void mAr(int* Vy1S, int n, char* S1vy)
{
    int R = Vy1S[0];    //Присвоение значения 1-го эл-та массива для написания формулы поиска результата
    for (int i = 0; i<(n-1); i++)   //Ввод действий и нахождение результата
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
    cout << "\nResult: " << R;
}
int main()
{
    char* S1vy = new char[10];     //Инициализация массива
    int* Vy1S = new int[99];
    cout << "Input constants:\nFor example: 7 4 5 end";
    int n = mAr(S1vy, Vy1S);   //Ввод переменных и подсчет количества элементов
    cout << "Input actions:\nFor example: + - * /";
    mAr(Vy1S, n, S1vy);    //Функция подсчета результата и его вывода на экран
}