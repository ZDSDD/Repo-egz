//
// Created by User on 12.06.2022.
//

#include "Podatnik.h"
using namespace std;
TaxPayer::TaxPayer(string P,string NAME){
    NIP=std::move(P);
    Name=std::move(NAME);
}
string TaxPayer::getNIP(){
    return NIP;
}
string TaxPayer::getName(){
    return Name;
}
TaxPayer::TaxPayer(const string& num_name){
    try {
        if (num_name.length() < 9)throw runtime_error("Bad data format. NIP should have 10 characters");
        if (num_name.length() < 10)throw runtime_error("No name of the company");
        NIP = num_name.substr(0, 9);
        Name = num_name.substr(11);
    }catch (exception &e){cout << e.what()<<endl;}
}
