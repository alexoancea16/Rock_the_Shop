// Employee class
// The base class to describe the main characteristics of all types of employees

#include <iostream>
#include <string>
#include <ctime>
#pragma once

using namespace std;

class Employee 
{
    protected:
        int id;
        string firstName;
        string secondName;
        string cnp;
        string dateOfEmployment;

    public:
        static int idCount; // Static variable to count employee id
        const int basicSalary = 3500; // Constant variable to manage each emploee's salary then
        Employee();
        Employee(string, string, string, string);
        friend ostream& operator<<(ostream&, const Employee&);
};