#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "Dane.h"
#include "Kontener.h"

using namespace std;


ostream &operator<<(ostream &os, Person &PER){
os
<<PER.getDzien()<<"."
<<PER.getMiesiac()<<"."
<<PER.getRok()<<endl
<<PER.getImie()<<endl
<<PER.getNazwsiko()<<endl<<endl;

return os;
}

int main(){

    string PESEL = "00000000000"; //11 digits
    string Nazwisko;
    string Imie;
    string Pelne_imie;

    ifstream osoby("osoba.txt");
    ifstream pesele("pesel.txt");

    Kontener<Person> ListOfPeople;

    /*getting data from files*/

    if(osoby.is_open() && pesele.is_open()){
            cout << "files opened successfully."<<endl;
            while(!osoby.eof() && !pesele.eof()){ //read until you find end of file
                pesele >> PESEL;
                osoby >> Nazwisko;
                getline(osoby,Pelne_imie);
                Pelne_imie.erase(0,1);

                try{
                Person NewPerson(PESEL,Pelne_imie,Nazwisko);
                ListOfPeople.wstaw(NewPerson);
                }
                catch(exception &e){
                    cout << "Error with creating NewPerson: " << e.what() << endl;}
            }

    }else{cout << R"("error opening files "osoba.txt" or "pesel.txt")"<<endl; }

    osoby.close();
    pesele.close();

    /*end working file files to read*/

    ofstream doZapisu("wyniki.txt");

    if(doZapisu.is_open()){
            Person Person_To_Save;
            while(ListOfPeople.len() > 0){
            Person_To_Save = ListOfPeople.Zdejmij();
            doZapisu << Person_To_Save;
            }
    }else{cout << "couldn't open file \"wyniki.txt\""<<endl;}


    return 0;
}
