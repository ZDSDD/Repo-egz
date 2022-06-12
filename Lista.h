//
// Created by User on 12.06.2022.
//

#ifndef PIERDOLETY_LISTA_H
#define PIERDOLETY_LISTA_H
#include "Podatnik.h"
#include <string>
using namespace std;

struct Lista {
private:
    int Counter=0;
    struct Node{
        string Dane;
        Node *nast;
        explicit Node(string D, Node *N = nullptr){
            Dane=move(D);
            nast = N;
        }
    };
    Node *pocz = nullptr;
public:
    ~Lista();
    void wstaw (TaxPayer &);
    void wypisz();
};


#endif //PIERDOLETY_LISTA_H
