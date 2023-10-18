#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int depositMoney();
int betMoney();
int createFieldAndCheckWin();
void checkFieldResult(int, int);
int checkAge();
void playAgain();
void gameLoop();

// Global variables.
int totalWinToday = 0;
int depositedMoney = 0;

int main() {
    int checkedAge;

    checkedAge = checkAge();
    if (checkedAge >= 18 && checkedAge <= 120) {
        gameLoop();
    }
    else {
        cout << "Error! Something went wrong!";
    }
    return 0;
}

// Gameloop.
void gameLoop() {
    // Variables.
    bool win = false;

    // Resets the time on the random function.
    srand(time(0));
    if (depositedMoney < 100) {
        depositedMoney += depositMoney();
    }
    checkFieldResult(createFieldAndCheckWin(), betMoney());
    playAgain();
}

// Gets the age of the user.
int checkAge() {
    // Variables.
    int age;

    // Welcomes the user.
    do {
        cout << endl;
        cout << "Welcome!\n"
            "You need to enter your age (18-120)\n"
            "How old are you?: ";
        cin >> age;
        cout << endl;
    } while (age < 18 && cout << "You must be at least 18 years old!\n" || age > 120 && cout << "You can't be older than 120 years!\n");

    return age;
}

// Deposit money.
int depositMoney() {
    // Variables.
    int amountOfMoney;
    // The amount of money the user wants to deposit.
    do {
        cout << "You need to deposit an amount of money. (Type in the amount you want to deposit).\n"
            "1. 100 kr\n"
            "2. 300 kr\n"
            "3. 500 kr\n"
            "How much do you want to deposit?: ";
        cin >> amountOfMoney;
        cout << endl;
    } while (amountOfMoney != 100 && amountOfMoney != 300 && amountOfMoney != 500 && cout << "You can only choose between 100, 300 or 500 kr.");

    cout << "You deposited " << amountOfMoney << " kr." << endl;

    return amountOfMoney;
}

// Bet money from the deposited money.
int betMoney() {
    // Variables.
    int bet;

    // The amount of money the user wants to bet.
    do {

        cout << endl;
        cout << "You also need to bet an amount of money that is at least 100 kr and not above your total deposit. (Type in the amount you want to bet).\n"
            "You have " << depositedMoney << " kr deposited.\n"
            "How much do you want to bet?: ";
        cin >> bet;
        cout << endl;
    } while (bet < 100 && cout << "You cannot bet under 100 kr." << endl || bet > depositedMoney && cout << "You cannot bet more than your deposit (" << depositedMoney << ") kr." << endl);

    return bet;
}

// Creates a gamefield and checks the result.
int createFieldAndCheckWin() {
    // Variables.
    int win = 0;

    // Creates an 2D array that is 3*3.
    int field[3][3]{};

    // Insers random characters into the array objects.
    for (int row = 0; row < 3; row++) {
        for (int square = 0; square < 3; square++) {
            field[row][square] = rand() % 3;
            int character = field[row][square];
            switch (character) {
            case 0:
                cout << "O ";
                break;
            case 1:
                cout << "X ";
                break;
            case 2:
                cout << "A ";
                break;
            }
        }
        cout << "\n";
    }

    // Check win condition.
    // Rows.
    for (int i = 0; i < 3; i++) {
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2]) {
            win += 1;
        }
    }

    // Columns.
    for (int i = 0; i < 3; i++) {
        if (field[0][i] == field[1][i] && field[1][i] == field[2][i]) {
            win += 1;
        }
    }

    // Top left to bot right.
    if (field[0][0] == field[1][1] && field[1][1] == field[2][2]) {
        win += 1;
    }
    // Bot left to top right.
    else if (field[0][2] == field[1][1] && field[1][1] == field[2][0]) {
        win += 1;
    }
    return win;
}

// Checks the result of the field and how much money the user won.
void checkFieldResult(int winResult, int bet) {
    // How many rows, columns and/or diagonals that are correct.
    // One argument
    cout << winResult;
    switch (winResult) {
    case 1:
        depositedMoney += bet * 2;
        totalWinToday += bet * 2;
        cout << "You got one argument correct, you win " << bet * 2 << " kr and your new deposit is " << depositedMoney << " kr!\n"
            "You have won/lost this much today: " << totalWinToday << " kr.";
        cout << endl;
        // Two arguments
    case 2:
        depositedMoney += bet * 2;
        totalWinToday += bet * 2;
        cout << "You got two arguments correct, you win " << bet * 2 << " kr and your new deposit is " << depositedMoney << " kr!\n"
            "You have won/lost this much today: " << totalWinToday << " kr.";
        cout << endl;
        // Three arguments
    case 3:
        depositedMoney += bet * 3;
        totalWinToday += bet * 3;
        cout << "You got three arguments correct, you win " << bet * 3 << " kr and your new deposit is " << depositedMoney << " kr!\n"
            "You have won/lost this much today: " << totalWinToday << " kr.";
        cout << endl;
        // Four arguemnts
    case 4:
        depositedMoney += bet * 3;
        totalWinToday += bet * 3;
        cout << "You got four arguments correct, you win " << bet * 3 << " kr and your new deposit is " << depositedMoney << " kr!\n"
            "You have won/lost this much today: " << totalWinToday << " kr.";
        cout << endl;
        // Five arguments
    case 5:
        depositedMoney += bet * 5;
        totalWinToday += bet * 5;
        cout << "You got five arguments correct, you win " << bet * 5 << " kr and your new deposit is " << depositedMoney << " kr!\n"
            "You have won/lost this much today: " << totalWinToday << " kr.";
        cout << endl;
        // Six arguments
    case 6:
        depositedMoney += bet * 5;
        totalWinToday += bet * 5;
        cout << "You got six arguments correct, you win " << bet * 5 << " kr and your new deposit is " << depositedMoney << " kr!\n"
            "You have won/lost this much today: " << totalWinToday << " kr.";
        cout << endl;
        // Eight arguments
    case 8:
        depositedMoney += bet * 10;
        totalWinToday += bet * 10;
        cout << "You got full field, you win " << bet * 10 << " kr and your new deposit is " << depositedMoney << " kr!\n"
            "You have won/lost this much today: " << totalWinToday << " kr.";
        cout << endl;
        // Zero arguments
    case 0:
        depositedMoney -= bet;
        totalWinToday -= bet;
        cout << "You lost " << bet << " kr and your new deposit is " << depositedMoney << " kr!\n"
            "You have won/lost this much today: " << totalWinToday << " kr.";
        cout << endl;
    }
}

// Play again.
void playAgain() {
    // Variables.
    int playAgain;

    // Askes if the user wants to play again.
    do {
        cout << endl;
        cout << "Do you want to play again or cash out? (Type 1 to play again, 2 to cash out).\n"
            "1. Play again\n"
            "2. Cash out\n"
            "Type in your answer here: ";
        cin >> playAgain;
        cout << endl;
    } while (playAgain != 1 && playAgain != 2 && cout << "You can only input 1 or 2.");

    if (playAgain == 1) {
        if (depositedMoney < 100) {
            cout << "You need to deposit more money." << endl;
            cout << endl;
            gameLoop();
        }
        else {
            gameLoop();
        }
    }
    else {
        cout << "Thanks for playing!" << endl;
        exit(0);
    }
}
