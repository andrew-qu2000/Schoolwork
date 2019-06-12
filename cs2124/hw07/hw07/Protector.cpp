//
//  Protector.cpp
//  hw07
//

#include <ostream>
#include "Protector.h"
using namespace std;

namespace WarriorCraft{

Protector::Protector(const string& protectorName, int str) :
    name(protectorName),
    strength(str),
    employer(nullptr),
    isDead(false)
{}
string Protector::getName() const { return name; }
int Protector::getStrength() const { return strength; }
Lord* Protector::getEmployer() const { return employer; }
bool Protector::getIsDead() const { return isDead; }
void Protector::setEmployer(Lord* hirer) { employer = hirer; }
void Protector::adjustStrength(float ratio) {
    strength *= ratio;
    if (ratio == 0.0) {
        makeDead();
    }
}
bool Protector::runAway() {
    if (employer) {
        employer = nullptr;
        return true;
    }
    return false;
}
void Protector::makeDead() { isDead = true; }
    
}
