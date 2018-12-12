#include <iostream>
using namespace std;
int main()
{   //Инициализация массива
    char *S1vy = new char[10];
    int *Vy1S = new int[99];
    cout << "Input constants:\nFor example: 7 4 5 end";
    for (int i = 0; i<99; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            S1vy[j] = {0};
        }
        cin >> S1vy;
        if ((S1vy[0]=='e')&&(S1vy[1] == 'n')&&(S1vy[2] == 'd')&&(S1vy[3] == '\0'))
        {break;};

        Vy1S[i] = atoi(&S1vy[0]);
    }
    //for (int i = 0; i<10; i++)
        //cin >> S1vy[2][i];
    //Проверка
    for (int i = 0; i<10; i++)
    cout << Vy1S[i] << endl;
    return 0;
}