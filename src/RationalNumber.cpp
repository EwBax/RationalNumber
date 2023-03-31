//
// Created by ewanb on 2023-03-29.
//

#include <regex>
#include <iostream>
#include <numeric>

#include "../inc/RationalNumber.h"

namespace RationalNumber {

    //==============================================================================================
    //====================================CONSTRUCTORS==============================================
    //==============================================================================================

    // Default constructor
    RationalNumber::RationalNumber()  : numerator(0), denominator(1) {
        std::cout << "Default RationalNumber constructor fired." << std::endl;
    }

    // Single integer constructor
    RationalNumber::RationalNumber(const int n) : numerator(n), denominator(1) {
        std::cout << "Single integer RationalNumber constructor fired." << std::endl;
    }

    // Double integer constructor
    RationalNumber::RationalNumber(int n, int d) : numerator(n),denominator(d) {
        std::cout << "Double integer RationalNumber constructor fired." << std::endl;
    }


    // Constructor to parse a string
    RationalNumber::RationalNumber(const std::string &rationalNumber) {

        std::cout << "String RationalNumber constructor fired." << std::endl;

        // Regex for matching input format ^-?\d+(\/-?[1-9]\d*)?$
        std::regex regex(R"(^-?\d+(\/-?0*[1-9](\d+)?)?$)");

        // Throwing exception if the string input is invalid
        if (!std::regex_match(rationalNumber, regex)) {
            throw std::invalid_argument("Invalid string format creating RationalNumber, "
                                        "std::invalid_argument thrown.");
        }

        // Code from https://stackoverflow.com/questions/9435385/split-a-string-using-c11
        regex = std::regex("/");
        std::sregex_token_iterator iterator{rationalNumber.begin(), rationalNumber.end(), regex, -1};
        std::vector<std::string> split{iterator, {}};

        // Handling potential exception if number is too big for an int
        try {
            numerator = std::stoi(split.at(0));
            if (rationalNumber.find('/') != std::string::npos) {
                denominator = std::stoi(split.at(1));
            } else {
                denominator = 1;
            }
        } catch (const std::out_of_range &e) {
            throw std::out_of_range("Number too large for RationalNumber, std::out_of_range "
                                    "thrown.");
        } catch (const std::exception &e) {
            throw e;
        }

        normalize();

    }

    // Copy constructor
    RationalNumber::RationalNumber(const RationalNumber &rationalNumber) {

        std::cout << "Copy RationalNumber constructor fired." << std::endl;

        this->numerator = rationalNumber.numerator;
        this->denominator = rationalNumber.denominator;
    }


    //==============================================================================================
    //==================================FUNCTIONS===================================================
    //==============================================================================================

    // Normalizes and simplifies the rational number
    void RationalNumber::normalize() {

        // Checking for zero
        if (numerator == 0) {
            denominator = 1;
            return;
        }

        // Normalizing negatives
        if (denominator < 0) {
                denominator *= -1;
                numerator *= -1;
        }

        int gcd = std::gcd(numerator, denominator);
        denominator /= gcd;
        numerator /= gcd;

    }

    //==============================================================================================
    //===============================OPERATOR OVERRIDES=============================================
    //==============================================================================================


    RationalNumber &RationalNumber::operator=(RationalNumber const &rationalNumber) {

        std::cout << "RationalNumber '=' overload fired." << std::endl;

        this->numerator = rationalNumber.numerator;
        this->denominator = rationalNumber.denominator;

        return *this;
    }


    RationalNumber operator+(const RationalNumber &leftNum, const RationalNumber &rightNum) {

        std::cout << "RationalNumber '+' overload fired." << std::endl;

        // Using single int argument operator
        // Finding common multiple denominator and adding numerators together
        RationalNumber result((leftNum.numerator * rightNum.denominator) + (rightNum.numerator *
                leftNum.denominator));
        result.denominator = leftNum.denominator * rightNum.denominator;

        result.normalize();

        return result;

    }


    RationalNumber operator-(const RationalNumber &leftNum, const RationalNumber &rightNum) {

        std::cout << "RationalNumber '-' overload fired." << std::endl;

        // Using double int argument operator
        // Finding common multiple denominator and difference of numerators
        RationalNumber result(
                (leftNum.numerator * rightNum.denominator) - (rightNum.numerator *leftNum.denominator),
                leftNum.denominator * rightNum.denominator);

        result.normalize();

        return result;

    }


    RationalNumber operator/(const RationalNumber &leftNum, const RationalNumber &rightNum) {

        std::cout << "RationalNumber '/' overload fired." << std::endl;

        // Checking for dividing by zero
        if (rightNum.numerator == 0) {
            throw std::invalid_argument("Dividing by zero");
        }

        // Flipping right number
        RationalNumber result(rightNum.denominator, rightNum.numerator);

        // Multiplying numbers
        result.numerator *= leftNum.numerator;
        result.denominator *= leftNum.denominator;

        result.normalize();

        return result;

    }

    RationalNumber operator*(const RationalNumber &leftNum, const RationalNumber &rightNum) {

        std::cout << "RationalNumber '*' overload fired." << std::endl;

        // Multiplying numbers in double int constructor
        RationalNumber result(leftNum.numerator * rightNum.numerator,
                              leftNum.denominator * rightNum.denominator);

        result.normalize();

        return result;

    }

    // Comparison operators

    bool operator>(const RationalNumber &leftNum, const RationalNumber &rightNum) {

        std::cout << "RationalNumber '>' overload fired." << std::endl;

        // A/B > C/D if A*D > C*B
        return (leftNum.numerator * rightNum.denominator) > (rightNum.numerator * leftNum
            .denominator);
    }


    bool operator<(const RationalNumber &leftNum, const RationalNumber &rightNum) {

        std::cout << "RationalNumber '<' overload fired." << std::endl;

        // A/B <>> C/D if A*D < C*B
        return (leftNum.numerator * rightNum.denominator) < (rightNum.numerator * leftNum
            .denominator);
    }


    bool operator==(const RationalNumber &leftNum, const RationalNumber &rightNum) {

        std::cout << "RationalNumber '==' overload fired." << std::endl;

        // A/B == C/D if A*D == C*B
        return (leftNum.numerator * rightNum.denominator) == (rightNum.numerator * leftNum
            .denominator);
    }


    // Output operator overload
    std::ostream &operator<<(std::ostream &output, const RationalNumber &rationalNumber) {
        output << rationalNumber.numerator << (rationalNumber.denominator == 1 ? "" : "/" + std::to_string(rationalNumber.denominator));
        return output;
    }

} // RationalNumber