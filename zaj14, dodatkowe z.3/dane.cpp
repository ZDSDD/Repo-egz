//
// Created by User on 17.06.2022.
//

#include "dane.h"



person::person(const string& NIP, const string& Last_Name, const string& Name, const string& Money) {

    if (!is_it_nip(NIP))throw logic_error("WRONG NIP");
    nip = NIP;
    last_name = (Last_Name);
    name = (Name);
    money = (Money);
    if (!GoodNIP(nip))
        nip = nip + " WRONG CONTROL NUMBER";

}

bool person::is_it_nip(const string &NIP) {
    if (NIP.length() != 10)return false;
    for (int i = 0; i < 10; i++)
        if (NIP[i] < '0' || NIP[i] > '9') return false;
    return true;

}

bool person::GoodNIP(const string &NIP) {

    if (!is_it_nip(NIP))return false;
    int sum;
    static int wages[9] = {6, 5, 7, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 9; i++)
        sum = sum + (NIP[i] - '0') * wages[i];
    return (sum % 11 == NIP[9]);

}

bool person::operator<(const person &per) const {
    {
        int j=0;
        while(this->name.length() > j){
            if(this->name[j] > per.last_name[j])return true;
            else if(this->name[j] < per.last_name[j])return false;
            j++;
        }
        return false;
    }
}

string person::get_nip() {return this->nip;}
string person::get_last_name() {return this->last_name;}
string person::get_money() {return this->money;}
string person::get_name() {return this->name;}

bool person::CheckMoney(const string &money){
    //124.23  -1231233.23
    for(char a : money){
        if(a=='-'||a=='.'||a>='0'&&a<='9')continue;
        else{
            return false;
        }
    }
    return true;
}
string person::get_round_money() {
    if(!CheckMoney(get_money()))return get_money()+" - DO WERYFIKACJI";

    string MONEY=get_money();

    unsigned long long Dot = MONEY.find('.');
    if(MONEY[Dot+1]<'5'){   //9.4 ~ 9
        MONEY.erase(Dot,MONEY.length());
    }
    else{ // 9.5 ~ 10
        if(MONEY[Dot-1] == '9') {
            int i = 1;
            while (Dot - i >= 0 && MONEY[Dot - i] == '9') { //when we have more than one '9' like 423999999.65
                MONEY[Dot - i] = '0';                       //change every value to 0 until you find end or '-' or <'9'
                i++;
            }
            if(Dot-i == 0 && MONEY[Dot-i] == '-'){ //when we have negative value and something like -9999.90
                MONEY[Dot-i] = '0';                //change '-' to '0'
                MONEY.insert(0,"-1");       //and add "-1" to the beginning, so we have -10000.90

            }else if(Dot - i ==-1){                 //when we have positive value and something like 9999.90
                MONEY.append("1");                 //just add 1 to the beginning, because value looks now 0000.90
            }
            else{                                   //when we are just out of loop so the value is like 456999.60
                MONEY[Dot-i] +=1;                   //add to 45[6]000.60 +1 so = 45[7]000.60
            }
        }else {                                     //when there is no need to go into loop because value is like 453249.67
            MONEY[Dot - 1] += 1;                    //4532[5]0.67
        }
        MONEY.erase(MONEY.find('.'),MONEY.length());
    }
    return MONEY;
}