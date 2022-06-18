//
// Created by User on 17.06.2022.
//

#ifndef iKNOW_DANE_H
#define iKNOW_DANE_H
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;
struct person{
private:
    string nip;
    string last_name;
    string name;
    string money;
public:
    explicit person(const string& NIP="0000000000",const string& LAST_NAME="#",const string& NAME="#",const string& MONEY="#");
    /*explicit to avoid hidden bugs*/

    static bool is_it_nip(const string &NIP);
    static bool GoodNIP(const string&);

    person & operator=(const person &per)= default;
    bool operator <(const person &per)const;


    string get_nip();
    string get_last_name();
    string get_name();
    string get_money();
    string get_round_money();
    static bool CheckMoney(const string&);

};

#endif //iKNOW_DANE_H
