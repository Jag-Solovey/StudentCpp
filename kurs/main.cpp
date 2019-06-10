#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;


class Apartment {
public:
    char* Area = 0;
    unsigned int Square = 0;
    unsigned int Floor = 0;
    unsigned int NumberOfRooms = 0;

};

template<class T>
class List {
public:
    ~List() {
        while (head != nullptr) {
            Node<T>* next = head->next;
            delete head;
            head = next;
        }
    }
    void Save(T Apartment)
    {
        string path = "ListWithApartments.txt";
        fstream fs;
        fs.open(path,fstream::in|ofstream::app);
        if(!fs.is_open())
        {
            cout << "Error with opening"<< endl;
        }
        else
            {
            cout << "File is save"<< endl;
                while (head != nullptr) {
                    Node<T>* next = head->next;
                    fs << Apartment << "\n";
                    head = next;
                }
            }
        fs.close();
    }

    void addFirst(T Apartment) {
        Node<T> *temp = new Node<T>;
        temp->data = Apartment;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }
    void print() {
        Node<T> *temp = head;
        while (temp != nullptr) {
            cout << "Area: " << temp->data.Area << " Square: " << temp->data.Square << " Floor: " <<
                 temp->data.Floor << " Number of rooms: " << temp->data.NumberOfRooms<< endl;
            temp = temp->next;
        }
    }
    void SavedValues(T Apartment)
    {
        List list;
        string path = "ListWithApartments.txt";
        ifstream fin;
        fin.open(path);
        if(!fin.is_open())
        {
            cout << "Error with opening"<< endl;
        }
        else
        {
            cout << "File is open"<< endl;
            T pnt;
            while(fin.read((char*)&pnt, sizeof(Apartment)))
            {
                fin >> pnt;
                list.addFirst(pnt);
                if (!fin.read((char*)&pnt,  sizeof(Apartment)))
                break;
            }

        }
        fin.close();
    }
    void check(T Apartment, int size)
    {
        List list;
        int i=0;
        while (i!=size)
        {
            if (Apartment[0] == Apartment[i])
            {
                cout << "Found this apartment option";
                list(Apartment[i]).print;
                remove(Apartment[0]);
                remove(Apartment[i]);
                break;
            } else i++;
        }
        cout << "Nothing found";
    }
    void check(T Apartment, int size, int i)
    {
        List list;

            if (Apartment[0] == Apartment[i])
            {
                cout << "\nConditions are met. Exchange confirmed."<<endl;
                list(Apartment[i]).print;
                remove(Apartment[0]);
                remove(Apartment[i]);
            } else "\nTerms violated. Exchange is prohibited.";
        }
    T& operator[](const int index)
    {
        int count = 0;
        List *temp = this->First;
        while(temp != nullptr)
        {
            if (count == index)
            {
                return temp->data;
            }
            temp = temp->Next;
            count++;
        }
    }
private:
    template<class T1>

    class Node {
    public:
        T1 data;
        Node* next;
    };
    Node<T>* head = nullptr;
};
ostream& operator<<(ostream& out, Apartment& a)
{
    out << a.Area << " " << a.NumberOfRooms << " " <<
    a.Square << " " << a.Floor;
    return out;
}
istream& operator>>(istream& in, Apartment& a)
{
    in >> a.Area >> a.NumberOfRooms >>
    a.Square >> a.Floor;
    return in;
}
bool operator==(Apartment& a1, Apartment& a2)
{
    return (a1.NumberOfRooms == a2.NumberOfRooms && a1.Floor == a2.Floor &&
            (a1.Square * 0.1 + a1.Square > a2.Square) &&
            (a1.Square - a1.Square * 0.1 < a2.Square));
}

int main()
{
    int size = 2;
    List<Apartment> list;
    Apartment Apartment;
    for (int i = 0; i < size; i++) {
        char* in = new char[10];
        if (i==0) cout << "Desired apartment. " << endl;
        else cout <<"Your apartment. " << endl;
        cout << "Area: ";
        cin >> in;

        Apartment.Area = new char[strlen(in) + 1];
        strcpy(Apartment.Area, in);
        Apartment.Area[strlen(in)] = '\0';
        cout << "Number of rooms: ";
        cin >> Apartment.NumberOfRooms;
        cout << "\nSquare of apartment: ";
        cin >> Apartment.Square;
        cout << "\nFloor: ";
        cin >> Apartment.Floor;
        list.addFirst(Apartment);
    }
    list.SavedValues(Apartment);
    cout << "Select a search method:" << endl << "1. Automatic search" << endl << "2. Manual search";
    int a;
    cin >> a;

    if (a == 1)
    {
        list.check(Apartment, size);
    }
    if (a == 2)
    {
        list.print();
        cout << "\nChoose the numder of apartment that interests you";
        int c;
        cin >> c;
        list.check(Apartment, size, c);
    }
    list.Save(Apartment);
    cout << endl;
    return 0;
}