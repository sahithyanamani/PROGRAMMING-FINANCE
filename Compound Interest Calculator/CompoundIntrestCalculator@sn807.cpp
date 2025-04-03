#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <sstream>
#include <typeinfo>
#include <stdlib.h>
#include <math.h>

#define RESET    "\033[0m"
#define BLACK    "\033[30m"
#define RED      "\033[31m"
#define GREEN    "\033[32m"
#define YELLOW   "\033[33m"
#define BLUE     "\033[34m"
#define MAGENTA  "\033[35m"
#define CYAN     "\033[36m"
#define WHITE    "\033[37m"
#define BOLDBLACK    "\033[1m\033[30m"
#define BOLDRED      "\033[1m\033[31m"
#define BOLDGREEN    "\033[1m\033[32m"
#define BOLDYELLOW   "\033[1m\033[33m"
#define BOLDBLUE     "\033[1m\033[34m"
#define BOLDMAGENTA  "\033[1m\033[35m"
#define BOLDCYAN     "\033[1m\033[36m"
#define BOLDWHITE    "\033[1m\033[37m"

using namespace std;

int debugLevel = 1;

double compdInterestCcltr(double principle, float period, float itrstRate, int periodNum);
void debugPrint(int dL, string statement);

double compdInterestCcltr(double principle, float period, float itrstRate, int periodNum) {

    double rn = (double)(itrstRate / period);
    double A = principle * (pow((1 + rn), periodNum * period));
    return A - principle;
}

void debugPrint(int dL, string statement) {

        if (dL < debugLevel) {
            return;
        }
        if (dL == 1) {
            cout << GREEN << "INFO: " << statement << RESET << endl;
        } else if (dL == 2) {
            cout << BOLDCYAN << "WARNING: " << statement << RESET << endl;
        } else if (dL == 3) {
            cout << YELLOW << "ERROR: " << statement << RESET << endl;
        } else if (dL == 4) {
            cout << MAGENTA << "SEVERE: " << statement << RESET << endl;
        } else if (dL == 5) {
            cout << BOLDRED << "FATAL: " << statement << RESET << endl;
            exit(EXIT_FAILURE);
        }  else {
            cout << "Sepecified debug level: " << dL << " is not defined in debugPrint function\n";
            exit(EXIT_FAILURE);
        }
}

int main() {
    
    double principle;
    float period;
    float itrstRate;
    int periodNum;
    cout << "Enter the value for Principle: " << "\n";
    cin >> principle;
    cout << "Enter the Number of times interest gets compounded per period: " << "\n";
    cin >> period;
    cout << "Enter the value for Interest Rate: " << "\n";
    cin >> itrstRate;
    cout << "Enter the Number of periods the money is invested for: " << "\n";
    cin >> periodNum;

    if(principle < 0 || period < 0 || itrstRate < 0 || periodNum < 0) {
        string statement = "Calculation needs positive values only\n";
        debugPrint(3, statement);
    } else if(period == 0.0) {
        string statement = "The period cannot be 0!\n";
        debugPrint(5, statement); 
    } else if(itrstRate == 0.0) {
        string statement = "The Interest Rate cannot be 0!\n";
        debugPrint(4, statement); 
    } else if(periodNum == 0.0) {
        string statement = "The time span cannot be 0!\n";
        debugPrint(5, statement); 
    } 
    else {
        double compoundInterest = compdInterestCcltr(principle, period, itrstRate, periodNum);
        string statement = "Compound Interest";
        debugPrint(1, statement);
        

        cout<< compoundInterest << "\n";
    }
    return 0;
}
