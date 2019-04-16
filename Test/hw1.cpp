
//#pragma once template <class T>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


    template<class T> class List {
    private:

        template<class T1>
        class Node {
        public:
            T1 data;
            Node *next;
        };

        Node<T> *head = nullptr;


    public:
        void addFirst(int book) {
            Node<T> *temp = new Node<T>;
            temp->data = book;
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
                cout << temp->data << endl;
                temp = temp->next;
            }
        }

        void clear()
        {
            T* temp = nullptr;
            swap(temp, head);
            delete[] temp;
        }
    };


int main()
{
    setlocale(LC_ALL, "Rus");
    int size = 3;
    List<int> list;
    for (int i = 0; i < size; i++) {
        int book;


        cout << "Book " << i << ". Year: ";
        cin >> book;

        list.addFirst(book);
    }
    list.print();
    list.clear();
    }
