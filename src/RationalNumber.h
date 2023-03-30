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
        RationalNumber() : numerator(0), denominator(1) {};

        explicit RationalNumber(const int n) : numerator(n), denominator(1) {};

        explicit RationalNumber(const int n, const int d) :
        numerator(n),denominator(d) {};

        explicit RationalNumber(const std::string &rationalNumber);
        RationalNumber(const RationalNumber &rationalNumber);

        // Function to normalize the number
        void normalize();


        static void findCommonDenominator(RationalNumber &num1, RationalNumber &num2);


        // Accessors
        int getNumerator() {return numerator;};
        int getDenominator() {return denominator;};

        // Mutators
        void setNumerator(int n) {numerator = n;}
        void setDenominator(int d) {denominator = d;}

        // operator override functions
        RationalNumber& operator= (RationalNumber const &rationalNumber);
        RationalNumber& operator+ (RationalNumber rationalNumber);
        RationalNumber& operator- (RationalNumber rationalNumber);
        RationalNumber& operator/ (RationalNumber rationalNumber);
        RationalNumber& operator* (RationalNumber rationalNumber);
        RationalNumber& operator> (RationalNumber rationalNumber);
        RationalNumber& operator< (RationalNumber rationalNumber);
        RationalNumber& operator== (RationalNumber rationalNumber);
        friend std::ostream& operator<< (std::ostream &output, const RationalNumber &student);

    };


    std::ostream& operator<< (std::ostream &output, const RationalNumber &rationalNumber);

} // RationalNumber

#endif //RATIONALNUMBER_RATIONALNUMBER_H
