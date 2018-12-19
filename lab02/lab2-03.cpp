#include <iostream>
using namespace std;

double res ()
{
    for (int i=0 ; ;)
    {
        char *S1vy = new char[66];
        double *Vy1S = new double[2];
        for (; ;)
        {
        cin >> S1vy;
        if (*S1vy == '\n')
            break;
        }
        while ((S1vy[i] != '+')||(S1vy[i] != '-')||(S1vy[i] != '*')||(S1vy[i] != '/'))
            i++;
        Vy1S[0] = atof(S1vy);
        char *S1vy1 = new char[99];
        int j = 0;
        while (S1vy[i+1] != '\0')
        {
            S1vy1[j] = S1vy[i + 1];
            j++;
        }
        Vy1S[1] = atof(S1vy1);
        switch (S1vy[i])
        {
            case '+':
                return Vy1S[0] + Vy1S[1];
            case '-':
                return Vy1S[0] - Vy1S[1];
            case '*':
                return Vy1S[0] * Vy1S[1];
            case '/':
                {
                    if (Vy1S[1] == 0)
                    {
                        cout << "\nYou cant divide by zero.";
                        exit(0);
                    }
                   else return Vy1S[0] / Vy1S[1];
                }
        }

    }

}

int main()
{
    //Инициализация массива
    cout << "Введите 2 числа и действие над ними.";
    double R = res();
    cout << "\nРезультат: " << R;
}