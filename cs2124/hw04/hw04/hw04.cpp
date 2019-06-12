//
//  hw04.cpp
//  hw04 - Simulation of medieval nobles battling with armies
//
//  Created by Andrew Qu on 2/27/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
using namespace std;

class Noble;

class Warrior{
    
    friend ostream& operator<<(ostream& os, const Warrior& warrior);
    
private:
    string name;
    int strength;
    Noble* employer = nullptr;
    
public:
    Warrior(string warName, int warStr):name(warName), strength(warStr){}
    //accessors
    string getName() const{
        return name;
    }
    
    int getStrength() const{
        return strength;
    }
    
    bool isHired() const{
        return employer != nullptr;
    }
    //mutators
    void setStrength(const double ratio){
        strength *= (1 - ratio);
    }
    
    void setEmployer(Noble* noble){
        employer = noble;
    }

};

class Noble{
    
private:
    string name;
    vector<Warrior*> army;
    bool isDead;
    //returns cumulative strength of army
    const int getStrength(){
        int totStr = 0;
        for(Warrior*& w : army){
            totStr += w->getStrength();
        }
        return totStr;
    }
    //removes Warrior* for a fired Warrior from army
    void removeWarrior(Warrior& warrior){
        for(size_t i = 0;i < army.size();i ++){
            if(army[i] == &warrior){
                //shift elements on right side of warrior one space
                //to the left
                for(size_t j = i;j < army.size() - 1;j ++){
                    army[j] = army[j+1];
                }
                army.pop_back();
                return;
            }
        }
    }
    
public:
    Noble(string nobName):name(nobName), isDead(false){} //alive when created
    //accessors
    string getName() const{
        return name;
    }
    
    bool getIsDead() const{
        return isDead;
    }
    //mutator(s)
    void makeDead(){ //makeAlive() need not exist
        isDead = true;
    }
    //shows size and strengths of army
    void display() const{
        cout << getName() << " has an army of " << army.size() << endl;
        for(Warrior* w : army){
            cout << *w;
        }
    }
    //adds a Warrior to army
    //returns true if successful, false otherwise
    bool hire(Warrior& hiree){
        if(isDead){ //can't hire if you're dead
            return false;
        }
        else if(hiree.isHired()){ //can't hire someone already hired
            return false;
        }
        hiree.setEmployer(this);
        army.push_back(&hiree);
        return true;
    }
    //removes a Warrior from army
    //returns true if successful, false otherwise
    bool fire(Warrior& firee){
        if(isDead){
            return false;
        }
        for(size_t i = 0;i < army.size();i ++){
            if(army[i] == &firee){
                cout << firee.getName() << ", you're fired! -- "
                << getName() << endl;
                firee.setEmployer(nullptr);
                removeWarrior(firee);
                return true;
            }
        }
        return false;
    }
    //multiplies all warriors' strengths by a ratio
    void setArmyStrength(double ratio){
        for(Warrior*& w : army){
            w->setStrength(ratio);
        }
    }
    //declare winner of a battle, adjusts army strengths
    void defeat(Noble& loser, double ratio){
        cout << getName() << " defeats " << loser.getName() << endl;
        loser.makeDead();
        setArmyStrength(ratio);
        loser.setArmyStrength(1); //all strength is lost
    }
    //battle two nobles, handle special cases
    void battle(Noble& opp){
        cout << getName() <<" battles " << opp.getName() << endl;
        if(getIsDead()){
            if(opp.getIsDead()){
                cout << "Oh, NO! They're both dead! Yuck!" << endl;
            }
            else{
                cout << "He's dead, " << opp.getName() << endl;
            }
        }
        else if(opp.getIsDead()){
            cout << "He's dead, " << getName() << endl;
        }
        else{ //both nobles are alive
            double nobleStrength = getStrength();
            double oppStrength = opp.getStrength();
            double ratio = oppStrength/nobleStrength;
            if(ratio == 1.0){
                cout << "Mutual Annihilation: " << getName() << " and "
                << opp.getName() << " die at each other's hands" << endl;
                makeDead();
                opp.makeDead();
                setArmyStrength(1);
                opp.setArmyStrength(1);
            }
            else if(ratio < 1.0){
                defeat(opp,ratio);
            }
            else{
                opp.defeat(*this, ratio);
            }
        }
    }
};

ostream& operator<<(ostream& os, const Warrior& warrior){
    os << "        " << warrior.name << ": " << warrior.strength << endl;
    return os;
}

int main(){
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
    
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
    
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();
    
    art.fire(cheetah);
    art.display();
    
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
    
    
    // NEW OUTPUT CODE
    cout << "==========\n"
    << "Status after all battles, etc.\n";
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();
    
}
