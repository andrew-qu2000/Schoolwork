//
//  hw01.cpp
//  hw01 - A script that reads a text file and undoes a Caesar Cypher
//
//  Created by Andrew Qu on 2/6/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Decrypts a lowercase letter by rotating a number of steps
char decryptChar(int steps, char encryption)
{
    //check if input is a lowercase letter
    if( encryption < 'a' || encryption > 'z' )
        return encryption;
    if( encryption - 'a' >= steps)
        return encryption - steps;
    return 'z' - (steps - (encryption - 'a') - 1);
}
//Mutates and decrypts a string
void decryptStr(int steps, string& encryption)
{
    for(size_t i = 0;i < encryption.size();i++)
    {
        encryption[i] = decryptChar(steps, encryption[i]);
    }
}
//Print out a vector of strings in reverse order
void printLines(vector<string> lines)
{
    for(size_t i = lines.size() - 1;i >= 0;i--)
    {
        cout << lines[i] << endl;
        if(i == 0) //prevent size_t from rolling over
            break;
    }
}

int main()
{
    //read and test text file
    ifstream encryptedText("encrypted.txt");
    if(!encryptedText)
    {
        cerr << "Could not open encrypted.txt\n";
        exit(1);
    }
    //read integer of steps used in Caesar Cypher
    int caesarSteps;
    encryptedText >> caesarSteps;
    string line;
    getline(encryptedText, line); //read the \n following the integer in the text file
    //read and decrypt lines, store in a vector of strings
    vector<string> lines;
    while( getline(encryptedText, line) )
    {
        decryptStr(caesarSteps, line);
        lines.push_back(line);
    }
    
    printLines(lines);
    
}
