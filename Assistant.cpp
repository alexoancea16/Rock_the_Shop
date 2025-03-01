// Functionalty of Assistant class

#include "Assistant.h"

// Default contructor with arguments which calls the base class constructor 
Assistant::Assistant(string firstName, string secondName, string cnp, string dateOfEmployment) : 
    Employee(firstName, secondName, cnp, dateOfEmployment) {}

// Method for calculate Salary
float Assistant::getSalary() const
{
    if(giveMoneyGift())
        return getBaseSalary() * salaryCoefficient + 100;
    return getBaseSalary() * salaryCoefficient;
}

// Methods for display data
ostream& operator<<(ostream& dev, Assistant& assistant)
{
    dev << "Assistant" << endl;
    dev << (Employee&)assistant;
    dev << "Salary: " << assistant.getSalary() << " lei" << endl;
    return dev;
}

// Methods for reading inputs
istream& operator>>(istream& dev, Assistant& assistant)
{
    dev >> (Employee&)assistant;
    return dev;
}