// Operator class - subclass of the Employee class
// Type of employee

#include "Employee.h"

#pragma once

using namespace std;

class Operator : public Employee
{
    private:
        const float salaryCoefficient = 1;
        float additionFromProcessingOrder = 0;
    public:
        Operator() = default; // Default constructor
        Operator(string, string, string, string, float = 0); // Default constructor with arguments


        // Method for calculate salary
        void setAdditionSalary(float addition);
        float getSalary() const override;

        // Methods for reading and display data
        friend ostream& operator<<(ostream&, Operator&);
        friend istream& operator>>(istream&, Operator&);

        // Method for returnning typology: operator
        string getTypology() const override;
};