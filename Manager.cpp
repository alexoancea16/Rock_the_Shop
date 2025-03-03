// Functionalty of Manager class

#include "Manager.h"

// Default contructor with arguments which calls the base class constructor 
Manager::Manager(string firstName, string secondName, string cnp, string dateOfEmployment) : 
    Employee(firstName, secondName, cnp, dateOfEmployment) {}

// Method for calculate Salary
float Manager::getSalary() const
{
    return getBaseSalary() * salaryCoefficient;
}

// Methods for display data
ostream& operator<<(ostream& dev, Manager& manager)
{
    dev << "Manager" << endl;
    dev << (Employee&)manager;
    dev << "Salary: " << manager.getSalary() << " lei" << endl;
    return dev;
}

// Methods for reading inputs
istream& operator>>(istream& dev, Manager& manager)
{
    dev >> (Employee&)manager;
    return dev;
}

// Method for returnning typology: manager
string Manager::getTypology() const
{
    return "Manager";
}