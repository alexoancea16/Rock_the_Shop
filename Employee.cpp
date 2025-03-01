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

// Methods for reading input

// Read First Name with constraints: The first name must be between 3 and 30 characters
void Employee::readFirstName(istream &dev)
{
    while(true)
    {
        try // use the exception try - catch
        {
            cout << "Enter the First Name: ";
            dev >> firstName;
            if(firstName.length() < 3 || firstName.length() > 30)
                throw invalid_argument("The first name must be between 3 and 30 characters.");
            break;
        }
        catch(const invalid_argument& e)
        {
            cerr << "Erorr: " << e.what() << endl;
        }
    }
}

// Read Second Name with constraints: The second name must be between 3 and 30 characters
void Employee::readSecondName(istream &dev)
{
    while(true)
    {
        try // use the exception try - catch
        {
            cout << "Enter the Second Name: ";
            dev >> secondName;
            if(secondName.length() < 3 || secondName.length() > 30)
                throw invalid_argument("The second name must be between 3 and 30 characters.");
            break;
        }
        catch(const invalid_argument& e)
        {
            cerr << "Erorr: " << e.what() << endl;
        }
    }
}

// Verify if the CNP is valid
void Employee::constraintCnp()
{
    const string constante = "279146358279";
    int suma, controlComponent;
    // Verify if the CNP has exactly 13 characters
    if (cnp.length() != 13)
    {
        throw invalid_argument("The CNP must have exactly 13 characters!");
    }
    // Veritfy if the CNP contain only numbers
    for (int i = 0; i < cnp.length(); i++)
    {
        if (!isdigit(cnp[i]))
        {
            throw invalid_argument("The CNP must contain only numbers!");
        }
    }
    // Verify control component using the specific equation
    suma = 0;
    for (int i = 0; i < 12; ++i)
    {
        suma += (cnp[i] - '0') * (constante[i] - '0');
    }
    controlComponent = suma % 11;
    if (controlComponent == 10)
    {
        controlComponent = 1;
    }
    if (controlComponent != (cnp[12] - '0'))
    {
        throw invalid_argument("The CNP is invalid: the control component does not match!");
    }
}

// Read the CNP witch respect the constraints.
void Employee::readCnp(istream &dev)
{
    while(true)
    {
        try
        {
            cout << "Enter the CNP: ";
            dev >> cnp;
            constraintCnp();
            break;
        }
        catch(const invalid_argument &e)
        {
            cerr << "Erorr: " << e.what() << endl;
        }
    }
}

// Verify if the date is valid
void Employee::constraintDateOfEmployment()
{
    // Validate the format
    if(dateOfEmployment.length() != 10 || dateOfEmployment[2] != '.' || dateOfEmployment[5] != '.')
    {
        throw invalid_argument("The date of employment must be in the format DD.MM.YYYY!");
    }
    if(!isdigit(dateOfEmployment[0]) || !isdigit(dateOfEmployment[1]) || 
    !isdigit(dateOfEmployment[3]) || !isdigit(dateOfEmployment[4]) ||
    !isdigit(dateOfEmployment[6]) || !isdigit(dateOfEmployment[7]) ||
    !isdigit(dateOfEmployment[8]) || !isdigit(dateOfEmployment[9]))
    {
        throw invalid_argument("The date of employment must be in the format DD.MM.YYYY with only numeric values!");
    }
    // Convert date
    int day = stoi(dateOfEmployment.substr(0, 2));
    int month = stoi(dateOfEmployment.substr(3, 2));
    int year = stoi(dateOfEmployment.substr(6, 4));
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1990)
    {
        throw invalid_argument("Date of employment is not valid!");
    }
    // Birthday from CNP
    int yearBirth = stoi(cnp.substr(1, 2));
    int monthBirth = stoi(cnp.substr(3, 2));
    int dayBirth = stoi(cnp.substr(5, 2));
    if(cnp[0] == '1' || cnp[0] == '2')
    {
        yearBirth += 1900;
    }
    else if(cnp[0] == '3' || cnp[0] == '4')
    {
        yearBirth += 1800;
    }
    else if(cnp[0] == '5' || cnp[0] == '6')
    {
        yearBirth += 2000;
    }
    // Verify if the employee is 18 years old
    if(year - yearBirth < 18 || (year - yearBirth == 18 && (month < monthBirth || (month == monthBirth && day < dayBirth)))) 
    {
        throw invalid_argument("The employee must be at least 18 years old at the date of employment!");
    }
    
}

// Read the date of emplyment 
void Employee::readDateOfEmployment(istream &dev)
{
    while(true)
    {
        try
        {
            cout << "Enter the date of employment (dd.mm.yyyy): ";
            dev >> dateOfEmployment;
            constraintDateOfEmployment();
            break;
        }
        catch(const invalid_argument &e)
        {
            cerr << "Erorr: " << e.what() << endl;
        }
    }
}

// Read operator
istream& operator>>(istream &dev, Employee& employee)
{
    employee.id = Employee::idCount++;
    employee.readFirstName(dev);
    employee.readSecondName(dev);
    employee.readCnp(dev);
    employee.readDateOfEmployment(dev);
    return dev;
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

// Method for calculate salary
float Employee::getBaseSalary() const
{
    // Calculate current year
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    // Calculate Years of experience
    int yearOfExperience = (now->tm_year + 1900) - stoi(dateOfEmployment.substr(6, 4));
    // Return base salary
    return (float)(basicSalary + yearOfExperience * 100);
}