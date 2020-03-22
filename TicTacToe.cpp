#include <iostream>
#include <iomanip>
#include <string>
#include <array>

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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ticTacToe[i][j] << " ";
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
            ticTacToe[i / 4][int (i % 4)] = x;
            checker = false;
        }

        i += 1;
    }

    ticTacToeBoard();
}

void userChoice() {
    int row, col;

    again: // acts as a do-while loop
    cout << "Choose row for user: (0, 1, 2): " << endl;
    cin >> row;
    cout << "Choose column for user (0, 1, 2): " << endl;
    cin >> col;
    cout << endl;

    if (ticTacToe[col][row] == x || ticTacToe[col][row] == o) {
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
    int playAgain;

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

    if (hasWon == true) {
        if (userWonFlag == 1) {
            cout << "You won! Play again? " << endl;
            cin >> playAgain;
        }

        if (userWonFlag == -1) {
            cout << "Computer won! Play again? " << endl;
            cin >> playAgain;
        }
    }

    return true;
}

int main() {
    
    bool runGame = true;

    while (runGame == true) {
        computerChoice();
        runGame = checkForWin();
        userChoice();
        runGame = checkForWin();
    }

    return 0;
}