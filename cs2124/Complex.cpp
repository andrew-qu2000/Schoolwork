//
//  Complex.cpp
//  hw01
//
//  Created by Andrew Qu on 2/6/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//
#include <iostream>
#include <stdio.h>
using namespace std;

struct Complex
{
    double real; //members of a struct are by default public
    double imag;
    
};

void printComp(Complex C)
{
    cout << "r: " << C.real << "i: " << C.imag;
}

