#include "Dane.h"

Person::Person(string PESEL,string Pelne_Imie,string NAZWISKO)
{
    if(!GoodPesel(PESEL))throw logic_error("PESEL BAD LENGTH");

    if(NAZWISKO=="" || Pelne_Imie == "") {Pelne_Imie = " DO "; NAZWISKO = " WERYFIKACJI ";}

    pesel = PESEL;
    pelne_imie = Pelne_Imie;
    nazwisko = NAZWISKO;
    setDateOfBirth(pesel);
}

void Person::setDateOfBirth(const string PESEL){

    if(PESEL[4] > '1'){
        rok = "20";
        rok+=PESEL[0];
        rok+=PESEL[1];

        dzien=PESEL[2];
        dzien+=PESEL[3];

        miesiac=PESEL[4]-2;
        miesiac+=PESEL[5];
    }
    else{
                rok = "19";
        rok+=PESEL[0];
        rok+=PESEL[1];

        dzien=PESEL[2];
        dzien+=PESEL[3];

        miesiac=PESEL[4];
        miesiac+=PESEL[5];
    }
}

bool Person::GoodPesel(string pes){
if(pes.length() != 11) return false;
for(char a : pes){
    if (a >= '0' && a<='9') continue;
    else return false;
}
return true;
}

bool Person::GoodControlNumber(string pes){
    if(!GoodPesel(pes))return false;

    static const int control[11]={1,3,7,9,1,3,7,9,1,3,1};
    int sum = 0;
    int i;

    for(i=0; i<11; i++)
    sum = sum + (pes[i]-'0')*control[i];

    if(sum % 10 == 0) return true;
    else return false;
}
bool Person::operator>=(Person &P)const{
int intROK;
int intROK2;
intROK = (rok[0]-'0')*1000 + (rok[1]-'0')*100 + (rok[2]-'0')*10 + (rok[3]-'0');
intROK2 = (P.rok[0]-'0')*1000 + (P.rok[1]-'0')*100 + (P.rok[2]-'0')*10 + (P.rok[3]-'0');

if (intROK > intROK2) return true;
else if(intROK < intROK2) return false;
else{// intROK == intROK2
    int intMIESIAC = (miesiac[0]-'0')*10 + (miesiac[1]-'0');
    int intMIESIAC2 = (P.miesiac[0]-'0')*10 + (P.miesiac[1]-'0');
    if(intMIESIAC > intMIESIAC2)return true;
    else if(intMIESIAC < intMIESIAC2)return false;
    else{// intMIESIAC == intMIESIAC2
        int intDZIEN = (dzien[0]-'0')*10 + (dzien[1]-'0');
        int intDZIEN2 = (P.dzien[0]-'0')*10 + (P.dzien[1]-'0');
        if(intDZIEN >= intDZIEN2)return true;
        else return false;
    }
}
}

