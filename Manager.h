// Manager class - subclass of the Employee class
// Type of employee 

#include "Employee.h"

#pragma once

using namespace std;

class Manager : public Employee
{
    private:
        const float salaryCoefficient = 1.25;

    public:
        Manager() = default; // Default constructor
        Manager(string,string,string,string); // Default constructor with arguments

        // Method for calculate salary
        float getSalary() const override;

        // Methods for reading and display data
        friend ostream& operator<<(ostream&, Manager&);
        friend istream& operator>>(istream&, Manager&);

        // Method for returnning typology: manager
        string getTypology() const override;
};