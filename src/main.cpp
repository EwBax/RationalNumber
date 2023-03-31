#include <iostream>
#include <regex>

#include "../inc/RationalNumber.h"

using namespace std;

// Function to get and validate input for making a rational number
RationalNumber::RationalNumber getRationalNumberInput() {

    // Regex for matching input format ^-?\d+(\/-?0*[1-9](\d+)?)?$
    regex regex(R"(^-?\d+(\/-?0*[1-9](\d+)?)?$)");


    RationalNumber::RationalNumber rationalNumber;

    cout << "Enter a rational number: ";

    while (true) {

        string input;
        getline(cin, input);

        // Validating and breaking loop if valid
        if (std::regex_match(input, regex)) {

            // Trying to create number, if numerator or denominator is too large it will throw an
            // exception
            try {
                rationalNumber = RationalNumber::RationalNumber(input);
                break;
            } catch (const out_of_range &e) {
                cout << endl << "That number had a numerator or denominator that is too large, "
                              "please enter a smaller value: ";
                // Restarting loop
                continue;
            } catch (...) {
                // Restarting loop
                cout << endl << "Something went wrong, please try entering another value: ";
                continue;
            }
        }

        cout << endl << "That is not a valid format for a rational number. Please use the "
                        "following formats: (-)#, or (-)#/(-)# with a denominator not equal to "
                        "zero." << endl;
        cout << "Enter rational number agan: ";

    }

    return rationalNumber;

}

int main() {

    while (true) {
        cout << endl << "RATIONAL NUMBER DRIVER / DEMO" << endl << endl;


        cout << "Rational Numbers must be entered in the following formats: (-)#, or (-)#/(-)# with a denominator not "
                "equal to zero." << endl << endl;
        cout << "FIRST NUMBER" << endl;

        RationalNumber::RationalNumber rationalNumber1 = getRationalNumberInput();

        cout << endl << "SECOND NUMBER" << endl;

        RationalNumber::RationalNumber rationalNumber2 = getRationalNumberInput();

        cout << endl << "DEMOING ARITHMETIC OPERATORS" << endl << endl;

        RationalNumber::RationalNumber result;

        // Demoing arithmetic operator overloads
        result = rationalNumber1 + rationalNumber2;
        cout << rationalNumber1 << " + " << rationalNumber2 << " = "
             << result << endl << endl;

        result = rationalNumber1 - rationalNumber2;
        cout << rationalNumber1 << " - " << rationalNumber2 << " = "
             << result << endl << endl;

        result = rationalNumber1 * rationalNumber2;
        cout << rationalNumber1 << " * " << rationalNumber2 << " = "
             << result << endl << endl;

        try {
            result = rationalNumber1 / rationalNumber2;
            cout << rationalNumber1 << " / " << rationalNumber2 << " = "
                 << result << endl << endl;
        } catch (const invalid_argument &e) {
            cout << "Error: cannot divide by zero." << endl << endl;
        } catch (...) {
            cout << "Error: something went wrong when dividing rational numbers." << endl << endl;
        }

        // boolalpha makes bools display as true/false instead of 1/0
        cout << "DEMOING COMPARISON OPERATORS" << boolalpha << endl << endl;

        // Demoing comparison operator overloads
        bool comparison = (rationalNumber1 > rationalNumber2);
        cout << rationalNumber1 << " > " << rationalNumber2 << " = "
             << comparison << endl << endl;

        comparison = (rationalNumber1 < rationalNumber2);
        cout << rationalNumber1 << " < " << rationalNumber2 << " = "
             << comparison << endl << endl;

        comparison = (rationalNumber1 == rationalNumber2);
        cout << rationalNumber1 << " == " << rationalNumber2 << " = "
             << comparison << endl << endl;


        cout << "Enter [Q] to quit, or any other input to restart: ";
        string input;
        getline(cin, input);
        if (input == "Q" || input == "q") {break;}

    }


    return 0;
}
