#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Apartment //Класс для выделения памяти для площади, этажа и кол-ва комнат
{
public:
    unsigned int Square = 0, Floor = 0, NumberOfRooms = 0;
};
bool operator==(Apartment& a1, Apartment& a2)
{
    return ((a1.Square/10 + a1.Square >= a2.Square)&&
            (a1.Square - a1.Square/10 <= a2.Square)&& a1.Floor == a2.Floor&&
            a1.NumberOfRooms == a2.NumberOfRooms);
}
ostream& operator<<(ostream& out, Apartment& a)
{
    out << a.NumberOfRooms << " " <<
    a.Square << " " << a.Floor;
    return out;
}
istream& operator>>(istream& in, Apartment& a)
{
    in >> a.NumberOfRooms >>
    a.Square >> a.Floor;
    return in;
}
/*Ассоциативный массив — абстрактный тип данных (интерфейс к хранилищу данных),
позволяющий хранить пары вида «(ключ, значение)»
и поддерживающий операции добавления пары, а также поиска и удаления пары по ключу.
То есть по сути нам надо создать класс хранящий пары.
Ассоциативный массив будет реализован на основе расширяющегося массива.
*/

template<class Key,class Value>//здесь используется одномерный массив
class assocArray
{
private:
    struct pair                //структура хранящая пару ключ значение
    {
        Key key;
        Value value;
    };
    pair* pairs;               //одномерный массив структуры
    int size;                  //размер массива
    int len;                   //кол-во элементов массива, которые заполнены
public:
    assocArray () : size(1), len(0) //конструктор по умолчанию
    {
        pairs = new pair[size];    //создается массив размером 1, len=0 так массив пуст
    }
    assocArray (const assocArray & arr)//конструктор копирования
    {
        size = arr.size;
        len = arr.len;
        pairs = new pair[size];
        for (int i = 0; i < len; i++)
        {
            pairs[i].key = arr.pairs[i].key;
            pairs[i].value = arr.pairs[i].value;
        }
    }
    ~assocArray ()//деструктор
    {
        delete[] pairs;
    }
    void _delete(Key key)//метод удаления по ключу
    {
        bool test = false;
        for (int i = 0; i < len; i++) //проверка на то есть ли в массиве элемент который нужно удалить
        {
            if (pairs[i].key == key)
            {
                test = true;
            }
        }
        if (test == true)//если test=true, то есть есть элемент с похожим ключем, выполняется следующие
        {
            pair *temp = new pair[size];//создается временный массив
            memcpy(temp, pairs, sizeof(pair) * size);//в него компируется все данный
            this->~assocArray();//удаляется основной массив и дальше обнуляются все значение
            size = 1;
            int _len = len;
            len = 0;
            pairs = new pair[size];//основной массив создается заного
            for (int i = 0; i < _len; i++)//проверка есть ли во временном массиве введенный в метод ключ
            {
                if (temp[i].key != key)//если по текущему индексу ключ и введеный ключ не совпадают то
                {
                    insert(temp[i].key, temp[i].value);//в метод добавления передаются ключ и значение
                }
            }
        }
    }
    void insert(Key key, Value value)//собственно метод добавления в массив, так как ключи не уникальный, то здесь нет проверки ключа на уникальность
    {
        if (len == size)//проверка на заполненность массива
        {
            pair* old = pairs;//копия массива
            pairs = new pair[size *2];//создается новый массив размер которого в 2 раза больше
            memcpy(pairs, old, sizeof(pair) * size);//копирование элементов в новый массив
            size *= 2;
            delete old;
        }
        pair temp;//создается временая переменная содержащая структуру
        temp.key = key;//присваивается ключ
        temp.value = value;//присваивается значение
        pairs[len++] = temp;//следующему элементу массива присваивается значение времменой
    }
    void show()//вывод всех заполненых элементов массива
    {
        for (int i = 0; i < len; i++)
        {
            cout << " " <<i+1<< ". " << pairs[i].key << " : " << pairs[i].value << endl;
        }
    }
    Value& operator[](Key key)//перегрузка оператора [ ] для вывода значения по ключу
    {
        for (int i = 0; i < len; i++) // но так как ключи не уникальные, то выведется первый найденный ключ
        {
            if (pairs[i].key == key)
            {
                return pairs[i].value;
            }
        }
        throw;
    }
    void getAll(Key key)//метод для получения всех значений у которых равные ключи
    {
        for (int i = 0; i < len; i++)
        {
            if (pairs[i].key == key)
            {
                cout << pairs[i].value << endl;
            }
        }
    }
    void getAll(Value value)//вывод всех ключей у которых равные значения
    {
        for (int i = 0; i < len; i++)
        {
            if (pairs[i].value == value)
            {
                cout << pairs[i].key << endl;
            }
        }
    }
    friend ostream& operator<<(ostream& out, assocArray& a)//перегрузка оператора вывода
    {
        for (int i = 0; i < a.len; i++)
        {
            out << a.pairs[i].key << " : " << a.pairs[i].value << endl;
        }
        return out;
    }
    friend istream& operator>>(istream& in, assocArray& a)//перегрузка оператора ввода
    {
        Key key;//создаются временные поля для ввода и последующей передачи их в метод добавления
        Value value;
        in >> key;
        in >> value;
        a.insert(key, value);
        return in;
    }
    Key& operator[](Value value)//перегрузка оператора [ ] для вывода ключа по значению
    {
        for (int i = 0; i < len; i++)
        {
            if (pairs[i].value == value)
            {
                return pairs[i].key;
            }
        }
        throw;
    }
    void save()//метод сохранения с относительным путем
    {

        ofstream out;
        out.open("ListWithApartments.txt");
        for (int i = 0; i < len; i++)
        {
            if (i == len - 1)//если элемент последний то не будет перехода на новую строку, так потом при вводе это создаст ошибку
            {
                out << pairs[i].key << endl << pairs[i].value;
            }
            else
            {
                out << pairs[i].key << endl << pairs[i].value<<endl;
            }
        }
        out.close();
    }
    void download()
    {
        bool test = true;//переменная которая нужна при проверки достигнут ли конец файла
        ifstream in;
        in.open("ListWithApartments.txt");
        if (!in)
        {
            cout << "error" << endl;
        }
        else
        {
            Key key;
            Value value;
            while (!in.eof())//вводится до тех пор пока не будет достигнут конец файла
            {
                in >> key;
                in >> value;
                insert(key, value);
            }
        }
        in.close();
    }
    void check()                    //функция для автоматической проверки
    {
        for (int i=2; i <= len; i++)
        {
            if (pairs[i].value == pairs[0].value)
            {
                cout << "Found this apartment option" << endl;
                cout << "Area: " << pairs[i].key << " Square, floor and number of rooms: " << pairs[i].value;
                pairs[0].key = "delete"; //Присвоения ключа удобного для удаления
                pairs[1].key = "delete";
                pairs[i].key = "delete";
                break;
            }
            if (i == len)
                {
                    cout << "Nothing found";
                    pairs[0].key = "delete";
                    break;
                }
        }
    }
    bool check(int a, int x)                 //функция для проверки ручного поиска
    {
        if (pairs[a].value == pairs[0].value)
        {
            cout << "\nConditions are met. Exchange confirmed." << endl;
            pairs[0].key = "delete";
            pairs[1].key = "delete";
            pairs[a].key = "delete";
            return true;
        }
        else
        {
            if (x == 2)    //Функция для выходя при 3 неудачных попытках выбора
            {
                cout << "Can't find a suitable option?";
                string y;
                cin >> y;
                if (y == "yes")
                {
                    pairs[0].key = "delete";
                    return true;
                }
            }
            cout << "\nTerms violated. Exchange is prohibited. \nChoose another option: ";
            return false;
        }
    }
};

