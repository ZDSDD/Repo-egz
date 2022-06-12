//
// Created by User on 12.06.2022.
//

#include "Lista.h"
#include <iostream>

using namespace std;
Lista::~Lista() {
    Node *Killer;
    while(pocz != nullptr){
        Killer = pocz;
        pocz = pocz ->nast;
        delete Killer;
    }
}
void Lista::wstaw(TaxPayer &Payer) {
    string PID_Name;
    if(Payer.getName().length() == 0)return;
    PID_Name = Payer.getNIP() + " " + Payer.getName();
    Node *Nowy = new Node(PID_Name);
    if(pocz == nullptr)
    pocz = Nowy;
    else{
        if(pocz->nast == nullptr)
            pocz->nast= Nowy;
        else{
            Node *Biegacz = pocz;
            while(Biegacz->nast != nullptr){
                Biegacz=Biegacz->nast;
            }
            Biegacz->nast=Nowy;
        }
    }
    Counter++;
}
void Lista::wypisz(){
Node *Biegacz=pocz;
while(Biegacz != nullptr){
    cout << Biegacz->Dane << endl;
    Biegacz=Biegacz->nast;
}
}