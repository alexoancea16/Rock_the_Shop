// Functionalty of Operator class

#include "Operator.h"

// Default contructor with arguments which calls the base class constructor 
Operator::Operator(string firstName, string secondName, string cnp, string dateOfEmployment, float additionFromProcessingOrder) : 
    Employee(firstName, secondName, cnp, dateOfEmployment), additionFromProcessingOrder(additionFromProcessingOrder) {}

// Method for calculate Salary
void Operator::setAdditionSalary(float addition)
{
    additionFromProcessingOrder += 0.15*addition;
}

float Operator::getSalary() const     // de adaugat procentul din valoarea comenzilor
{
    if(giveMoneyGift())
        return getBaseSalary() * salaryCoefficient + additionFromProcessingOrder + 100;
    return getBaseSalary() * salaryCoefficient + additionFromProcessingOrder;
}

// Methods for display data
ostream& operator<<(ostream& dev, Operator& oper)
{
    dev << "Operator" << endl;
    dev << (Employee&)oper;
    dev << "Salary: " << oper.getSalary() << " lei" << endl;
    return dev;
}

// Methods for reading inputs
istream& operator>>(istream& dev, Operator& oper)
{
    dev >> (Employee&)oper;
    return dev;
}

// Method for returnning typology: operator
string Operator::getTypology() const
{
    return "Operator";
}