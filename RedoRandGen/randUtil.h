#ifndef RANDUTIL_H
#define RANDUTIL_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <limits>
#include <cstdlib>

using namespace std;
using namespace dbu;

int guesses[251];
int guess_count = 0;
int randValue; 

namespace randoms {

    int generateRandomNumber () {
        srand(time(NULL));
        randValue = rand() % 251;
        return randValue;
    }

    void printArray(int array[] , int size){
        cout<<"the entered values are:";
        for(int i= 0 ; i < size ; i++){
            cout << array[i] << "\t";
        }
        cout << endl;
        return ;
    }  

    void isNumberCorrect (int realValue) {
        while(true){
            int guess;
            cout<<"Guess a random value:";
            cin >> guess;
            guesses[guess_count++] = guess;
            if (guess == realValue){
                debugPrint(1,"You win!" );
                break;
            }
            else if (guess > realValue){
                debugPrint(4,"Too high!");
            }
            else {
                debugPrint(4,"Too low!");
            }
        }
        printArray(guesses , guess_count);
        return;
    } 
}

#endif