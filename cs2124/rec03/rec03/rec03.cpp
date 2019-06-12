//
//  rec03.cpp
//  rec03 - Minesweeper
//
//  Created by Andrew Qu on 2/15/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Minesweeper
{
    static const int BOMB_PROBABILITY = 10;
    const int BOARD_LENGTH = 10;
    const int BOARD_WIDTH = 10;
    struct Tile
    {
        bool isBomb;
        int bombNeighbors;
        bool isVisible;
        int row;
        int col;
        Tile(int r,int c)
        {
            if( (rand() % 100) < BOMB_PROBABILITY)
            {
                isBomb = true;
            }
            else
            {
                isBomb = false;
            }
            isVisible = false;
            row = r;
            col = c;
        }
    };
    vector<vector<Tile>> BOARD;
    
public:
    Minesweeper()
    {
        //populate board with tiles
        for(int r = 0;r < BOARD_LENGTH;r ++)
        {
            vector<Tile> row;
            for(int c = 0;c < BOARD_WIDTH;c ++)
            {
                row.push_back(Tile(r + 1,c + 1));
            }
            BOARD.push_back(row);
        }
        //calculate bomb neighbors for each tile
        for(vector<Tile>& r : BOARD)
        {
            for(Tile& t : r)
            {
                t.bombNeighbors = countBombs(t.row, t.col);
            }
        }
    }
    //returns number of bombs adjacent to given coordinate
    int countBombs(int& row, int& col) const
    {
        int bombs = 0;
        if(!validRow(row) || !validCol(col))
        {
            return bombs;
        }
        bombs += isBombTile(row - 1, col - 1);
        bombs += isBombTile(row - 1, col);
        bombs += isBombTile(row - 1, col + 1);
        bombs += isBombTile(row, col - 1);
        bombs += isBombTile(row, col + 1);
        bombs += isBombTile(row + 1, col - 1);
        bombs += isBombTile(row + 1, col);
        bombs += isBombTile(row + 1, col + 1);
        return bombs;
    }
    //returns true if given row is in bounds of board, false otherwise
    bool validRow(int row) const
    {
        return (row >= 1 && row <= BOARD_LENGTH);
    }
    //returns true if given column in in bounds of board, false otherwise
    bool validCol(int col) const
    {
        return (col >= 1 && col <= BOARD_WIDTH);
    }
    //returns true if tile at given coordinate is a bomb, false oherwise
    int isBombTile(int row, int col) const
    {
        if(!validRow(row) || !validCol(col))
        {
            return 0;
        }
        if(BOARD[row - 1][col - 1].isBomb)
            return 1;
        return 0;
    }
    //returns true if tile at given coordinate is visible, false otherwise
    bool isVisible(int row, int col) const
    {
        if(!validRow(row) || !validCol(col))
        {
            return false;
        }
        return BOARD[row - 1][col - 1].isVisible;
    }
    //prints current state of board
    void display(bool showBombs) const
    {
        for(const vector<Tile>& row : BOARD)
        {
            for(const Tile& t : row)
            {
                //if showBombs is true, all bombs are shown
                //regardless of that tile's visibility
                if(t.isBomb && showBombs)
                {
                    cout << "[*]";
                }
                else if(t.isVisible)
                {
                    cout << "[" << t.bombNeighbors << "]";
                }
                else
                {
                    cout << "[ ]";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    //plays an additional tile if play() is called on a tile
    //with no bomb neighbors
    void playHelper(int row, int col)
    {
        if(!validRow(row) || !validCol(col))
        {
            return;
        }
        if(BOARD[row - 1][col - 1].isVisible)
        {
            return;
        }
        BOARD[row - 1][col - 1].isVisible = true;
        if(BOARD[row - 1][col - 1].bombNeighbors == 0)
        {
            playAdjacents(row, col);
        }
    }
    //calls playHelper on all adjacent tiles of given coordinate
    void playAdjacents(int row, int col)
    {
        playHelper(row - 1, col - 1);
        playHelper(row - 1, col);
        playHelper(row - 1, col + 1);
        playHelper(row, col - 1);
        playHelper(row, col + 1);
        playHelper(row + 1, col - 1);
        playHelper(row + 1, col);
        playHelper(row + 1, col + 1);
    }
    //reveals the tile at given coordinate
    bool play(int row, int col)
    {
        BOARD[row - 1][col - 1].isVisible = true;
        if(isBombTile(row, col))
        {
            return false;
        }
        if(BOARD[row - 1][col - 1].bombNeighbors == 0)
        {
            playAdjacents(row, col);
        }
        return true;
    }
    //returns true if bombs are the only invisble tiles left on the board
    //returns false otherwise
    bool done() const
    {
        for(const vector<Tile>& row : BOARD)
        {
            for(const Tile& t : row)
            {
                if(!t.isVisible && !t.isBomb)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    srand(int(time(NULL)));
    Minesweeper sweeper = Minesweeper();
    while (!sweeper.done())
    {
        sweeper.display(false);
        int row_sel = -1, col_sel = -1;
        while(row_sel == -1)
        {
            int r,c;
            cout << "row?";
            cin >> r;
            if(!sweeper.validRow(r))
            {
                cout << "Row out of bounds\n";
                continue;
            }
            cout << "col?";
            cin >> c;
            if(!sweeper.validCol(c))
            {
                cout << "Column out of bounds\n";
                continue;
            }
            if(sweeper.isVisible(r,c))
            {
                cout << "Square already visible\n";
                continue;
            }
            row_sel = r;
            col_sel = c;
        }
        if(!sweeper.play(row_sel,col_sel))
        {
            cout << "Sorry, you died...\n";
            sweeper.display(true);
            exit(0);
        }
    }
    cout << "You won!!!!\n";
    sweeper.display(true);
}
