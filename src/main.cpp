#include <iostream>

#include "RationalNumber.h"

using namespace std;

int main() {

    RationalNumber::RationalNumber rationalNumber1("16/64");
    RationalNumber::RationalNumber rationalNumber2("32/64");

    rationalNumber1 = rationalNumber1 - rationalNumber2;

    cout << rationalNumber1.getNumerator() << "/" << rationalNumber1.getDenominator() << endl;

    return 0;
}
