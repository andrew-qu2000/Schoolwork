//
//  Warrior.h
//  hw07
//


#ifndef Warrior_h
#define Warrior_h
#include "Protector.h"

namespace WarriorCraft{

class Warrior : public Protector {
public:
    Warrior(const std::string& warName, int str);
    void nameDropLord() const;
};

}
#endif /* Warrior_h */


