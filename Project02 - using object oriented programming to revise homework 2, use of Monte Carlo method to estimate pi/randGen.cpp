#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <sstream>
#include <typeinfo>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <fstream>
#include "randGen.h"

using namespace std;

// Initialize the static variable `debugLevel` in the `DebugPrint` class to 1
int DebugPrint::debugLevel = 1;

// Set the debug level in the `DebugPrint` class
void DebugPrint::setDebugLevel(int dl) 
{
    debugLevel = dl;
}

// Get the current debug level from the `DebugPrint` class
int DebugPrint::getDebugLevel() 
{
    return debugLevel;
}

// Print debug statements based on the debug level
void DebugPrint::print(int dL, string statement) 
{
    // Check if the debug level is below the set debug level
    if (dL < debugLevel) 
    {
        return;
    }
    // Output different types of debug messages based on the debug level
    if (dL == 1) 
    {
        cout << GREEN << "INFO: " << statement << RESET << endl;
    } else if (dL == 2) 
    {
        cout << BOLDCYAN << "WARNING: " << statement << RESET << endl;
    } else if (dL == 3) 
    {
        cout << YELLOW << "ERROR: " << statement << RESET << endl;
    } else if (dL == 4) 
    {
        cout << MAGENTA << "SEVERE: " << statement << RESET << endl;
    } else if (dL == 5) 
    {
        cout << BOLDRED << "FATAL: " << statement << RESET << endl;
        exit(EXIT_FAILURE);
    } else 
    {
        cout << "Sepecified debug level: " << dL << " is not defined in debugPrint function\n";
        exit(EXIT_FAILURE);
    }
}

// Constructor for the `RandGen` class
RandGen::RandGen(int rng, int ctr) : range(rng), cntr(ctr) 
{
    srand(time(NULL));
}

// Set the range for random number generation
void RandGen::setRange(int rng) 
{
    range = rng;
}

// Get the current range for random number generation
int RandGen::getRange() 
{
    return range;
}

// Set the counter for random number generation
void RandGen::setCntr(int ctr) 
{
    cntr = ctr;
}

// Read the current counter for random number generation
int RandGen::readCntr() 
{
    return cntr;
}

// Generate a random point with two coordinates
double* RandGen::genPoint() 
{
    for (int i = 0; i < 2; ++i) 
    {
        
        point[i] = (double) (rand() % range) / range;
    }
    return point;
}

// Calculate the distance of the generated point from the origin
double RandGen::distance() 
{
    double x1 = point[0];
    double y1 = point[1];

    return ((x1 * x1) + (y1 * y1));
}

// Constructor for the `FindPi` class
FindPi::FindPi() : estimatedResults(0.0) {}

// Set the estimated results for π calculation
void FindPi::setEstmResults(double estmResults) 
{
    estimatedResults = estmResults;
}

// Get the estimated results for π calculation
double FindPi::getEstmResults() 
{
    return estimatedResults;
}

// Run the estimation of π using Monte Carlo method
double FindPi::runEstimation(int itr, int randLimit) 
{

    if(itr <= 0)
    {
        DebugPrint dbu;
        dbu.print(3, "Total iterations must be a positive value");
        return 0;
    }

    int insideCircle = 0;

    // we are not keeping track of the total values because it is already inputed as itr variable

    RandGen randGen(randLimit, itr);

    for (int i = 0; i < itr; ++i) 
    {
        randGen.genPoint();
        double dist = randGen.distance();

        if (dist <= 1) 
        {
            insideCircle+=1;
        }
    }
    estimatedResults = (double) (4.0 * insideCircle) / itr;
    return estimatedResults;
}

