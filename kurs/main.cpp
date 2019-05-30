#include <iostream>
#include <string.h>

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
        if (i==1) cout << "Your apartment. " << endl;
        else cout <<"Desired apartment. " << endl;
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
    list.print();
    cout << endl;

    return 0;
}