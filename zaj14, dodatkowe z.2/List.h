//
// Created by User on 13.06.2022.
//

#ifndef PIERDOLETY_LIST_H
#define PIERDOLETY_LIST_H
#include <string>
#include <utility>
using namespace std;

struct List {
private:
    struct Node{
        string iban;
        Node *nast;
        Node(string CODE,Node* N= nullptr){
            nast=N;
            iban=std::move(CODE);
        }
    };
    int counter=0;
    Node *pocz= nullptr;
public:
    ~List();
    List()=default;
    void insert(const string&,int);
    void printList();
    string *Give(string);
};


#endif //PIERDOLETY_LIST_H
