//
//  Rational.cpp
//  rec08
//
//  Created by Andrew Qu on 3/29/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include <iostream>
#include "Rational.h"
using namespace std;

namespace CS2124{
    
//---private members---
int Rational::greatestCommonDivisor(){
    int absx = abs(numer);
    int absy = abs(denom);
    while (absy != 0) {
        int temp = absx % absy;
        absx = absy;
        absy = temp;
    }
    return absx;
}

void Rational::normalize(){
    int gcd = greatestCommonDivisor();
    numer /= gcd; denom /= gcd;
    if(denom < 0){
        numer *= -1; denom *= -1;
    }
}
//---public members---
Rational::Rational(int top, int bot):numer(top),denom(bot){
    Rational::normalize();
}

Rational& Rational::operator+=(const Rational& rat2){
    int newTop, newBot;
    newTop = numer * rat2.denom + denom * rat2.numer;
    newBot = denom * rat2.denom;
    numer = newTop; denom = newBot;
    normalize();
    return *this;
}

Rational& Rational::operator++(){
    numer += denom;
    return *this;
}

Rational Rational::operator++(int dummy){
    Rational ret(numer,denom);
    numer += denom;
    return ret;
}

Rational::operator bool() const{
    return numer != 0;
}

ostream& operator<<(ostream& os, const Rational& rat){
    os << rat.numer << "/" << rat.denom;
    return os;
}

istream& operator>>(istream& is, Rational& rat){
    char slant;
    is >> rat.numer >> slant >> rat.denom;
    rat.normalize();
    return is;
}

bool operator==(const Rational& left, const Rational& right){
    return (left.numer == right.numer && left.denom == right.denom);
}

bool operator<(const Rational& left, const Rational& right){
    return (left.numer * right.denom) < (right.numer * left.denom);
}
//---non member functions---
Rational operator+(const Rational& left, const Rational& right){
    Rational rat = left;
    return rat += right;
}
    
bool operator!=(const Rational& left, const Rational& right){
    return !(left == right);
}
    
Rational& operator--(Rational& rat){
    rat += -1;
    return rat;
}
    
Rational operator--(Rational& rat, int dummy){
    Rational ret(rat);
    rat += -1;
    return ret;
}
    
bool operator<=(Rational& left, Rational& right){
    return !(left > right);
}
    
bool operator>(Rational& left, Rational& right){
    return right < left;
}
    
bool operator>=(Rational& left, Rational& right){
    return !(left < right);
}

} //end namespace
