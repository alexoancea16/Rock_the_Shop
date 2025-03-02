// Operator class - subclass of the Employee class
// Type of employee

#include "Employee.h"

#pragma once

using namespace std;

class Operator : public Employee
{
    private:
        const float salaryCoefficient = 1;
        // vectorul de comenzi 

    public:
        Operator() = default; // Default constructor
        Operator(string,string,string,string); // Default constructor with arguments

        // Method for calculate salary
        float getSalary() const override;

        // Methods for reading and display data
        friend ostream& operator<<(ostream&, Operator&);
        friend istream& operator>>(istream&, Operator&);
};