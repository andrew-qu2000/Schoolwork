/*
	rec08 - Rational number class and overloading operators
	Andrew Qu 03/29/19
 */

#include <iostream>
// If time allows use  separate compilation, otherwise just define the class below
#include "Rational.h"

using namespace std;

// If time allows after implementing separate compilation, then wrap the class in a namespace.
using namespace CS2124;

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
}
