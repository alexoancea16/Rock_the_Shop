// Assistant class - subclass of the Employee class
// Type of employee

#include "Employee.h"

#pragma once

using namespace std;

class Assistant : public Employee
{
    private:
        const float salaryCoefficient = 0.75;
    
    public:
        Assistant() = default; // Default constructor
        Assistant(string, string, string, string); // Default constructor with arguments

        // Method for calculate salary
        float getSalary() const override;

        // Methods for reading and display data
        friend ostream& operator<<(ostream&, Assistant&);
        friend istream& operator>>(istream&, Assistant&);

        // Method for returnning typology: assistant
        string getTypology() const override;
};