#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

char x = 'X';
char o = 'O';
char playAgain = 'Y';

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
    cout << "Choose row for user: (0, 1, 2): " << endl;
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
    int playAgain;

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

    if (hasWon == true) {
        if (userWonFlag == 1) {
            cout << "You won!" << endl;
        }

        if (userWonFlag == -1) {
            cout << "Computer won!" << endl;
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