//
//  rec01.cpp
//  rec01
//
//  Created by Andrew Qu on 2/1/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//globals
vector<vector<char>> map;
int generations = 10;

//checks if coordinate is within bounds
bool isValid(size_t row, size_t col)
{
    return( (row >= 0 && row < map.size() - 1) && (col >= 0 && col < map[row].size() - 1) );
}

//counts all living neighbors of a space
int countNeighbor(size_t row, size_t col)
{
    int count = 0;
    if(isValid(row - 1, col - 1) && map[row - 1][col - 1] == '*') count++;
    if(isValid(row - 1, col) && map[row - 1][col] == '*') count++;
    if(isValid(row - 1, col + 1) && map[row - 1][col + 1] == '*') count++;
    if(isValid(row, col - 1) && map[row][col - 1] == '*') count++;
    if(isValid(row, col + 1) && map[row][col + 1] == '*') count++;
    if(isValid(row + 1, col - 1) && map[row + 1][col - 1] == '*') count++;
    if(isValid(row + 1, col) && map[row + 1][col] == '*') count++;
    if(isValid(row + 1, col + 1) && map[row + 1][col + 1] == '*') count++;
    return count;
}

void printMap()
{
    for(vector<char> row : map)
    {
        for(char c : row)
            cout << c;
        cout << endl;
    }
    cout << endl;
}

int main()
{
    ifstream life("life.txt");
    if (!life)
    {
        cerr << "Could not open life.txt\n";
        exit(1);
    }
    vector<char> rowVector;
    string row;
    while (getline(life, row))
    {
        rowVector.clear();
        for(char c : row)
        {
            rowVector.push_back(c);
        }
        map.push_back(rowVector);
    }
    life.close();
    printMap();
    
    //print new generations
    vector<vector<char>> newGeneration;
    int currGeneration = 0;
    while(currGeneration < generations)
    {
        for(size_t r = 0;r < map.size();r ++)
        {
            vector<char> newRowVector;
            for(size_t c = 0;c < map[r].size();c ++)
            {
                int livingNeighbors = countNeighbor(r, c);
                if(livingNeighbors == 3)
                    newRowVector.push_back('*');
                else if (livingNeighbors == 2 && map[r][c] == '*')
                    newRowVector.push_back('*');
                else
                    newRowVector.push_back('-');
            }
            newGeneration.push_back(newRowVector);
            newRowVector.clear();
        }
        map.clear();
        for(vector<char> row : newGeneration)
        {
            map.push_back(row);
        }
        printMap();
        newGeneration.clear();
        currGeneration += 1;
    }
}
