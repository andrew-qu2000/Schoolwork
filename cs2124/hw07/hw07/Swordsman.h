//
//  Swordsman.h
//  hw07
//
//  Created by Andrew Qu on 4/22/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#ifndef Swordsman_h
#define Swordsman_h
#include "Warrior.h"

namespace WarriorCraft{

class Swordsman : public Warrior {
public:
    Swordsman(const std::string& swordName, int str);
    void doBattle() const override;
};

}
#endif /* Swordsman_h */
