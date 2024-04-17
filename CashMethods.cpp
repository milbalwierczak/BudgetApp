#include "CashMethods.h"

bool CashMethods::validateAmount(string &amount){
    int pointCounter = 0;
    int decimalPlacesCounter = 0;
    bool result = false;

    for(size_t i = 0; i < amount.length(); i++){
        decimalPlacesCounter++;
        if(isdigit(amount[i])){
            result = true;
        }
        else if (amount[i] == ',') {
           amount[i] = '.';
           if(++pointCounter > 1) return false;
           decimalPlacesCounter = 0;
        }
        else if (amount[i] == '.'){
           if(++pointCounter > 1) return false;
           decimalPlacesCounter = 0;
        }
        else return false;

    }

    if(decimalPlacesCounter > 2 && amount.find('.') != string::npos) return false;

    return result;

}
