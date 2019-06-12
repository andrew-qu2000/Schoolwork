//
//  Wizard.h
//  hw07
//
//  Created by Andrew Qu on 4/22/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#ifndef Wizard_h
#define Wizard_h
#include "Protector.h"

namespace WarriorCraft{

class Wizard : public Protector {
public:
    Wizard(const std::string& wizName, int str);
    void doBattle() const override;
};

#endif /* Wizard_h */

}
