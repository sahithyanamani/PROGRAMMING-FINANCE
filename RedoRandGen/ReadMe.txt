Sahithya Namani
SN807
RUID - 219004323
Assignment-3

Steps to run the code:
1. Unzip the .zip folder
2. Go to command prompt to open the file where it has been saved
3. Type command  g++ RandNumGen.cpp and press enter to compile the code.
4. Now type ./a.out command to run the code.

Flow of instructions:
- When the RandNumGen.cpp file is compiled and executed the main function takes an input values
that can have {0,1} as its value.
- If the user chooses 0 the game ends, and if he chooses 1, in the switch statement calls the play_game() 
function.
- The input is taken from the user until the value given is 0 that is when the game =ends.
- The play_game() function initializes the value randValue to a randdom variable using the
generateRandomNumber() function from the randUtil.h header file.
- It then calls the isNumberCorrect(randValue) and send the generated random value as argument.
- This function prompts the user to input a value and uses the following logic:

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
- After the game ends the final array containing all the guessed values
- int generateRandomNumber () {
        srand(time(NULL));
        randValue = rand() % 251;
        return randValue;
    } 
    The generateRandomNumber() function uses the rand() function to generate a random number and divides 
        it by 251 to get the value of randValue variuable