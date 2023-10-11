#include <iostream>
#include <ctime>
using namespace std;

int main(){
    // Variables.
    int age, depositedMoney, stake, totalWinToday = 0, playAgain;
    bool play = true;

    // Welcomes the user.
    cout << "Welcome!\n"
            "How old are you?: ";
    cin >> age;

    while(play == true){
        // If the age of the user is 18 or above and wants to play again, they get to play.
        if (age >= 18){
            cout << endl;
            cout << "ah";

            // The amount of money the user wants to bet.
            do {
                cout << "You need to deposit an amount of money that's at least 100 kr. (Type in the amount you want to deposit).\n"
                        "How much do you want to deposit?: ";
                cin >> depositedMoney;
            } while (depositedMoney > 99);
        }
    }

    return 0;
}