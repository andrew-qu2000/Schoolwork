//
//  Noble.h
//  hw07
//


#ifndef Noble_h
#define Noble_h
#include <string>

namespace WarriorCraft{
    
class Noble {
public:
    Noble(const std::string& nobleName);
    std::string getName() const;
    bool getIsDead() const;
    virtual int getStrength() const;
    virtual void conductBattle() const;
    virtual void adjustStrengths(float ratio);
    void battle(Noble& opponent);
private:
    std::string name;
    bool isDead;
    virtual void makeDead();
};

}
#endif /* Noble_h */


