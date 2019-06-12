//
//  hw03.cpp
//  hw03 - Medieval fighting simulator with warriors and weapons
//
//  Created by Andrew Qu on 2/17/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//
/*
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
using namespace std;

class Warrior
{
private:
    string name;
    class Weapon
    {
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
};

//Prints existing warriors and their weapons
void status(vector<Warrior>& warriors);

//Executes commands of inputted text file
//eg. warrior creation, battling, status printing
void runSequence(vector<Warrior>& warriors, ifstream& sequence);

//Battles two warriors and handles special cases, adjusts strengths
void battle(Warrior& warA, Warrior& warB);

//Battles two warriors when one will win, adjusts strengths
void defeat(Warrior& winner, Warrior& loser);

//Returns pointer to warrior with specified name
Warrior* findWarrior(vector<Warrior>& warriors, string warName);

int main()
{
    vector<Warrior> warriors;
    ifstream battleLog("warriors.txt");
    //check if file was opened
    if(!battleLog)
    {
        cout << "Failed to open warriors.txt";
        exit(1);
    }
    runSequence(warriors, battleLog);
    battleLog.close();
}

void status(vector<Warrior>& warriors)
{
    cout << "There are " << warriors.size() << " warriors:" << endl;
    for(Warrior w : warriors)
    {
        cout << "Warrior: " << w.getName() << ", "
        << "weapon: " << w.getWepName() << ", " << w.getStrength();
        cout << endl;
    }
}

void runSequence(vector<Warrior>& warriors, ifstream& sequence)
{
    string line;
    string warName;
    string wepName;
    int wepStr;
    string fighterA;
    string fighterB;
    while(sequence >> line)
    {
        if(line == "Warrior") //creates a new warrior
        {
            sequence >> warName >> wepName >> wepStr;
            warriors.push_back(Warrior{warName,wepName,wepStr});
        }
        else if(line == "Status") //gives status
        {
            status(warriors);
        }
        else //battles two warriors
        {
            sequence >> fighterA >> fighterB;
            battle(*findWarrior(warriors, fighterA),
                   *findWarrior(warriors, fighterB));
        }
    }
}

void battle(Warrior& warA, Warrior& warB)
{
    cout << warA.getName() << " battles " << warB.getName() << endl;
    if(warA.getStrength() == 0)
    {
        if(warB.getStrength() == 0) //both were already dead
        {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else //only B is alive
        {
            cout << "He's dead, " << warB.getName() << endl;
        }
    }
    else if(warB.getStrength() == 0) //only A is alive
    {
        cout << "He's dead, " << warA.getName() << endl;
    }
    else
    {
        if(warA.getStrength() == warB.getStrength()) //both will die
        {
            cout << "Mutual Annihilation: " << warA.getName() << "and "
            << warB.getName() << " die at each other's hands" << endl;
            warA.setStrength(0);
            warB.setStrength(0);
        }
        else if (warA.getStrength() > warB.getStrength())
        {
            defeat(warA,warB);
        }
        else
        {
            defeat(warB,warA);
        }
    }
}

void defeat(Warrior& winner, Warrior& loser)
{
    cout << winner.getName() << " defeats " << loser.getName() << endl;
    winner.setStrength(winner.getStrength() - loser.getStrength());
    loser.setStrength(0);
}

Warrior* findWarrior(vector<Warrior>& warriors, string warName)
{
    for(Warrior& w : warriors)
    {
        if(w.getName() == warName)
        {
            return& w;
        }
    }
    return& warriors[0];
}


*/


