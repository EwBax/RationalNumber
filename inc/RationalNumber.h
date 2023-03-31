//
// Created by ewanb on 2023-03-29.
//

#ifndef RATIONALNUMBER_RATIONALNUMBER_H
#define RATIONALNUMBER_RATIONALNUMBER_H

#include <string>

namespace RationalNumber {

    class RationalNumber {

    private:
        int numerator;
        int denominator;

    public:
        // Constructors
        RationalNumber();

        explicit RationalNumber(int n);

        explicit RationalNumber(int n, int d);

        explicit RationalNumber(const std::string &rationalNumber);
        RationalNumber(const RationalNumber &rationalNumber);

        // Function to normalize the number
        void normalize();

        // Accessors
        int getNumerator() {return numerator;};
        int getDenominator() {return denominator;};

        // Mutators
        void setNumerator(int n) {numerator = n;}
        void setDenominator(int d) {denominator = d;}

        // operator override functions
        RationalNumber& operator= (RationalNumber const &rationalNumber);

        friend RationalNumber operator+(const RationalNumber &leftNum,
                const RationalNumber &rightNum);

        friend RationalNumber operator-(const RationalNumber &leftNum,
                const RationalNumber &rightNum);

        friend RationalNumber operator/(const RationalNumber &leftNum,
                const RationalNumber &rightNum);

        friend RationalNumber operator*(const RationalNumber &leftNum,
                const RationalNumber &rightNum);

        friend bool operator>(const RationalNumber &leftNum,
                const RationalNumber &rightNum);

        friend bool operator<(const RationalNumber &leftNum,
                const RationalNumber &rightNum);

        friend bool operator==(const RationalNumber &leftNum,
                const RationalNumber &rightNum);

        friend std::ostream& operator<< (std::ostream &output, const RationalNumber &rationalNumber);

    };


    // using non-member functions to take in two arguments
    // This would make it possible to implement using arithmetic or comparison operators with an int
    // and RationalNumber
    RationalNumber operator+(const RationalNumber &leftNum,
            const RationalNumber&rightNum);
    RationalNumber operator-(const RationalNumber &leftNum,
            const RationalNumber &rightNum);
    RationalNumber operator/(const RationalNumber &leftNum,
            const RationalNumber &rightNum);
    bool operator>(const RationalNumber &leftNum,
            const RationalNumber &rightNum);
    bool operator<(const RationalNumber &leftNum,
            const RationalNumber &rightNum);
    bool operator==(const RationalNumber &leftNum,
            const RationalNumber &rightNum);
    std::ostream& operator<< (std::ostream &output, const RationalNumber &rationalNumber);

} // RationalNumber

#endif //RATIONALNUMBER_RATIONALNUMBER_H
