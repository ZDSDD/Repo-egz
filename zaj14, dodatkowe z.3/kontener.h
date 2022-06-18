//
// Created by User on 17.06.2022.
//
#ifndef iKNOW
#define iKNOW

#include "dane.h"
#include <string>
#include <stdexcept>

using namespace std;

template<typename Type>
struct List {

private:
    struct Node {
        Type data;
        Node *next = nullptr;

        explicit Node(Type x, Node *N = nullptr) {

            data = x;
            next = N;

        }
    };

    int counter = 0;
    Node *head = nullptr;

public:
    List() = default;

    ~List();

    void insert(Type);

    /* sorting isn't needed. Data should be already sorted. */
    Type takeFromList();

    int len();
};

template<typename Type>
List<Type>::~List() {
    while (head != nullptr) {

        Node *killer = head;
        head = killer->next;
        delete killer;
    }
}

template<typename Type>
void List<Type>::insert(Type el) {

    Node *NEW_NODE = new Node(el);
    if (head == nullptr) {
        head = NEW_NODE;
    } else {
        NEW_NODE->next = head;
        head = NEW_NODE;
    }
    counter++;
}

template<typename Type>
Type List<Type>::takeFromList() {
    if (counter == 0)
        throw logic_error("List is empty");

    Type result = head->data;
    Node *killer = head;
    head = head->next;
    delete killer;
    counter--;

    return result;
}

template<typename Type>
int List<Type>::len() {
    return counter;
}

#endif
