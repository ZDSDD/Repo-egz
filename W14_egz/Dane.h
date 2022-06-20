#ifndef DANE_H
#define DANE_H

#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

struct Person
{
    public:
       Person(string PESEL="00000000000",string pelne_imie="#",string nazwisko="#");
       bool GoodPesel(string pes);
       bool GoodControlNumber(string pes);
       void setDateOfBirth(const string PESEL);
       bool operator>=(Person &per)const;

       string getPesel(){
       return pesel;}
       string getDzien(){
       return dzien;}
       string getRok(){
       return rok;}
       string getMiesiac(){
       return miesiac;}
       string getImie(){
       return pelne_imie;}
       string getNazwsiko(){
       return nazwisko;}


    private:
        string pesel="00000000000"; //11
        string pelne_imie;
        string nazwisko;
        string dzien="0";
        string miesiac="0";
        string rok="0";
};

#endif // DANE_H
