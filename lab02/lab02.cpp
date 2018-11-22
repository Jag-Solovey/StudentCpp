#include <iostream>
using namespace std;
int main()
{   //Инициализация массива
    char **S1vy = new char*[2];
    for (int i = 0; i<2; i++)
        S1vy[i] = new char [10];
    cout << "Input constants:\nFor example: 7 4 5 end";
    for (int i = 0; i<10; i++)
    {
        while (S1vy[1][i] != 'e' && S1vy[1][i+1] != 'n' && S1vy[1][i+2] != 'd') {

            cin >> S1vy[1][i];
        }
    }

    int score = 9;
    cout << "Input action:\nFor example: + * - / end";
    for (int i = 0; i<score; i++)
    {
        cin >> S1vy[2][i];
        while (S1vy[2][i] != '+' || S1vy[2][i] != '-' || S1vy[2][i] != '*' || S1vy[2][i] != '/')
            cout << "There is no such option! :D Try again!\n ";
            cin.clear();
            cin.ignore(6666,'\n');
            cin >> S1vy[2][i];
    }
    //Проверка
    for (int i = 0; i<10; i++)
    cout << S1vy[1][i] << endl;
    return 0;
}