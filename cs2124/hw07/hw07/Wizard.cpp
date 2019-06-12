//
//  Wizard.cpp
//  hw07
//
//  Created by Andrew Qu on 4/22/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include "Wizard.h"
#include <ostream>
using namespace std;

namespace WarriorCraft{

Wizard::Wizard(const string& wizName, int str) : Protector(wizName, str) {}
void Wizard::doBattle() const {
    cout << "POOF" << endl;
}

}
