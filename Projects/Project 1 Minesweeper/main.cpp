/*
 *  Created on: 10/10/2019
 * Project Name: Project 1 Minesweeper
 * Author: Jade Braun
 * Last Updated: 10/20/2019
 */

#include<iostream>
#include<sstream> //stringstream
#include<cstdlib> //rand function
#include<string>
#include<stdlib.h>
#include<ctime> //time function
#include<cctype>
#include<fstream>
#include "Struct.h"

using namespace std;

char board[9][9], mineAry[9][9], reset;
int numMines, x, y, count = 0;
string xPos, yPos;


//function prototypes
void assign();
void display(char bo[9][9]);
void readFile(char board[9][9]);
void writeFile(char board[9][9]);
void mineNum();
void play();
void adjacent();
int check();

int main() {

    
    //users input for level difficulty
    char choice;

    //structure variables
    Beginner mine;
    Inter m;
    Hard boom;

    //create a do while loop that contains bulk of gameplay code
    do {


        cout << "Would you like to play easy or hard mode." << endl
                << "Easy mode only has 10 mines intermediate has 20 and hard mode has 30." << endl
                << "Enter E for easy, M for medium and H for hard." << endl;
        cin >> choice;
        choice = toupper(choice);
        //while loop to check  if valid input
        while (!((choice == 'E') || (choice == 'M') || (choice == 'H'))) {

            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid entry, please pick a level difficulty (e/m/h): ";
            cin >> choice;
            choice = toupper(choice); //automatically capitalizes char 
            //I used it just to shorten my argument in the while() so I didn't have to type out all 6 options


        }

        if (choice == 'E' || choice == 'e') {

            //assigns number of mines to be 10
            mine.mineN = numMines;
            numMines = 10;
            assign();
            display(board);
            play();
            readFile(board);
            writeFile(board);


            cout << "Play again? (y/n): ";
            cin >> reset;
        }
        //assigns 20 mines
        if (choice == 'm' || choice == 'M') {
            m.min = numMines;
            numMines = 20;
            assign();
            display(board);
            play();
            readFile(board);
            writeFile(board);
            
            cout << "Play again? (y/n): ";
            cin >> reset;
        }

        //assigns 30 mines
        if (choice == 'H' || choice == 'h') {
            boom.bomb = numMines;
            numMines = 30;
            assign();
            display(board);
            play();
            readFile(board);
    writeFile(board);
    
            cout << "Play again? (y/n): ";
            cin >> reset;
        }


    } while (reset == 'y' || reset == 'Y');
    //resets game, exits if 'n' or 'N' is entered

  
    return 0;
}

void assign() {

    //create random seed
    srand((unsigned int) time(0));

    //creating the character table to display hyphens as the board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = '-';
            mineAry[i][j] = '0';
        }
    }
    //placing the mines on the board
    for (int i = 0; i < numMines; i++) {

        int row = (rand() % 9);

        int col = (rand() % 9);

        //! will show up if mine is found
        while (mineAry[row][col] == '!') {
            row = (rand() % 9);

            col = (rand() % 9);

        }
        mineAry[row][col] = '!';

    }

    mineNum();

}
//this function counts the amount of mines are around the tile you just revealed

void mineNum() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (mineAry[i][j] == '!') {
                for (int row = i - 1; row <= i + 1; row++) {
                    for (int col = j - 1; col <= j + 1; col++) {
                        if (row >= 0 && row <= 9) {
                            if (col >= 0 && col <= 9) {
                                //if no mine is found it counts how many mines there are around the selected tile
                                if (mineAry[row][col] != '!') {
                                    mineAry[row][col] += 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void readFile(char mineAry[9][9])
{
     ifstream fIn("mines.txt");
    
    if(fIn.fail())
    {
        cout << "Error opening file"; 
    }
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
           fIn >> mineAry[i][j]; 
        }
    }
    fIn.close();
          
}
//display the board
void display(char bo[9][9]) {
    
    
            
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << bo[i][j] << " ";
            
        }
        cout << endl;
    }
}
void writeFile(char mineAry[9][9])
{
    ofstream fOut;
    fOut.open("output.txt");
    if(fOut.fail())
    {
        cout << "Error opening file" << endl;
        
    }
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            board[i][j] = mineAry[i][j];
            fOut << mineAry[i][j];
            
        }
            fOut<< endl;
    }
    fOut.close();
   
    
}

void play() {
    //81 tiles for 9 by 9 board
    for (int i = 0; i <= 81; i++) {

        //while loops to get valid row and column inputs
        do {
            cout << "Enter the number of the row you'd like to choose a spot (1 - 9)" << endl;
            cin >> xPos;
            stringstream(xPos) >> x;
        } while (x < 1 || x > 9);

        do {
            cout << "Enter the number of the column you'd like to choose a spot (1 - 9)" << endl;
            cin >> yPos;
            stringstream(yPos) >> y;

        } while (y < 1 || y > 9);

        //if the row and col have already been revealed
        while (board[x - 1][y - 1] == mineAry[x - 1][y - 1]) {
            cout << "You've already picked that spot." << endl;
            cout << "Please enter a row you haven't piked yet:" << endl;
            cin >> xPos;
            stringstream(xPos) >> x;

            cout << "Please enter a column you haven't picked yet:" << endl;
            cin >> yPos;
            stringstream(yPos) >> y;

        }
        //checks if you hit a mine
        if (mineAry[x - 1][y - 1] == '!') {
            cout << "BOOM!" << endl;
            cout << "Game Over" << endl;

            display(mineAry);
            return;
        } else {

            board[x - 1][y - 1] = mineAry[x - 1][y - 1];
            adjacent();
            display(board);
            count = check();

            if (count == (81 - numMines)) {
                cout << "WINNER!" << endl;
                //returns to ask user if they want to play again
                return;
            }
        }
    }
}
//function that checks adjacent tiles for 0
//this function pops up the spaces around it until it hits a nonzero value

void adjacent() {
    if (mineAry[x - 1][y - 1] == '0') {
        for (int row = x - 2; row != x + 1; row++) {
            for (int col = y - 2; col != y + 1; col++) {
                if (row >= 0 && row <= 9) {
                    if (col >= 0 && col <= 9) {
                        board[row][col] = mineAry[row][col];

                        if (mineAry[row][col] == '0') {
                            for (int row2 = row - 1; row2 != row + 2; row2++) {
                                for (int col2 = col - 1; col2 != col + 2; col2++) {
                                    if (row2 >= 0 && row2 <= 9) {
                                        if (col2 >= 0 && col2 <= 9) {
                                            if (mineAry[row2][col2] != '!') {
                                                board[row2][col2] = mineAry[row2][col2];
                                            }

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}
//checks if no more mines then you win

int check() {
    int count = 0;
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == mineAry[row][col]) {
                count = count + 1;
            }
        }
    }
    return count;
}