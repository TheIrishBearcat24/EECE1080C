#include "catAndMouse.h"

/**
 * 
 * Project title: Tesla Game (aka Cat and Mouse)
 * 
 * */

char direction;

int userRow;
int userCol;
int roadsterRow;
int roadsterCol;
int tempY = 0;
int tempX = 0;

void catAndMouse::setUpBoard() {
    int rowCounter = 0;
    int colCounter = 0;
    int colCounter1 = 0; // had to make a second colum counter because for some reason if
                        // I copied and pasted the code from below, it messed up the ordering of the numbers

    for (int a = 0; a < 15; a++) {
        cout << " " << colCounter1;
        colCounter1++;

        if (colCounter1 >= 10) {
            colCounter1 %= 10;
        }
    }

    cout << endl;

    for (int i = 0; i < 15; i++) {
        cout << rowCounter;
        for (int j = 0; j < 15; j++) {
            cout << board[i][j] << " ";
        }
        
        cout << rowCounter;

        cout << endl;

        rowCounter++;

        if (rowCounter >= 10) {
            rowCounter %= 10; // for some reason once the counter hit 10, the formatting for the board got screwed up
                            // so this resets the counter back to zero in a sense, but here 1 = 11 etc
        }
    }

    for (int k = 0; k < 15; k++) {
        cout << " " << colCounter;
        colCounter++;

        if (colCounter >= 10) {
            colCounter %= 10;
        }
    }
}

void catAndMouse::randomPlacement() {

    srand(time(0));

    userRow = (rand() % 14) + 1;
    userCol = (rand() % 14) + 1;
    roadsterRow = (rand() % 14) + 1;
    roadsterCol = (rand() % 14) + 1;

    // checks for an empty slot on the board
    if (board[userRow][userCol] == '-') {
        board[userRow][userCol] = userPlace;
    }

    // if (board[roadsterRow][roadsterCol] == '-' && !(board[roadsterRow][roadsterCol] == board[userRow][userCol])) {
    //     board[roadsterRow][roadsterCol] = roadster;
    // }

    setUpBoard();

    cout << endl;
}

void catAndMouse::move() {
    
    // randomizes the placement of the character
    srand(time(0));

    userRow = (rand() % 14) + 1;
    userCol = (rand() % 14) + 1;
    roadsterRow = (rand() % 14) + 1;
    roadsterCol = (rand() % 14) + 1;

    // big do-while loop includes switch statement to continuously move the user character
    do {
        cout << "Enter letter to move in a direction (W - Up, A - Left, S - Down, D - Right): ";
        cin >> direction;

        switch (direction) {
            case 'W':
                board[userRow][userCol] = '-'; // sets old position to an empty slot
                tempY = userRow - 1; // shifts user one position up
                shiftUser(tempY, userCol);
                userRow = tempY;
                board[userRow][userCol] = userPlace;
                setUpBoard();
                break;
            case 'A':
                board[userRow][userCol] = '-'; // sets old position to an empty slot
                tempX = userCol - 1; // shifts user one position left
                shiftUser(userRow, tempX);
                board[userRow][userCol] = userPlace;
                setUpBoard();
                break;
            case 'S':
                board[userRow][userCol] = '-'; // sets old position to an empty slot
                tempY = userRow + 1; // shifts user one position down
                shiftUser(tempY, userCol);
                board[userRow][userCol] = userPlace;
                setUpBoard();
                break;
            case 'D':
                board[userRow][userCol] = '-'; // sets old position to an empty slot
                tempX = userCol + 1; // shifts user one position right
                shiftUser(userRow, tempX);
                board[userRow][userCol] = userPlace;
                setUpBoard();
                break;
            default:
                board[userRow][userCol] = board[userRow][userCol]; // just leaves character there
                setUpBoard();
                break;
        }
        cout << endl;
    }

    while (promptAgain() == true);
}

// boolean function to see whether or not the user wants to move again
bool catAndMouse::promptAgain() {
    bool moveAgainChecker; 
    char moveAgain;
    cout << endl;
    cout << "Move again? ";
    cin >> moveAgain;

    if (moveAgain == 'Y' || moveAgain == 'y') {
        moveAgainChecker = true;
    }

    else {
        moveAgainChecker = false;
    }

    return moveAgainChecker;   
}

int catAndMouse::getXCoord(int coordinate) { // returns x coordinate into the userCol variable
    userCol = coordinate; // I was dumb and originally had the coordinate feeding into the userCol
    return coordinate;
}

int catAndMouse::getYCoord(int coordinate) { // returns y coordinate into the userRow variable
    userRow = coordinate; // I was dumb and originally had the coordinate feeding into the userRow
    return coordinate;
}

// allows user to recursively store the new position from the previous move as the starting position for the next move
char catAndMouse::shiftUser(int y, int x) {
    y = getYCoord(y);
    x = getXCoord(x);

    return userPlace;
}

int main() {
    catAndMouse game;
    game.randomPlacement();
    game.move();
    game.promptAgain();
    return 0;
}