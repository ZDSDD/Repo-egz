#include <iostream>
#include <string>
#include <fstream>
#include <random> // testing library for better randomness
#include "Podatnik.h"
#include "Lista.h"
using namespace std;

int main(){

/* Settings to number generator */
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(0,9);
/* End of setting */

    string NIP="0000000000"; //10 digits
    string CompanyName;

    int Companies_to_add=0;
    cout << "Enter number of companies you want to add(0 for skip): "; cin >> Companies_to_add; cin.ignore();
    ///Start work with file
    if(Companies_to_add > 0) {
        ofstream File_Taxpayers("MyData.txt", ios::app);
        if (File_Taxpayers.good()) {
            int i, j;
            for (i = 0, j = 0; i < Companies_to_add; i++, j = 0) {
                NIP.replace(j, 1, to_string(dist(gen)));
                if (NIP[0] == '0')NIP[0] = '1';
                for (j = 1; j < 10; j++) {
                    NIP.replace(j, 1, to_string(dist(gen)));
                }
                cout << "Enter company name: ";
                getline(cin, CompanyName);
                if(!CompanyName.empty())
                File_Taxpayers << NIP << " " << CompanyName<<endl;
            }
        }else cout << "Couldn't open the file" << endl;
        File_Taxpayers.close();
        ///File close, end input
    }
    ///Start reading from file
    ifstream Tax_File("MyData.txt");
    if(Tax_File.good()){
        Lista ListOfTaxPaxers;
        string NIPandName;
        while(getline(Tax_File,NIPandName)){
            TaxPayer Payer(NIPandName);
            ListOfTaxPaxers.wstaw(Payer);
        }
        ListOfTaxPaxers.wypisz();
        ListOfTaxPaxers.split_to_files();
    }
    Tax_File.close();
    return 0;
}