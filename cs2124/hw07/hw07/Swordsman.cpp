//
//  Swordsman.cpp
//  hw07
//
//  Created by Andrew Qu on 4/22/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include "Swordsman.h"
#include <ostream>
using namespace std;

namespace WarriorCraft{

Swordsman::Swordsman(const string& swordName, int str) : Warrior(swordName, str) {}
void Swordsman::doBattle() const {
    cout << "CLANG!  ";
    nameDropLord();
}

}
