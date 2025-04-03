#ifndef DEBUGUTIL_H
#define DEBUGUTIL_H

#include <iostream>
#include <string>
#include <stdlib.h>

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

using std::cout;
using std::endl;
using std::string;

int debugLevel = 1;

/**
 * 
void debugPrint(int dL, string statement);
void prBoldYellow(string statement);

int main() {
    prBoldYellow("Bold Yellow Statement");

    debugPrint(1, "this is INFO message");
    debugPrint(2, "this is a WARNING message");
    debugPrint(3, "this is an ERROR message");
    debugPrint(4, "this is an SEVERE message");
    debugPrint(5, "this is an FATAL message");

    return 0;
}

 */

namespace dbu {

    void prBoldYellow (string statement) {
        cout << BOLDYELLOW << statement << RESET << endl;
    }

    void debugPrint(int dL, string statement) {

        // cout << "debugLevel=" << debugLevel << '\n';
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
}

#endif