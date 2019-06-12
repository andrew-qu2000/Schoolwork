//
//  hw02.cpp
//  hw02 - Medieval fighting simulator between warriors
//
//  Created by Andrew Qu on 2/13/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
using namespace std;

struct Warrior
{
    string name;
    int strength;
};

//Returns index of named warrior in vector of warriors
size_t findWarrior(vector<Warrior> warriors, string name)
{
    for (size_t i = 0;i < warriors.size();i++)
    {
        if (warriors[i].name == name)
            return i;
    }
    return 0;
}

//Adjusts strengths of fighters and announces winner
void defeat(Warrior& winner, Warrior& loser)
{
    winner.strength -= loser.strength;
    loser.strength = 0;
    cout << winner.name << " defeats " << loser.name << endl;
}

//Battles two warriors based on their strengths
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
    else //both fighters are still alive
    {
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
//Prints all existing warriors and their information
void status(vector<Warrior>& warriors)
{
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for(Warrior w : warriors)
        cout << "Warrior: " << w.name << ", strength: " << w.strength << endl;
}

int main()
{
    vector<Warrior> warriors;
    ifstream battleLog("warriors.txt");
    string command;
    string name;
    int strength;
    string warA;
    string warB;
    
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
            battleLog >> warA;
            battleLog >> warB;
            battle( warriors[findWarrior(warriors,warA)],
                    warriors[findWarrior(warriors,warB)] );
        }
        else
        {
            status(warriors);
        }
    }
}
