//
//  Lord.h
//  hw07
//


#ifndef Lord_h
#define Lord_h
#include "Noble.h"
#include "Protector.h"
#include <vector>

namespace WarriorCraft{
    
class Lord : public Noble {
public:
    Lord(const std::string& lordName);
    int getStrength() const override;
    void conductBattle() const override;
    void adjustStrengths(float ratio) override;
    bool hires(Protector& hiree);
    bool fire(Protector& firee);
    void loseRunaway(Protector* runaway);
private:
    std::vector<Protector*> army;
    bool removeProtector(Protector* pToRemove);
};

}
#endif /* Lord_h */

