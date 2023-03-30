//
// Created by ewanb on 2023-03-29.
//

#include <regex>
#include <iostream>
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

        std::cout << "Copy RationalNumber constructor fired." << std::endl;

        this->numerator = rationalNumber.numerator;
        this->denominator = rationalNumber.denominator;
    }


    //==============================================================================================
    //==================================FUNCTIONS===================================================
    //==============================================================================================

    // Normalizes and simplifies the rational number
    void RationalNumber::normalize() {

        if (numerator == 0) {
            denominator = 1;
            return;
        }

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

        for (int i = lowerNumber; i > 1; i--) {
            if (denominator % i == 0 && numerator % i == 0) {
                denominator /= i;
                numerator   /= i;
                break;
            }
        }

    }

    //==============================================================================================
    //===============================OPERATOR OVERRIDES=============================================
    //==============================================================================================


    RationalNumber &RationalNumber::operator=(RationalNumber const &rationalNumber) {

        std::cout << "RationalNumber '=' overload fired." << std::endl;

        // Calling swap function to swap values
        this->numerator = rationalNumber.numerator;
        this->denominator = rationalNumber.denominator;

        return *this;
    }


    RationalNumber operator+(const RationalNumber &leftNum,
            const RationalNumber &rightNum) {

        std::cout << "RationalNumber '+' overload fired." << std::endl;

        RationalNumber result((leftNum.numerator * rightNum.denominator) + (rightNum.numerator *
                leftNum.denominator));
        result.denominator = leftNum.denominator * rightNum.denominator;

        result.normalize();

        return result;

    }


    RationalNumber operator-(const RationalNumber &leftNum,
            const RationalNumber &rightNum) {

        std::cout << "RationalNumber '-' overload fired." << std::endl;

        RationalNumber result(
                (leftNum.numerator * rightNum.denominator) - (rightNum.numerator *leftNum.denominator),
                leftNum.denominator * rightNum.denominator);

        result.normalize();

        return result;

    }

    RationalNumber operator/(const RationalNumber &leftNum, const RationalNumber &rightNum) {

        std::cout << "RationalNumber '/' overload fired." << std::endl;

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

        RationalNumber result(leftNum.numerator * rightNum.numerator,
                              leftNum.denominator * rightNum.denominator);

        result.normalize();

        return result;

    }

    std::ostream &operator<<(std::ostream &output, const RationalNumber &rationalNumber) {
        output << rationalNumber.numerator << "/" << rationalNumber.denominator;
        return output;
    }

} // RationalNumber