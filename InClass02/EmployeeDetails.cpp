#include <iostream>
#include "EmployeeDetails.h"
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;


/*
    //EmployeeDetails::EmployeeDetails(string name, int age, string designation)
{
    setEmployeeName(name);
    setEmployeeAge(age);
    setEmployeeDesignation(designation);
}
*/

// Setter method for EmployeeName
void EmployeeDetails::setEmployeeName(std::string name)
{
    EmployeeName = name;
    
}

// Setter method for EmployeeAge
void EmployeeDetails::setEmployeeAge(int age)
{
    EmployeeAge = age;

}

// Setter method for EmployeeDesignation
void EmployeeDetails::setEmployeeDesignation(std::string designation)
{
    EmployeeDesignation = designation;
}

// Getter method for EmployeeName
string EmployeeDetails::getEmployeeName() const {
    
    return EmployeeName;
}

// Getter method for EmployeeAge
int EmployeeDetails::getEmployeeAge() const {
    
    return EmployeeAge;
}

// Getter method for EmployeeDesignation
string EmployeeDetails::getEmployeeDesignation() const {
    
    return EmployeeDesignation;
}

// Method to display employee details
void EmployeeDetails::displayDetails() const {
    std::cout << "Welcome " <<  getEmployeeName() << "!" << std::endl;
    std::cout << "Age: " << getEmployeeAge() << std::endl;
    std::cout << "Designation: " << getEmployeeDesignation() << std::endl;
    std::cout << std::endl;
}