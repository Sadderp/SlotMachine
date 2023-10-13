#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int depositMoney();
int betMoney(int bet);
bool createFieldAndCheckWin();

int main(){
    // Variables.
    int age, stake, totalWinToday = 0, playAgain, depositedMoney;
    bool win = false;

    // Resets the time on the random function.
    srand(time(0));

    // Welcomes the user.
    cout << "Welcome!\n"
            "How old are you?: ";
    cin >> age;

    while(true){
        // If the age of the user is 18 or above and wants to play again, they get to play.
        if (age >= 18){
            depositedMoney = depositMoney();
            stake = betMoney(depositedMoney);

            if (createFieldAndCheckWin()) {
                cout << "Du har vunnit!\n";
            }
            else {
                cout << "Ingen vinst denna gång.\n";
            }

            cout << "success, for now :(";
            break;
        }
        else{
            cout << endl;
            cout << "You need to be at least 18 years old to play!";
            break;
        }
    }
    return 0;
}

// Deposit money
int depositMoney(){
    int amountOfMoney;

    // The amount of money the user wants to deposit.
    do {
        cout << endl;
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

// Bet money from the deposited money
int betMoney(int getDepositedMoney){
    int bet;

    // The amount of money the user wants to bet.
    do {
        
        cout << endl;
        cout << "You also need to bet an amount of money that is at least 100 kr and not above your total deposit. (Type in the amount you want to bet).\n"
                "You have "<< getDepositedMoney << " kr deposited.\n"
                "How much do you want to bet?: ";
        cin >> bet;
        cout << endl;
    } while (bet < 100 && cout << "You cannot bet under 100 kr." << endl || bet > getDepositedMoney && cout << "You cannot bet more than your deposit (" << getDepositedMoney << ") kr." << endl );

    return bet;
}

// Creates a gamefield and checks the win
bool createFieldAndCheckWin(){
    // Creates an 2D array that is 3*3.
    int field[3][3];

    // Insers random characters into the array objects.
    for (int row = 0; row < 3; row++){
        for (int square = 0; square < 3; square++){
            field[row][square] = rand() % 3;
            int character = field[row][square];
            switch(character){
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
    for (int i = 0; i < 3; i++) {
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2]) {
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (field[0][i] == field[1][i] && field[1][i] == field[2][i]) {
            return true;
        }
    }
    if (field[0][0] == field[1][1] && field[1][1] == field[2][2]) {
        return true;
    } 
    else if (field[0][2] == field[1][1] && field[1][1] == field[2][0]) {
        return true;
    }
    return false;
}