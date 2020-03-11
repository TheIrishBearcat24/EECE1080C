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
    //How would we implement a randomizational tool for the placement of the opponent's placement?
    //How would we check for winning and losing?
    //Going to need a do while loop to check for playing again

    //making sure owen can commit

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

    int main() {

        srand(time(0));
        
        ticTacToeBoard();

        return 0;
    }