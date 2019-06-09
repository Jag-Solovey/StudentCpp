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
    ostream& operator<<(ostream& os, const Apartment& Apartment)
    {
        os << Apartment.Area << " " << Apartment.NumberOfRooms << " " << Apartment.Square << " " << Apartment.Floor;
        return os;
    }
    istream& operator>>(istream& is, Apartment& Apartment)
    {
        is >> Apartment.Area >> Apartment.NumberOfRooms >> Apartment.Square >> Apartment.Floor;
        return is;
    }
    void Save()
    {
        Apartment Apartment;
        string path = "ListWithApartments.txt";
        ofstream fout;
        fout.open(path, ofstream::app);
        if(!fout.is_open())
        {
            cout << "Error with opening"<< endl;
        }
        else
            {
            cout << "File is save"<< endl;
            while
            fout << Apartment << endl;
            }
        fout.close();
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
    void SavedValues()
    {
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
            List<Apartment> pnt;
            while(fin.read((char*)&pnt, sizeof(Apartment)))
            {
                pnt.print();
            }

        }
        fin.close();
    }
    void check()
    {};

private:
    template<class T1>

    class Node {
    public:
        T1 data;
        Node* next;
    };
    Node<T>* head = nullptr;
};

int main()
{
    int size = 2;
    List<Apartment> list;
    for (int i = 0; i < size; i++) {
        Apartment Apartment;

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
    //list.print();
    cout << "Select a search method:" << endl << "1. Automatic search" << endl << "2. Manual search";
    int a;
    cin >> a;
    if (a == 1)
    {
        list.check();
    }
    if (a == 2)
    {

    }
    list.Save();
    cout << endl;
    list.SavedValues();
    return 0;
}