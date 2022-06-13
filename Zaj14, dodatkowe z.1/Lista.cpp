//
// Created by User on 12.06.2022.
//

#include "Lista.h"
#include <iostream>
#include "fstream"
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
void Lista::split_to_files() {
    ofstream Tax_File_771("piotrkow.txt");
    ofstream Tax_File_772("radomsk.txt");
    ofstream Tax_File_773("tomaszow.txt");

    Node *Biegacz = pocz;
    char begOfNIP[3];

    while (Biegacz != nullptr){
        for(int i=0; i<3; i++)
            begOfNIP[i]=Biegacz->Dane[i];
        if(begOfNIP[0] == '7' && begOfNIP[1] == '7' && begOfNIP[2] =='1'){
            Tax_File_771 << Biegacz->Dane<<endl;
        }
        else if(begOfNIP[0] == '7' && begOfNIP[1] == '7' && begOfNIP[2] =='2'){
            Tax_File_772 << Biegacz->Dane<<endl;
        }
        else if(begOfNIP[0] == '7' && begOfNIP[1] == '7' && begOfNIP[2] =='3'){
            Tax_File_773 << Biegacz->Dane<<endl;
        }
        else{
            cout <<Biegacz->Dane<<"\tUnknown NIP"<<endl;
        }
        Biegacz=Biegacz->nast;
    }
    Tax_File_771.close();
    Tax_File_772.close();
    Tax_File_773.close();
}