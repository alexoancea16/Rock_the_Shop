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

        Employee(); // Default constructor
        Employee(string, string, string, string); // Default constructor with argumets

        // Methods for reading inputs
        void readFirstName(istream&);
        void readSecondName(istream&);
        void constraintCnp();
        void readCnp(istream&);
        void constraintDateOfEmployment();
        void readDateOfEmployment(istream&);
        friend istream& operator>>(istream&, Employee&);
        friend ostream& operator<<(ostream&, const Employee&);

        // Method for calculate salary
        bool giveMoneyGift() const;
        float getBaseSalary() const;
        virtual float getSalary() const = 0;
};