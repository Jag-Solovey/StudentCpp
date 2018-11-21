#include <iostream>
using namespace std;
int main()
{   //Инициализация массива
    int **S1vy = new int*[2];
    for (int i = 0; i<2; i++)
        S1vy[i] = new int [10];

    cout << "Input constants:\nFor example: 357 4 5 end";
    for (int i = 0; i<10; i++)
        cin >> S1vy[1][i];
    for (int i = 0; i<10; i++)
    cout << S1vy[1][i] << endl;
    return 0;
}