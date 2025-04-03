#include <iostream>
#include <string>
#include "debugUtil.h"
#include "randUtil.h"

using namespace std;
using namespace randoms;
using namespace dbu;

void play_game();

void play_game(){
    int randValue;
    randValue =  randoms::generateRandomNumber();
    cout << "Guess the number" <<endl;
    randoms::isNumberCorrect(randValue);
    return;
}

int main(){
    int choice;
    cout << "Please chose the following options \n";
    do {
        cout << "0. Quit" << endl;
        cout << "1. Play Game " << endl;
        cin >> choice;

        switch(choice){
            case 0:
                cout << "Game Over !Thanks for playing the game \n"; 
                break;
            case 1:
                play_game();
                break;
            default:
                debugPrint(3 , "Invalid Choice");
                break;
        }   
    } while(choice != 0);

    return 0;
}
