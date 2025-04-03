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

#ifndef RANDGEN_H
#define RANDGEN_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <sstream>
#include <stdlib.h>

// macro or symbolic literals (constants)
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

class DebugPrint {
    static int debugLevel;
    public:
    void setDebugLevel (int dl);    
    int getDebugLevel ();    
    void print(int dL, std::string statement);
};

class RandGen {
    int range;
    int cntr;
    double point[2];
    public:
    RandGen(int rng=RAND_MAX, int ctr=0);
    int getRange();
    void setRange(int rng);
    int readCntr();
    void setCntr(int ctr);
    double* genPoint();
    double distance();
};

class FindPi {
    double estimatedResults;
    public:
    FindPi();
    void setEstmResults(double estmResults);
    double getEstmResults();
    double runEstimation(int itr, int randLimit);
};

#endif