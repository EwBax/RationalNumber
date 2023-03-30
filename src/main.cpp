#include <iostream>
#include <regex>

#include "../inc/RationalNumber.h"

using namespace std;

string getRationalNumberString() {

    // Regex for matching input format ^-?\d+(\/-?0*[1-9](\d+)?)?$
    regex regex(R"(^-?\d+(\/-?0*[1-9](\d+)?)?$)");

    string input;

    while (true) {

        getline(cin, input);

        // Validating and breaking loop if valid
        if (std::regex_match(input, regex)) {break;}

        cout << "That is not a valid format for a rational number. Please use the following "
                "formats: (-)#, or (-)#/(-)# with a denominator not equal to zero." << endl;

    }

    return input;

}

int main() {

    cout<< "RATIONAL NUMBER DRIVER / DEMO" << endl << endl;

    cout << "Enter the first rational number: ";

    RationalNumber::RationalNumber rationalNumber1(getRationalNumberString());

    cout << "Enter the second rational number: ";

    RationalNumber::RationalNumber rationalNumber2(getRationalNumberString());

    cout << endl;

    RationalNumber::RationalNumber result;

    result = rationalNumber1 + rationalNumber2;
    cout << rationalNumber1 << " + " << rationalNumber2 << " = "
        << result << endl << endl;


    result = rationalNumber1 - rationalNumber2;
    cout << rationalNumber1 << " - " << rationalNumber2 << " = "
        << result << endl << endl;

    result = rationalNumber1 * rationalNumber2;
    cout << rationalNumber1 << " * " << rationalNumber2 << " = "
        << result << endl << endl;

    result = rationalNumber1 / rationalNumber2;
    cout << rationalNumber1 << " / " << rationalNumber2 << " = "
        << result << endl << endl;



    return 0;
}
