//
// Created by ewanb on 2023-03-29.
//

#include <regex>
#include <iostream>
#include "RationalNumber.h"

namespace RationalNumber {

    //==============================================================================================
    //====================================CONSTRUCTORS==============================================
    //==============================================================================================

    // Constructor to parse a string
    RationalNumber::RationalNumber(const std::string &rationalNumber) {

        // Regex for matching input format ^-?\d+(\/-?\d+)?$
        std::regex regex(R"(^-?\d+(\/-?\d+)?$)");

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
            denominator = std::stoi(split.at(1));
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
        this->numerator = rationalNumber.numerator;
        this->denominator = rationalNumber.denominator;
    }


    //==============================================================================================
    //==================================FUNCTIONS===================================================
    //==============================================================================================

    // Normalizes and simplifies the rational number
    void RationalNumber::normalize() {

        // Normalizing negatives
        if (denominator < 0) {
                denominator *= -1;
                numerator *= -1;
        }

        int lowerNumber;

        // Getting the absolute value of the numerator
        numerator < 0 ? lowerNumber = numerator * -1 : lowerNumber = numerator;

        if (lowerNumber > denominator) {
            lowerNumber = denominator;
        }

        for (int i = lowerNumber; i > 0; i--) {
            if (denominator % i == 0 && numerator % i == 0) {
                denominator /= i;
                numerator   /= i;
                break;
            }
        }

    }


    // Modifies two rational numbers to have a common denominator, leaves them not normalized
    void RationalNumber::findCommonDenominator(RationalNumber &num1, RationalNumber &num2) {

        double d1 = num1.denominator;
        double d2 = num2.denominator;

        num1.numerator *= d2;
        num1.denominator *= d2;
        num2.numerator *= d1;
        num2.denominator *= d1;

    }

    //==============================================================================================
    //===============================OPERATOR OVERRIDES=============================================
    //==============================================================================================


    RationalNumber &RationalNumber::operator=(RationalNumber const &rationalNumber) {
        // Calling swap function to swap values
        this->numerator = rationalNumber.numerator;
        this->denominator = rationalNumber.denominator;

        return *this;
    }


    RationalNumber &RationalNumber::operator+(RationalNumber rationalNumber) {

        // Finding common denominator
        findCommonDenominator(*this, rationalNumber);

        this->numerator += rationalNumber.numerator;

        this->normalize();

        return *this;

    }


    RationalNumber &RationalNumber::operator-(RationalNumber rationalNumber) {

        findCommonDenominator(*this, rationalNumber);

        this->numerator -= rationalNumber.numerator;

        this->normalize();

        return *this;
    }


} // RationalNumber