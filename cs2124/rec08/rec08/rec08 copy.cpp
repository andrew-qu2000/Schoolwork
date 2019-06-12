/*
	rec08 - Rational number class and overloading operators
	Andrew Qu 03/29/19
 */

#include <iostream>

// If time allows use  separate compilation, otherwise just define the class below
//#include "Rational.h"

using namespace std;

// If time allows after implementing separate compilation, then wrap the class in a namespace.
//using namespace CS2124;

class Rational{
    friend ostream& operator<<(ostream& os, const Rational& rat){
        os << rat.numer << "/" << rat.denom;
        return os;
    }
    friend istream& operator>>(istream& is, Rational& rat){
        char slant;
        is >> rat.numer >> slant >> rat.denom;
        rat.normalize();
        return is;
    }
    friend bool operator==(const Rational& left, const Rational& right);
    friend bool operator<(const Rational& left, const Rational& right);
private:
    int numer;
    int denom;
    //returns gcd of x and y
    int greatestCommonDivisor() {
        int absx = abs(numer);
        int absy = abs(denom);
        while (absy != 0) {
            int temp = absx % absy;
            absx = absy;
            absy = temp;
        }
        return absx;
    }
    //Reduces to simplest terms and removes neg. signs from denom.
    void normalize(){
        int gcd = greatestCommonDivisor();
        numer /= gcd; denom /= gcd;
        if(denom < 0){
            numer *= -1; denom *= -1;
        }
        
    }
public:
    Rational(int numer = 0, int denom = 1):numer(numer),denom(denom){
        normalize();
    }
    
    Rational& operator+=(const Rational& rat2){
        int newTop, newBot;
        newTop = numer * rat2.denom + denom * rat2.numer;
        newBot = denom * rat2.denom;
        numer = newTop; denom = newBot;
        normalize();
        return *this;
    }
    
    Rational& operator++(){
        numer += denom;
        return *this;
    }
    
    Rational operator++(int dummy){
        Rational ret(numer,denom);
        numer += denom;
        return ret;
    }
    
    explicit operator bool() const{
        return numer != 0;
    }
};

//Non-members and non-friends
Rational operator+(const Rational& left, const Rational& right);
bool operator==(const Rational& left, const Rational& right);
bool operator!=(const Rational& left, const Rational& right);
Rational& operator--(Rational& rat);
Rational operator--(Rational& rat, int dummy);
bool operator<=(Rational& left, Rational& right);
bool operator>(Rational& left, Rational& right);
bool operator>=(Rational& left, Rational& right);

int main() {
    Rational twoThirds(2,3);
    cout << twoThirds << endl;
    
    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    
    const Rational one = 1;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    cout << "one = " << one << endl;
    
    cout << "a += b: " << (a += b) << endl;	// Implement as member
    cout << "a = " << a << endl;
    
    // Implement as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    
    cout << "a == one: " << boolalpha << (a == one) << endl;
    
    // How does this manage to work?
    // It does NOT require writing another == operator. 
    cout << "1 == one: " << boolalpha << (1 == one) << endl;
    
    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;
    
    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;
    
    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;
    
    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing?
    //cout << "a-- -- = " << (a-- --) << endl;
    //cout << "a = " << a << endl;

    
    // Should report that 1 is true
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    } 

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    }
    //Test comparison operators
     Rational c(-1,4);
     Rational d(3);
     Rational e(3);
     cout << "c = " << c << endl;
     cout << "d = " << d << endl;
     cout << "e = " << e << endl;
     cout << "c < d: " << (c < d) << endl;
     cout << "d < c: " << (d < c) << endl;
     cout << "d > c: " << (d > c) << endl;
     cout << "d >= c: " << (d >= c) << endl;
     cout << "d >= e: " << (d >= e) << endl;
     cout << "d < e : " << (d < e) << endl;
    /*
     */
}

Rational operator+(const Rational& left, const Rational& right){
    Rational rat = left;
    return rat += right;
}

bool operator==(const Rational& left, const Rational& right){
    return (left.numer == right.numer && left.denom == right.denom);
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

bool operator<(const Rational& left, const Rational& right){
    return (left.numer * right.denom) < (right.numer * left.denom);
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
