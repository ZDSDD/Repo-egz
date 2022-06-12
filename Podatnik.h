//
// Created by User on 12.06.2022.
//

#ifndef PIERDOLETY_PODATNIK_H
#define PIERDOLETY_PODATNIK_H

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

struct TaxPayer {
private:
    string NIP;
    string Name;
public:
    TaxPayer()=default;
    TaxPayer(string,string);
    TaxPayer(const string&);

/*    void setPID(string);
    void setName(string);*/

    string getNIP();
    string getName();
};


#endif //PIERDOLETY_PODATNIK_H
