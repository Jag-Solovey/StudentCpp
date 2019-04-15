//template <class T1>
#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
namespace StructList
{
struct Book
{
    char* Name;
    int Year;
};
struct List
{
    struct Node
    {
        Book data;
        Node* next;
        Node* prev;
    };
    Node* head = nullptr;

    void addFirst(Book book)
    {
        Node* temp = new Node;
        temp->data = book;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = temp;
            return;
        }

        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void print()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data.Name << " (" << temp->data.Year << ")" << endl;
            temp = temp->next;
        }
    }

    void clear()
    {

        while (head != nullptr)
        {
            delete[] head->data.Name;
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
}
using namespace StructList;
int main()
{
    setlocale(LC_ALL, "Rus");
    int arraySize = 3;
    List list;

    for (int i = 0; i < arraySize; i++)
    {
        Book book;

        char* buff = new char[255];
        cout << "Книга " << i << ". Название: ";
        cin >> buff;

        book.Name = new char[strlen(buff) + 1];
        strcpy(book.Name, buff);
        book.Name[strlen(buff)] = '\0';

        cout << "Книга " << i << ". Год: ";
        cin >> book.Year;

        list.addFirst(book);
    }

    list.print();
    list.clear();
}