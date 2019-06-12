//
//  weather.cpp
//  hw01
//
//  Created by Andrew Qu on 2/11/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//const bool DEBUG = true;
const double ZERO_F = 32.0;
constexpr double C_TO_F_RATIO = 5.0/9.0;

class Reading
{
public:
    Reading(double temp) : tempF(temp){}
    double get_tempF() const {return tempF;}
    double get_tempC() const
    {
        return (tempF - ZERO_F) * C_TO_F_RATIO;
    }
    
private:
    double tempF;
};

ostream& operator<<(ostream& os, const Reading& r)
{
    os << "Weather reading: " << r.get_tempF() << 'F' << endl;
}

int main()
{
    double temp;
    Reading rd{temp};
}
