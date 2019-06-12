//
//  Warrior.cpp
//  hw07
//

#include "Warrior.h"
#include <ostream>
using namespace std;

namespace WarriorCraft{

Warrior::Warrior(const string& warName, int str) : Protector(warName, str) {}
void Warrior::nameDropLord() const {
    cout << getName() << " says: Take that in the name of my lord, "
    << getEmployer()->getName() << endl;
}

}
