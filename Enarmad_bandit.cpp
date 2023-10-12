#include <iostream>
#include <ctime>
using namespace std;
int depositMoney();
int betMoney(int bet);

int main(){
    // Variables.
    int age, stake, totalWinToday = 0, playAgain, depositedMoney;
    bool play = true;

    // Welcomes the user.
    cout << "Welcome!\n"
            "How old are you?: ";
    cin >> age;

    while(play == true){
        // If the age of the user is 18 or above and wants to play again, they get to play.
        if (age >= 18){
            depositedMoney = depositMoney();
            stake = betMoney(depositedMoney);

            int field[3][3];

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
                cout << "\n\n";
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

    cout << endl;
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