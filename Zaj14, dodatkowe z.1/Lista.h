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
    int Counter=0;
    ~Lista();
    void wstaw (TaxPayer &);
    void wypisz();
    void split_to_files();
};


#endif //PIERDOLETY_LISTA_H
