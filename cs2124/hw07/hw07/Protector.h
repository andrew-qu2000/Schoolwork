//
//  Protector.h
//  hw07
//
//  Created by Andrew Qu on 4/22/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#ifndef Protector_h
#define Protector_h
#include "Lord.h"
#include <string>

namespace WarriorCraft{

class Protector {
public:
    Protector(const std::string& protectorName, int str);
    std::string getName() const;
    int getStrength() const;
    Lord* getEmployer() const;
    bool getIsDead() const;
    void setEmployer(Lord* hirer);
    virtual void doBattle() const;
    void adjustStrength(float ratio);
    bool runAway();
private:
    std::string name;
    int strength;
    Lord* employer;
    bool isDead;
    void makeDead();
};
    
}
#endif /* Protector_h */

