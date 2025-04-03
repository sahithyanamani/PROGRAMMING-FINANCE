#include "randGen.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

/****
 rand() returns a pseudo-random number in the range of 0 to RAND_MAX
 after compile, the sequence in generating the random number is fixed,
 so for every run, rand() generates the same sequence of random number
 srand() comes to rescue for this problem
 srand() sets the starting point for rand(), the starting point needs only be seeded once,
 before calls to rand(), and the start of the program.  It should not be repeatedly seeded,
 or reseeded every time you wish to generate a new batch of pseudo-random numbers.  That means
 srand(time(null)) needs to be called once in a program life time.  time() returns a different
 value everytime, and hence the pseudo-random number vary for every program call.
 srand() sets the seed which is used by rand to generate random number.
*/

int main(int argc, char* argv[]) {
    // use current time as seed for random generator
    srand(time(NULL));
    RandGen rGenObj;
    DebugPrint dbug;
    FindPi estmPiObj;
    int itrCnt = 0;
    int maxRange = RAND_MAX;
    double myEstm;

    // Test user defined objects: 
    // dbug.setDebugLevel(1);
    // double dist = rGenObj.distance();
    // dbug.print(2, "dist=" + std::to_string(dist));
    // dbug.print(1, "RandGen.cntr=" + std::to_string(rGenObj.readCntr()));
    // cout << rGenObj.getRange() << endl;
    
    if (argc < 3) {
        cout << "\nToo few arguments for program to work!\n";
        cout << "Usage: " << argv[0] << " darts radius" << endl;
        cout << "     : " << argv[0] << " darts radius debugLevel\n" << endl;
        return 0;
    } else if (argc == 2) {
        itrCnt = atoi(argv[1]);
        myEstm = estmPiObj.runEstimation(itrCnt, RAND_MAX);
    } else if (argc == 3) {
        itrCnt = atoi(argv[1]);
        maxRange = atoi(argv[2]);
        myEstm = estmPiObj.runEstimation(itrCnt, maxRange);
    } else if (argc == 4) {
        itrCnt = atoi(argv[1]);
        maxRange = atoi(argv[2]);
        dbug.setDebugLevel(atoi(argv[3]));
        myEstm = estmPiObj.runEstimation(itrCnt, maxRange);
    } else {
        cout << "\nToo many arguments for program to work!\n";
        cout << "Usage: " << argv[0] << " darts radius\n" << endl;
        return 0;
    }
    
    cout << "Estimated pi: " << myEstm << endl;

    return 0;
}
