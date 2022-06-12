//
// Created by User on 12.06.2022.
//

#include "Podatnik.h"
using namespace std;
TaxPayer::TaxPayer(string P,string NAME){
    PID=std::move(P);
    Name=std::move(NAME);
}
string TaxPayer::getPID(){
    return PID;
}
string TaxPayer::getName(){
    return Name;
}
TaxPayer::TaxPayer(const string& num_name){
    try {
        if (num_name.length() < 10)throw runtime_error("Bad data format. PID should have 11 characters");
        if (num_name.length() < 13)throw runtime_error("No name of the company");
        PID = num_name.substr(0, 10);
        Name = num_name.substr(11);
    }catch (exception &e){cout << e.what()<<endl;}
}
