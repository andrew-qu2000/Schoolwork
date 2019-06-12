//
//  PersonWithStrengthToFight.cpp
//  hw07
//
//  Created by Andrew Qu on 4/22/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//
#include "PersonWithStrengthToFight.h"
#include <ostream>
using namespace std;

namespace WarriorCraft{

PersonWithStrengthToFight::PersonWithStrengthToFight(const string& pwstfName, int str) :
    Noble(pwstfName),
    strength(str)
{}
int PersonWithStrengthToFight::getStrength() const { return strength; }
void PersonWithStrengthToFight::conductBattle() const {
    cout << "UGH!!!\n";
}
void PersonWithStrengthToFight::adjustStrengths(float ratio) override {
    strength *= ratio;
}

}
