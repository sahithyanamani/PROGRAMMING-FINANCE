#include <iostream>
#include <string>

// Define a class called EmployeeDetails to manage employee information
class EmployeeDetails {

    public:
    // Constructor for creating an EmployeeDetails object
    explicit EmployeeDetails(std::string name, int age, std::string designation): EmployeeName(name), EmployeeAge(age), EmployeeDesignation(designation){}
    
    // Setter methods to modify employee details
    void setEmployeeName(std::string name);
    void setEmployeeAge(int age);
    void setEmployeeDesignation(std::string designation);

    // Getter methods to retrieve employee details
    std::string getEmployeeName() const;
    int getEmployeeAge() const;
    std::string getEmployeeDesignation() const;
    
    // Method to display employee details
    void displayDetails () const;

    private:
    
    // Private member variables to store employee information
    std::string EmployeeName;
    int EmployeeAge;
    std::string EmployeeDesignation;
};