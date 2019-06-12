//
//  hw03.cpp
//  hw03 - Medieval fighting simulator with warriors and weapons
//
//  Created by Andrew Qu on 2/17/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
using namespace std;

class Warrior
{
    friend ostream& operator<<(ostream& os, const Warrior& warrior);
private:
    string name;
    class Weapon
    {
        friend ostream& operator<<(ostream& os, const Weapon& weapon)
        {
            os << "weapon: " << weapon.name << ", " << weapon.strength;
            return os;
        }
    public:
        Weapon(string wepName, int wepStr):
        name(wepName),
        strength(wepStr)
        {}
        //accessors
        string getName()
        {
            return name;
        }
        
        int getStrength()
        {
            return strength;
        }
        //mutator(s)
        void setStrength(int newStrength)
        {
            strength = newStrength;
        }
        
    private:
        string name;
        int strength;
    };
    Weapon weapon;
    
public:
    Warrior(string warName, string wepName, int wepStr):
    name(warName),
    weapon(Weapon{wepName, wepStr})
    {}
    //accessors
    string getName()
    {
        return name;
    }
    
    string getWepName()
    {
        return weapon.getName();
    }
    
    int getStrength()
    {
        return weapon.getStrength();
    }
    //mutator(s)
    void setStrength(int newStrength)
    {
        weapon.setStrength(newStrength);
    }
    //defeat another warrior and adjust strengths
    void defeat(Warrior& opp)
    {
        cout << getName() << " defeats " << opp.getName() << endl;
        setStrength(getStrength() - opp.getStrength());
        opp.setStrength(0);
    }
    //engage in battle with another warrior
    //handle special cases
    void battle(Warrior& opp)
    {
        cout << getName() << " battles " << opp.getName() << endl;
        if(getStrength() == 0)
        {
            if(opp.getStrength() == 0) //both warriors are dead
            {
                cout << "Oh NO! They're both dead! Yuck!" << endl;
            }
            else //only this warrior is dead
            {
                cout << "He's dead, " << opp.getName() << endl;
            }
        }
        else if(opp.getStrength() == 0) //only opponent is dead
        {
            cout << "He's dead, " << getName() << endl;
        }
        else
        {
            if(getStrength() == opp.getStrength())
            {
                cout << "Mutual Annihilation: " << getName() << " and "
                << opp.getName() << " die at each other's hands" << endl;
                setStrength(0);
                opp.setStrength(0);
            }
            else if(getStrength() < opp.getStrength())
            {
                opp.defeat(*this);
            }
            else
            {
                defeat(opp);
            }
        }
    }
    
};

//overloaded operator<< for Warriors
ostream& operator<<(ostream& os, const Warrior& warrior)
{
    os << "Warrior: " << warrior.name << ", " << warrior.weapon << endl;
    return os;
}

//prints existing warriors and their weapons
void status(vector<Warrior*>& warriors);

//returns pointer to the warrior with specified name
Warrior* findWarrior(vector<Warrior*>& warriors, string warName);

//executes commands from text file (warrior creation, battling, statuses)
void runSequence(vector<Warrior*>& warriors, ifstream& sequence);

int main()
{
    vector<Warrior*> warriors;
    ifstream battleLog("warriors.txt");
    if(!battleLog)
    {
        cout << "Failed to open warriors.txt";
        exit(1);
    }
    runSequence(warriors, battleLog);
    battleLog.close();
}

void status(vector<Warrior*>& warriors)
{
    cout << "There are " << warriors.size() << " warriors:" << endl;
    for(Warrior* w : warriors)
    {
        cout << *w;
    }
}

Warrior* findWarrior(vector<Warrior*>& warriors, string warName)
{
    for(Warrior*& w : warriors)
    {
        if(w->getName() == warName)
        {
            return w;
        }
    }
    return warriors[0];
}

void runSequence(vector<Warrior*>& warriors, ifstream& sequence)
{
    string line;
    string warName;
    string wepName;
    int wepStr;
    Warrior* fighterA;
    Warrior* fighterB;
    while(sequence >> line)
    {
        if(line == "Warrior") //creates a new warrior
        {
            sequence >> warName >> wepName >> wepStr;
            Warrior* newWar = new Warrior{warName,wepName,wepStr};
            warriors.push_back(newWar);
        }
        else if(line == "Status") //gives status
        {
            status(warriors);
        }
        else //battles two warriors
        {
            sequence >> warName;
            fighterA = findWarrior(warriors, warName);
            sequence >> warName;
            fighterB = findWarrior(warriors, warName);
            fighterA->battle(*fighterB);
        }
    }
}
