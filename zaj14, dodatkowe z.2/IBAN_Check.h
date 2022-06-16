//
// Created by User on 16.06.2022.
//

#ifndef PIERDOLETY_IBAN_CHECK_H
#define PIERDOLETY_IBAN_CHECK_H

#include <string>


#define ll long long int

using namespace std;

string ChangeCountry_ToNumber(string A);
bool checkControlDigits(string number);
bool checkControlDigit(string number);
// https://www.geeksforgeeks.org/modulo-power-for-large-numbers-represented-as-strings/
ll powerLL(ll x, int MOD) {
    int n = 1;
    ll result = 1;
    while (n) {
        if (n & 1)
            result = result * x % MOD;
        n = n / 2;
        x = x * x % MOD;
    }
    return result;
}

ll powerStrings(string sa, int MOD) {
    ll a = 0;

    // calculating  a % MOD
    for (int i = 0; i < sa.length(); i++)
        a = (a * 10 + (sa[i] - '0')) % MOD;

    return powerLL(a, MOD);
}


bool checkControlDigit(string number) {
    int wages[7] = {7, 1, 3, 9, 7, 1, 3};
    int i;
    int suma = 0;
    for (i = 0; i < 7; i++) {
        suma = suma + (number[i + 4] - '0') * wages[i];
    }
    if (suma % 10 == number[11] - '0') {
        return true;
    }
    return false;
}

bool checkControlDigits(string number) {
    int LenOfIBAN = 0;
    while (number[LenOfIBAN] != '\0') LenOfIBAN++;
    if(number[0]=='P' && number[1] =='L' && LenOfIBAN==28){
        string NUM = ChangeCountry_ToNumber(number);
        char TwoDigitsAfterCountry [2] = {number[2],number[3]};
        char BiggerNumber[LenOfIBAN+3];
        int i;
        for( i = 0; i<LenOfIBAN-4; i++)
            BiggerNumber[i]=number[i+4];
        BiggerNumber[i++] = NUM[0];
        BiggerNumber[i++] = NUM[1];
        BiggerNumber[i++] = NUM[2];
        BiggerNumber[i++] = NUM[3];
        BiggerNumber[i++] = TwoDigitsAfterCountry[0];
        BiggerNumber[i++] = TwoDigitsAfterCountry[1];
        BiggerNumber[i]='\0';
        cout << number << endl;
        cout << BiggerNumber << endl;
        string StringBiggerNumber = BiggerNumber;
        if(powerStrings(StringBiggerNumber,97)==1){
            cout << "Good Control Numbers";
            return true;

        }else{
            cout << "Bad Control Numbers"<< endl;
            //throw logic_error("Bad Control Numbers");
        }
    }
    return false;
}

string ChangeCountry_ToNumber(string A){
    string final = "0000";
    static string CountryDigits[26] = {
            "10", "11", "12", "13", "14",
            "15", "16", "17", "18", "19",
            "20", "21", "22", "23", "24",
            "25", "26", "27", "28", "29",
            "30", "31", "32", "33", "34", "35"};
    final[0] = CountryDigits[A[0] - 'A'][0];
    final[1] = CountryDigits[A[0] - 'A'][1];
    final[2] = CountryDigits[A[1] - 'A'][0];
    final[3] = CountryDigits[A[1] - 'A'][1];
    return final;
}

#endif //PIERDOLETY_IBAN_CHECK_H