int main()
{
    /*assocArray <string, int> test;     //проверка шаблонной коллекции на работоспособность
    test.download();
    cout << test;
    cin >> test;
    cin >> test;
    cout << test;
    test.save();
    return 0;*/

    assocArray <string, Apartment> Apartment;
    for (int i = 0; i < 2; i++)   //Ввод изначальных пунктов: желаемой и искомой квартиры
    {
        if (i==0) cout << "Desired apartment. " << endl;
        else cout << "Your apartment. " << endl;
        cout << "Area:  \nSquare of apartment:  \nFloor:  \nNumber of rooms:  " << endl;
        cin >> Apartment;
    }
    Apartment.download();    //Добавление в массив квартир из сохраненного списка
    cout << "Select a search method:" << endl << "1. Automatic search" << endl << "2. Manual search";
    int a;
    cin >> a;
    if (a == 1)
    {
        Apartment.check();  //Применение функции автоматического поиска
    }
    if (a == 2)
    {
        Apartment.show();
        cout << "\nChoose the numder of apartment that interests you";
        int c,x = 0;
        cin >> c;
        c = c-1;
        while(!(Apartment.check(c, x)))  //Применение логической функции ручного поиска
        {                                // Выполняется до момента удачного выбора или при достижении условия отмены выбора
            x++;
            cin.clear();
            cin.ignore(6666,'\n');
            cin >> c;
        }
    }
    Apartment._delete("delete");
    remove("ListWithApartments.txt");
    Apartment.save();
}