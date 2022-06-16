#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include "List.h"
using namespace std;


int main(){

/*settings for random machine*/
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0,9);
/*end of settings*/


string IBAN="2200000000001111111111111111"; //28 chars
char Country[2]={'P','L'};


ofstream FWI("FileWithIBANs.txt",ios::app);
if(FWI.good()){
    int AddMoreIBAN=0;
    cout << "Do you want to add more IBAN numbers? Enter number: "; cin >> AddMoreIBAN;cin.ignore();
    for(int i=0; i< AddMoreIBAN; i++){
        IBAN[0]=Country[0]; IBAN[1]=Country[1];
        for(int j=2; j<28; j++){
            IBAN[j] = dist(gen)+48;
            /*48 is code for '0' in ASCII you can check it by printf("%d",int('0'));
             *Converting numbers in int to the char format*/
        }
        FWI << IBAN << endl;
    }
}else{
    cout << "Couldn't open the file"<<endl;
}
FWI.close();

ifstream FWI_read("FileWithIBANs.txt");
if(FWI_read.good()){
    List MyList;
while(getline(FWI_read,IBAN)){
    MyList.insert(IBAN,28);
}
    MyList.printList();
}
return 0;
}