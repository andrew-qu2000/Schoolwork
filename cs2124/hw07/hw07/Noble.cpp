//
//  Noble.cpp
//  hw07
//

#include <iostream>
#include "Noble.h"
#include "Protector.h"
using namespace std;

namespace WarriorCraft{
    
Noble::Noble(const string& nobleName) : name(nobleName), isDead(false) {}
string Noble::getName() const { return name; }
bool Noble::getIsDead() const {return isDead; }
void Noble::battle(Noble& opponent) {
    cout << name << " battles " << opponent.getName() << endl;
    if (isDead) {
        if (opponent.getIsDead()) {
            cout << "Oh NO! They're both dead! Yuck!\n";
        }
        else {
            cout << "He's dead, " << opponent.getName() << endl;
        }
    }
    else if (opponent.getIsDead()) {
        cout << "He's dead, " << name << endl;
    }
    else {
        float ourStrength = getStrength();
        float oppStrength = opponent.getStrength();
        conductBattle();
        opponent.conductBattle();
        if (ourStrength == oppStrength) {
            cout << "Mutual Annihilation: " << name << " and "
            << opponent.getName() << " die at each other's hands\n";
            adjustStrengths(0.0);
            makeDead();
            opponent.adjustStrengths(0.0);
            opponent.makeDead();
        }
        else if (ourStrength > oppStrength) {
            cout << name << " defeats " << opponent.getName() << endl;
            adjustStrengths(1.0 - oppStrength/ourStrength);
            opponent.adjustStrengths(0.0);
            opponent.makeDead();
        }
        else {
            cout << opponent.getName() << " defeats " << name << endl;
            adjustStrengths(0.0);
            makeDead();
            opponent.adjustStrengths(1 - ourStrength/oppStrength);
        }
    }
}
void Noble::makeDead() { isDead = true; }

}
