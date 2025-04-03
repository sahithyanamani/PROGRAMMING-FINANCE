#include <iostream>

using namespace std;

int countBinStr(int n);


int main()
{
    
    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;
    int values = countBinStr(n);
    cout << "Number of binary strings of length n that do not have two consecutive 0's:";
    cout << values << endl;

    return 0;
}

int  countBinStr(int n ){
    if(n==0)
    {
        return 1; // An empty string is a valid binary string
    }
    if (n==1)
    {
        return 2; // "0" and "1" are valid binary strings of length 1
    }

    // To count binary strings of length n without consecutive 0's,
    // we have two choices for the first digit: 0 or 1.
    // If we choose 0 for the first digit, the next digit must be 1.
    // If we choose 1 for the first digit, the next digit can be 0 or 1.
    // So, recursively calculate for n-1 and n-2 and sum them.
    return countBinStr(n-1) + countBinStr(n-2);
} 