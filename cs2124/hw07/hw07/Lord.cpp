//
//  Lord.cpp
//  hw07
//
//  Created by Andrew Qu on 4/22/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include "Lord.h"
#include <ostream>
using namespace std;

namespace WarriorCraft{
    
Lord::Lord(const string& lordName) : Noble(lordName) {}
int Lord::getStrength() const {
    int armyTotal = 0;
    for(Protector* pPtr : army) {
        armyTotal += pPtr->getStrength();
    }
    return armyTotal;
}
void Lord::conductBattle() const{
    for(Protector* pPtr : army) {
        pPtr->doBattle();
    }
}
void Lord::adjustStrengths(float ratio) {
    for(Protector* pPtr : army) {
        pPtr->adjustStrength(ratio);
    }
}
bool Lord::hires(Protector& hiree) {
    if (!hiree.getEmployer() && !hiree.getIsDead()) {
        hiree.setEmployer(this);
        army.push_back(&hiree);
        return true;
    }
    return false;
}
bool Lord::fire(Protector& firee) {
    if (removeProtector(&firee)) {
        cout << "You don't work for me anymore, " << firee.getName() << "!\n";
        return true;
    }
    return false;
}
void Lord::loseRunaway(Protector* runaway) {
    cout << runaway->getName() << " has fled Lord "
    << getName() << "!\n";
    removeProtector(runaway);
}
bool Lord::removeProtector(Protector* pToRemove) {
    for (size_t i = 0;i < army.size();i ++) {
        if (army[i] == pToRemove) {
            for (size_t j = i;j < army.size() - 1;j ++) {
                army[j] = army[j+1];
            }
            army.pop_back();
            return true;
        }
    }
    return false;
}

}
