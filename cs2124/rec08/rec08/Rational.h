//
//  Rational.h
//  rec08
//
//  Created by Andrew Qu on 3/29/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#ifndef Rational_h
#define Rational_h
#include <iostream>

namespace CS2124 {
    
class Rational{
    friend std::ostream& operator<<(std::ostream& os, const Rational& rat);
    friend std::istream& operator>>(std::istream& is, Rational& rat);
    friend bool operator==(const Rational& left, const Rational& right);
    friend bool operator<(const Rational& left, const Rational& right);
private:
    int numer;
    int denom;
    //returns gcd of x and y
    int greatestCommonDivisor();
    //Reduces to simplest terms and removes neg. signs from denom.
    void normalize();
public:
    Rational(int top = 0, int bot = 1);
    
    Rational& operator+=(const Rational& rat2);
    
    Rational& operator++();
    
    Rational operator++(int dummy);
    
    explicit operator bool() const;
};
//---non member functions---
Rational operator+(const Rational& left, const Rational& right);
bool operator!=(const Rational& left, const Rational& right);
Rational& operator--(Rational& rat);
Rational operator--(Rational& rat, int dummy);
bool operator<=(Rational& left, Rational& right);
bool operator>(Rational& left, Rational& right);
bool operator>=(Rational& left, Rational& right);
    
} //end namespace
#endif /* Rational_h */
