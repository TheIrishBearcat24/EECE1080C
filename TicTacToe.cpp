#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
//going to need to include vector library and maybe stdlib?

using namespace std;

    char x = 'X';
    char o = 'O';
    char playAgain = 'Y';

    char ticTacToe[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}}; //put this inside the do while loop
    
    //TO DO
    //Make array of user inputs and computer inputs
    //cout computer user and computer inputs
    //After each input, the other player needs to make a move
    //Computer always goes first
    //Need to make it that computer almost always wins
    //Machine learning aspect

    void ticTacToeBoard() {
        do {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << ticTacToe[i][j] << " ";
                }

                cout << endl;
            }

            cout << "Want to play again? (Y/N): ";

            cin >> playAgain;
        }

        while (playAgain == 'y' || playAgain == 'Y');
    }

    void computeMoves() {
        char firstMove = rand() % 3;
    }

    int main() {
        
        ticTacToeBoard();

        return 0;
    }