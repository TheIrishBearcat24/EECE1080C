#include <iostream>
#include <string>
//going to need to include vector library and maybe stdlib?

using namespace std;

class TicTacToe {

    char x = 'X';
    char o = 'O';
    char playAgain = 'Y';

    char ticTacToe[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}}; //put this inside the do while loop

    //TO DO
    //How would we implement a randomizational tool for the placement of the opponent's placement?
    //How would we check for winning and losing?
    //Going to need a do while loop to check for playing again
};