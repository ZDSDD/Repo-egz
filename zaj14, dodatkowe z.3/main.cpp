#include <iostream>
#include <string>
#include <fstream>

#include "kontener.h"
#include "dane.h"

using namespace std;

ostream &operator<<(ostream &os, person &per){
    os
    <<per.get_last_name()
    <<endl
    <<per.get_name()
    <<endl
    <<per.get_nip()
    <<endl
    <<per.get_round_money()
    <<endl << endl;
    return os;
}

int main() {

    ifstream plik("podatnicy.txt");
    ifstream plik2("rozliczenia.txt");

    List<person> list;

    string nip;
    string last_name;
    string name;
    string Money;

    if (plik.is_open() && plik2.is_open()) {
        /*start read file*/
        while (!plik.eof() && !plik2.eof()) {
            getline(plik, nip);
            if (nip.empty())continue;// if empty line - restart the loop
            plik >> last_name;
            plik2 >> Money;
            plik.ignore(1); // delete space;
            getline(plik, name);
            try {

                person iPer(nip, last_name, name, Money);
                list.insert(iPer);

            } catch (exception &e) { cout << "error: " << e.what() << endl; }
        }
        /*end read file*/
        plik.close();
        plik2.close();

        ofstream file_save("wyniki.txt");
        if (file_save.is_open()) {
            person toSave;
            while (list.len() > 0) {
                toSave = list.takeFromList();
                file_save << toSave;
            }
            file_save.close();
        } else { cout << "error open file \"wyniki.txt\"" << endl; }
    } else { cout << R"(Error opening files "podatnicy.txt" "rozliczenia.txt")";}
    return 0;
}
