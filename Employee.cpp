// Functionalty of Employee class

#include "Employee.h"

int Employee::idCount = 0;

// Default constructor
Employee::Employee()
{
    idCount++;
    id = idCount;
}

// Default constructor with arguments
Employee::Employee(string firstName, string secondName, string cnp, string dateOfEmployment):
    firstName(firstName), secondName(secondName), cnp(cnp), dateOfEmployment(dateOfEmployment)
{
    idCount++;
    id = idCount;
}

// Display operator - display in the console
ostream& operator<<(ostream &dev, const Employee& employee)
{
    dev << "Employee details:" << endl;
    dev << "Id: " << employee.id << endl;
    dev << "Fist Name: " << employee.firstName << endl;
    dev << "Second Name: " << employee.secondName << endl;
    dev << "CNP: " << employee.cnp << endl;
    dev << "Date of employment: " << employee.dateOfEmployment << endl;
    return dev;
}