//
//  Archer.cpp
//  hw07
//
//  Created by Andrew Qu on 4/22/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include "Archer.h"
#include <ostream>
using namespace std;

namespace WarriorCraft{

Archer::Archer(const string& archName, int str) : Warrior(archName, str) {}
void Archer::doBattle() const {
    cout << "TWANG!  ";
    nameDropLord();
}

}
