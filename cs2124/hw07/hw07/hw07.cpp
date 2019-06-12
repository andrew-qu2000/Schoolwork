//
//  hw07 - Inheritance in medieval fighting between Nobles and Protectors
//  Andrew Qu
//

#include <iostream>
#include <vector>
#include "Noble.h"
#include "Lord.h"
#include "PersonWithStrengthToFight.h"
#include "Protector.h"
#include "Wizard.h"
#include "Warrior.h"
#include "Archer.h"
#include "Swordsman.h"
using namespace std;
using namespace WarriorCraft;
/*
class Noble;
class Lord;
class PersonWithStrengthToFight;

class Protector {
public:
    Protector(const string& protectorName, int str) :
        name(protectorName),
        strength(str),
        employer(nullptr),
        isDead(false)
    {}
    string getName() const { return name; }
    int getStrength() const { return strength; }
    Lord* getEmployer() const { return employer; }
    bool getIsDead() const { return isDead; }
    void setEmployer(Lord* hirer) { employer = hirer; }
    virtual void doBattle() = 0;
    void adjustStrength(float ratio) {
        strength *= ratio;
        if (ratio == 0.0) {
            makeDead();
        }
    }
    bool runAway() {
        if (employer) {
            employer = nullptr;
            return true;
        }
        return false;
    }
private:
    string name;
    int strength;
    Lord* employer;
    bool isDead;
    void makeDead() { isDead = true; }
};

class Noble {
public:
    Noble(const string& nobleName) : name(nobleName), isDead(false) {}
    string getName() const { return name; }
    bool getIsDead() const { return isDead; }
    virtual int getStrength() const = 0;
    virtual void conductBattle() = 0;
    virtual void adjustStrengths(float ratio) = 0;
    void battle(Noble& opponent) {
        cout << name << " battles " << opponent.getName() << endl;
        if (isDead) {
            if (opponent.getIsDead()) {
                cout << "Oh NO! They're both dead! Yuck!\n";
            }
            else {
                cout << "He's dead, " << opponent.getName() << endl;
            }
        }
        else if (opponent.getIsDead()) {
            cout << "He's dead, " << name << endl;
        }
        else {
            float ourStrength = getStrength();
            float oppStrength = opponent.getStrength();
            conductBattle();
            opponent.conductBattle();
            if (ourStrength == oppStrength) {
                cout << "Mutual Annihilation: " << name << " and "
                << opponent.getName() << " die at each other's hands\n";
                adjustStrengths(0.0);
                makeDead();
                opponent.adjustStrengths(0.0);
                opponent.makeDead();
            }
            else if (ourStrength > oppStrength) {
                cout << name << " defeats " << opponent.getName() << endl;
                adjustStrengths(1.0 - oppStrength/ourStrength);
                opponent.adjustStrengths(0.0);
                opponent.makeDead();
            }
            else {
                cout << opponent.getName() << " defeats " << name << endl;
                adjustStrengths(0.0);
                makeDead();
                opponent.adjustStrengths(1 - ourStrength/oppStrength);
            }
        }
    }
private:
    string name;
    bool isDead;
    virtual void makeDead() { isDead = true; }
};

class Lord : public Noble {
public:
    Lord(const string& lordName) : Noble(lordName) {}
    int getStrength() const override {
        int armyTotal = 0;
        for(Protector* pPtr : army) {
            armyTotal += pPtr->getStrength();
        }
        return armyTotal;
    }
    void conductBattle() override {
        for(Protector* pPtr : army) {
            pPtr->doBattle();
        }
    }
    void adjustStrengths(float ratio) override {
        for(Protector* pPtr : army) {
            pPtr->adjustStrength(ratio);
        }
    }
    bool hires(Protector& hiree) {
        if (!hiree.getEmployer() && !hiree.getIsDead()) {
            hiree.setEmployer(this);
            army.push_back(&hiree);
            return true;
        }
        return false;
    }
    bool fire(Protector& firee) {
        if (removeProtector(&firee)) {
            cout << "You don't work for me anymore, " << firee.getName() << "!\n";
            return true;
        }
        return false;
    }
    void loseRunaway(Protector* runaway) {
        cout << runaway->getName() << " has fled Lord "
        << getName() << "!\n";
        removeProtector(runaway);
    }
private:
    vector<Protector*> army;
    bool removeProtector(Protector* pToRemove) {
        for (size_t i = 0;i < army.size();i ++) {
            if (army[i] == pToRemove) {
                for (size_t j = i;j < army.size() - 1;j ++) {
                    army[j] = army[j+1];
                }
                army.pop_back();
                return true;
            }
        }
        return false;
    }
};

class PersonWithStrengthToFight : public Noble {
public:
    PersonWithStrengthToFight(const string& pwstfName, int str) :
        Noble(pwstfName),
        strength(str)
    {}
    int getStrength() const override { return strength; }
    void conductBattle() override {
        cout << "UGH!!!\n";
    }
    void adjustStrengths(float ratio) override {
        strength *= ratio;
    }
private:
    int strength;
};



class Wizard : public Protector {
public:
    Wizard(const string& wizName, int str) : Protector(wizName, str) {}
    void doBattle() override {
        cout << "POOF" << endl;
    }
};

class Warrior : public Protector {
public:
    Warrior(const string& warName, int str) : Protector(warName, str) {}
    void nameDropLord() const {
        cout << getName() << " says: Take that in the name of my lord, "
        << getEmployer()->getName() << endl;
    }
};

class Archer : public Warrior {
public:
    Archer(const string& archName, int str) : Warrior(archName, str) {}
    void doBattle() override {
        cout << "TWANG!  ";
        nameDropLord();
    }
};

class Swordsman : public Warrior {
public:
    Swordsman(const string& swordName, int str) : Warrior(swordName, str) {}
    void doBattle() override {
        cout << "CLANG!  ";
        nameDropLord();
    }
};
*/
int main() {
    Lord sam("sam");
    Archer samantha("samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250);
    joe.battle(randy);
    joe.battle(sam);
    Lord janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);
    janet.hires(stout);
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);
    janet.battle(barclay);
    janet.hires(samantha);
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);
    sam.battle(barclay);
    joe.battle(barclay);
}
