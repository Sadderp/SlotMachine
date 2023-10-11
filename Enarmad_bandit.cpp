#include <iostream>
#include <ctime>
using namespace std;
int depositMoney();
int betMoney();

int main(){
    // Variables.
    int age, stake, totalWinToday = 0, playAgain;
    bool play = true;

    // Welcomes the user.
    cout << "Welcome!\n"
            "How old are you?: ";
    cin >> age;

    while(play == true){
        // If the age of the user is 18 or above and wants to play again, they get to play.
        if (age >= 18){
            //depositedMoney = depositMoney();
            
            stake = betMoney();
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

// Askes the user how much money they want to deposit. It must be at least 100 kr.
int depositMoney(){
    int amountOfMoney;

    // The amount of money the user wants to deposit.
    do {
        cout << endl;
        cout << "You need to deposit an amount of money that is at least 100 kr. (Type in the amount you want to deposit).\n"
                "How much do you want to deposit?: ";
        cin >> amountOfMoney;
    } while (amountOfMoney < 100);

    cout << endl;
    cout << "You deposited " << amountOfMoney << " kr." << endl;

    cout << endl;
    return amountOfMoney;
}

int betMoney(){
    int bet;
    int depositedMoney;

    depositedMoney = depositMoney();

    // The amount of money the user wants to bet.
    do {
        cout << "You have " << depositedMoney << " kr deposited and must use more than 100 of them." << endl;
        cout << endl;
        cout << "You also need to bet an amount of money that is at least 100 kr and not above your total deposit. (Type in the amount you want to bet).\n"
                "How much do you want to bet?: ";
        cin >> bet;
        cout << endl;
    } while (bet < 100 || bet > depositedMoney);

    return bet;
}