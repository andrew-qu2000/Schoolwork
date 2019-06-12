//
//  PersonWithStrengthToFight.h
//  hw07
//

#ifndef PersonWithStrengthToFight_h
#define PersonWithStrengthToFight_h
#include "Noble.h"

namespace WarriorCraft{

class PersonWithStrengthToFight : public Noble {
public:
    PersonWithStrengthToFight(const std::string& pwstfName, int str);
    int getStrength() const override;
    void conductBattle() const override;
    void adjustStrengths(float ratio) override;
private:
    int strength;
};

}
#endif /* PersonWithStrengthToFight_h */
