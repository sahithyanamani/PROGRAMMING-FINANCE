#include <iostream>
#include "EmployeeDetails.h"
#include <string>
using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    string EmployeeName;
    int EmployeeAge;
    string EmployeeDesignation;

    // Create two EmployeeDetails objects with initial values
    EmployeeDetails ed1("Andrew", 40, "SWE");
    EmployeeDetails ed2("Aditya", 35, "SDE");

    // Display initial details of employees in ed1 and ed2
    cout << "Initial details of employee in ed1: " << endl;
    ed1.displayDetails();
    cout << "Initial details of employee in ed2: "  << endl;
    ed2.displayDetails();
    
    // Prompt the user to input employee details for ed1
    cout << "Please enter the emp1 Name:" << endl;
    cin >> EmployeeName ;
    cout << "Please enter the emp1 Age:" << endl;
    cin >> EmployeeAge;
    cout << "Please enter the emp1 Designation:" << endl;
    cin >> EmployeeDesignation;
    
    // Update ed1's details using the setter methods
    cout << " updating the details using the setter methods" << endl;
    ed1.setEmployeeName(EmployeeName);
    ed1.setEmployeeAge(EmployeeAge);
    ed1.setEmployeeDesignation(EmployeeDesignation);
    
    cout << endl;

    // Display updated details of ed1
    cout << "After updating the details using the setter methods" << endl;
    ed1.getEmployeeName();
    ed1.getEmployeeAge();
    ed1.getEmployeeDesignation();

    // Display details of both employees using the display function
    cout << "Calling the display function:" << endl;
    ed1.displayDetails();
    ed2.displayDetails();

    return 0;
}