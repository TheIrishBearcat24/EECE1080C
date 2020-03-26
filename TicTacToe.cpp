/**
 * 
 * By: Owen Porpora and Cameron Clarke
 * 
 * */

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void runGame();

char x = 'X';
char o = 'O';

char ticTacToe[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}}; // sets up the board

void ticTacToeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ticTacToe[i][j] << " "; // creates a 3x3 board
        }

        cout << endl;
    }
}

void computerChoice() {
    bool checker = true;
    int i = 0;

    cout << "Board after computer move: " << endl;
    cout << endl;

    while (checker == true) {
        if (ticTacToe[i / 4][int (i % 4)] == '-') { // uses an iterator to check if the next space is an empty slot
            ticTacToe[i / 4][int (i % 4)] = x; // acts as a random number generator for choosing computer's decision
            checker = false;
        }

        i += 1;
    }

    ticTacToeBoard();
}

void userChoice() {
    int row, col;

    again: // acts as a do-while loop
    cout << "Choose row for user (0, 1, 2): " << endl;
    cin >> row;
    cout << "Choose column for user (0, 1, 2): " << endl;
    cin >> col;
    cout << endl;

    if (ticTacToe[row][col] == x || ticTacToe[row][col] == o) {
        cout << "Slot already taken. Please try again." << endl;
        goto again;
    }

    else {
        ticTacToe[row][col] = o;
        cout << "Board after user input: " << endl;
        ticTacToeBoard();
    }
}

bool checkForWin() {
    bool hasWon = false;
    int userWonFlag = 0;

    // all of the logic for checking the winning conditions
    for (int i = 0; i < 3; i++) {
        if (ticTacToe[0][i] == o && ticTacToe[1][i] == o && ticTacToe[2][i] == o) {
            hasWon = true;
            userWonFlag = 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (ticTacToe[i][0] == o && ticTacToe[i][1] == o && ticTacToe[i][2] == o) {
            hasWon = true;
            userWonFlag = 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (ticTacToe[0][i] == x && ticTacToe[1][i] == x && ticTacToe[2][i] == x) {
            hasWon = true;
            userWonFlag = -1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (ticTacToe[i][0] == x && ticTacToe[i][1] == x && ticTacToe[i][2] == x) {
            hasWon = true;
            userWonFlag = -1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (ticTacToe[0][0] == x && ticTacToe[1][1] == x && ticTacToe[2][2] == x) {
            hasWon = true;
            userWonFlag = -1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (ticTacToe[2][0] == x && ticTacToe[1][1] == x && ticTacToe[2][0] == x) {
            hasWon = true;
            userWonFlag = -1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (ticTacToe[0][0] == o && ticTacToe[1][1] == o && ticTacToe[2][2] == o) {
            hasWon = true;
            userWonFlag = 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (ticTacToe[2][0] == o && ticTacToe[1][1] == o && ticTacToe[2][0] == o) {
            hasWon = true;
            userWonFlag = 1;
        }
    }

    return true;
}

void playAgainChecker(bool winner, char winningPiece, char & yesNo) {
    if (winner) {
        // this all displays the conditions and lets user say yes or no for going again
        if (winningPiece == '0') {
            cout << "You won!" << endl;
            cout << "Play again? (Y/N)" << endl;
            cin >> yesNo;
        }

        else if (winningPiece == 'X') {
            cout << "You lose!" << endl;
            cout << "Play again? (Y/N)" << endl;
            cin >> yesNo;
        }

        else {
            cout << "Tie!" << endl;
            cout << "Play again? (Y/N)" << endl;
            cin >> yesNo;
        }

        if (yesNo == 'Y' || yesNo == 'y') {
            winner = false;
            winningPiece = ' ';

            for (int i = 0; i < 3; i++) {
                ticTacToe[i][0] = '-';
                ticTacToe[i][1] = '-';
                ticTacToe[i][2] = '-';
            }
        }

        else {
            cout << "Thanks for playing!" << endl;
        }
    }
}

void runGame(char & yesNo) {

    bool isWinner = false;
    char winningPiece = ' ';

    while (!isWinner) {
        computerChoice();
        checkForWin();

        if (isWinner) {
            break;
        }

        userChoice();
        ticTacToeBoard();
        checkForWin();
    }

    playAgainChecker(isWinner, winningPiece, yesNo);

}

int main() {
    
    char yesNo = 'Y';
    unsigned randomSeed = time(0);
    srand(randomSeed);

    while (yesNo == 'Y') {
        runGame(yesNo);
    }

    return 0;
}