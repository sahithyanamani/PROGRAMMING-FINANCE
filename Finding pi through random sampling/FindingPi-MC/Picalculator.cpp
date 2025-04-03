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

using namespace std;

int main() 
{
    // declaring the variables
    double x_cord, y_cord, pi;
    int totalIterations;

    cout << "Enter the total number of Interations:\n";
    cin >> totalIterations;
    
    // if the value of iterations is <0
    if(totalIterations <= 0)
    {
        cout << "Please enter a value greater than 0 as the number of iterations muct be greater than 0!\n";
        return 0;
    }

    // initialize two variables to keep track of the points generated na dpoints falling in the circle area

    int circle_count = 0;
    int square_count = 0;

    srand(time(NULL));

    // Open and write the values to the file!
    ofstream file;
    file.open("values.txt");
    ofstream MyExcelFile;
    MyExcelFile.open("values_ex.csv");

    for(int i = 0; i < totalIterations; i++) {
        x_cord = (double) (rand() * 1.0) / RAND_MAX;
        y_cord = (double) (rand() * 1.0) / RAND_MAX;

        //writing the coordinates to the files
        file << x_cord << " " << y_cord << "\n";
        MyExcelFile << x_cord << "," << y_cord << endl;

    
        // calculating the distance from origin
        double org_distance = x_cord * x_cord + y_cord * y_cord;
        if (org_distance <= 1) 
        {
            // if the point lies within the circle area then we increment circle count
            circle_count+=1;
        }
        // we will keep track of all the points generated
        square_count +=1;
    }
    // calculating pi value as per formula
    pi = (double) (4.0 * circle_count) / square_count;

    // printing the value of pi
    cout << "Value of pi from this experiment : " << pi << "\n";
    MyExcelFile.close();

    return 0;
}