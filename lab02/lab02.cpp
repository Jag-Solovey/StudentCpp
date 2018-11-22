#include <iostream>
using namespace std;
int main()
{   //Инициализация массива
    char **S1vy = new char*[2];
    for (int i = 0; i<2; i++)
        S1vy[i] = new char [10];
    cout << "Input constants:\nFor example: 7 4 5 end";
    for (int i = 0; i<10; i++)
        cin >> S1vy[1][i];
    //Проверка
    for (int i = 0; i<10; i++)
    cout << S1vy[1][i] << endl;
    return 0;
}