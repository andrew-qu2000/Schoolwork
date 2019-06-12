//
//  rec02.cpp
//  rec02 - Script that receives a list of a hydrocarbons and sorts them by molecular formula
//
//  Created by Andrew Qu on 2/8/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
using namespace std;

struct hydrocarbon
{
    vector<string> names;
    int carbonAtoms;
    int hydrogenAtoms;
};
//Prompts user for name of text file containing hydrocarbons
void openStream(ifstream& streamToOpen);

//Returns index of molecular formula that new hydrocarbon should be added to
size_t findSameFormula(const vector<hydrocarbon>& formulaVector, int ca, int ha);

//Adds a new hydrocarbon to the collection
void addHydrocarbon(vector<hydrocarbon>& formulaVector, string name, int ca, int ha);

//Creates collection of hydrocarbons based on text file
void fillVector(vector<hydrocarbon>& formulaVector, ifstream& file);

//Bubble-Sorts collection of hydrocarbons based on number of carbon/hydrogen atoms
void sortVector(vector<hydrocarbon>& formulaVector);

//Outputs list of formulas and associated hydrocarbons
void displayVector(const vector<hydrocarbon>& formulaVector);

int main()
{
    ifstream formulaFile;
    vector<hydrocarbon> hydrocarbons;
    openStream(formulaFile);
    fillVector(hydrocarbons, formulaFile);
    sortVector(hydrocarbons);
    displayVector(hydrocarbons);
}

void openStream(ifstream& streamToOpen)
{
    string fileName;
    do{
        streamToOpen.clear();
        cout << "Enter name of file:";
        cin >> fileName;
        streamToOpen.open(fileName);
    }while(!streamToOpen);
}

void fillVector(vector<hydrocarbon>& formulaVector, ifstream& file)
{
    string hcName;
    int ca;
    int ha;
    char element;
    while( file >> hcName >> element >> ca >> element >> ha)
    {
        addHydrocarbon(formulaVector, hcName, ca, ha);
    }
}

void addHydrocarbon(vector<hydrocarbon>& formulaVector, string name, int ca, int ha)
{
    size_t indToAddTo = findSameFormula(formulaVector, ca, ha);
    //If same formula doesn't exist
    if(indToAddTo == formulaVector.size())
    {
        vector<string> newNames;
        newNames.push_back(name);
        hydrocarbon hc = hydrocarbon{newNames, ca, ha};
        formulaVector.push_back(hc);
    }
    //If same formula does exist
    else
    {
        formulaVector[indToAddTo].names.push_back(name);
    }
}

size_t findSameFormula(const vector<hydrocarbon>& formulaVector, int ca, int ha)
{
    for(size_t i = 0;i < formulaVector.size();i++)
    {
        if(formulaVector[i].carbonAtoms == ca)
            if(formulaVector[i].hydrogenAtoms == ha)
                return i;
    }
    return formulaVector.size(); //If same formula is not found
}

void sortVector(vector<hydrocarbon>& formulaVector)
{
    bool swapped = true;
    while(swapped)
    {
        swapped = false;
        for(size_t i = 0;i < formulaVector.size() - 1;i++)
        {
            if(formulaVector[i].carbonAtoms > formulaVector[i+1].carbonAtoms)
            {
                swap(formulaVector[i],formulaVector[i+1]);
                swapped = true;
            }
            else if (formulaVector[i].carbonAtoms == formulaVector[i+1].carbonAtoms)
            {
                if(formulaVector[i].hydrogenAtoms > formulaVector[i+1].hydrogenAtoms)
                {
                    swap(formulaVector[i],formulaVector[i+1]);
                    swapped = true;
                }
            }
        }
    }
}

void displayVector(const vector<hydrocarbon>& formulaVector)
{
    for(hydrocarbon hc : formulaVector)
    {
        cout << 'C' << hc.carbonAtoms << 'H' << hc.hydrogenAtoms;
        for(string name : hc.names)
        {
            cout << ' ' << name;
        }
        cout << endl;
    }
}
