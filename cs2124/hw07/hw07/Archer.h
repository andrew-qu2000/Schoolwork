//
//  Archer.h
//  hw07
//

#ifndef Archer_h
#define Archer_h
#include "Warrior.h"

namespace WarriorCraft{

class Archer : public Warrior {
public:
    Archer(const std::string& archName, int str);
    void doBattle() const override;
};

}
#endif /* Archer_h */
