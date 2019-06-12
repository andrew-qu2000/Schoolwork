//
//  hw02.cpp
//  hw02 - Medieval fighting simulator between warriors
//
//  Created by Andrew Qu on 2/7/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//
/*
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
using namespace std;

struct Warrior
{
    string name;
    int strength;
};

void defeat(Warrior& winner, Warrior& loser);
void battle(Warrior& war1, Warrior& war2);
void status(vector<Warrior> warriors);
Warrior findWarrior(vector<Warrior> warriors, string& name);

int main()
{
    vector<Warrior> warriors;
    ifstream battleLog("warriors.txt");
    string command;
    string name;
    int strength;
    Warrior warA;
    Warrior warB;
    
    while(battleLog >> command)
    {
        if (command == "Warrior")
        {
            battleLog >> name;
            battleLog >>  strength;
            Warrior newWar = Warrior();
            newWar.name = name;
            newWar.strength = strength;
            warriors.push_back(newWar);
        }
        else if (command == "Battle")
        {
            battleLog >> name;
            warA = findWarrior(warriors, name);
            battleLog >> name;
            warB = findWarrior(warriors, name);
            battle(warA, warB);
        }
        else
        {
            status(warriors);
        }
    }
}

void defeat(Warrior& winner, Warrior& loser)
{
    winner.strength -= loser.strength;
    loser.strength = 0;
    cout << winner.strength << " " << loser.strength << endl;
    cout << winner.name << " defeats " << loser.name << endl;
}

void battle(Warrior& war1, Warrior& war2)
{
    cout << war1.name << " battles " << war2.name << endl;
    if(war1.strength == 0)
    {
        if(war2.strength == 0)
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        else
            cout << "He's dead, " << war2.name << endl;
    }
    else if (war2.strength == 0)
        cout << "He's dead, " << war1.name << endl;
    else
    {
        cout << war1.strength << " " << war2.strength << endl;
        if(war1.strength < war2.strength)
            defeat(war2, war1);
        else if (war1.strength > war2.strength)
            defeat(war1, war2);
        else
        {
            cout << "Mutual Annihilation: " << war1.name << " and "
                 << war2.name << " die at each other's hands" << endl;
            war1.strength = 0;
            war2.strength = 0;
        }
    }
}

void status(vector<Warrior>& warriors)
{
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for(Warrior w : warriors)
        cout << "Warrior: " << w.name << ", strength: " << w.strength << endl;
}

Warrior findWarrior(vector<Warrior>& warriors, string& name)
{
    for (Warrior w : warriors)
    {
        if (w.name == name)
        {
            return w;
        }
    }
    return Warrior();
}

void runBattle(ifstream& sequence, vector<Warrior>& warriors)
{
    
}
*/
