// Implementation main functionality

#include "Implementation.h"

// Function for read the list of employee from file and create a list
void readEmployeesFromFile(const string& nameFile, vector<unique_ptr<Employee>>& employeeList)
{
    ifstream file(nameFile);
    if (!file.is_open())
    {
        cout << "Erorr open file! " << endl;
        return;
    }
    string type, firstName, secondName, cnp, dateOfEmployment;
    while (file >> type >> firstName >> secondName >> cnp >> dateOfEmployment)
    {
        if (type == "Manager")
        {
            employeeList.push_back(make_unique<Manager>(firstName, secondName, cnp, dateOfEmployment));
        }
        else if (type == "Assistant")
        {
            employeeList.push_back(make_unique<Assistant>(firstName, secondName, cnp, dateOfEmployment));
        }
        else if (type == "Operator")
        {
            employeeList.push_back(make_unique<Operator>(firstName, secondName, cnp, dateOfEmployment));
        }
        else
        {
            cout << "The type is not in list " << endl;
        }
    }
    file.close();
}

// Function for verify if the shop has a minim number of employee
bool verifyNumberOfEmployees(const vector<unique_ptr<Employee>>& employeeList)
{
    int numberOfManagers = 0, numberOfOperators = 0, numarOfAssistants = 0;
    for(const auto& employee : employeeList)
    {
        string type = employee->getTypology();
        if (type == "Manager")
            numberOfManagers++;
        else if (type == "Operator")
            numberOfOperators++;
        else if (type == "Assistant")
            numarOfAssistants++;
    }
    return numberOfManagers >= 1 && numberOfOperators >= 3 && numarOfAssistants >= 1;
}

// Function for read the list of product from file and create a list
void readProductsFromFile(const string& nameOfFile, vector<unique_ptr<Product>>& productsList)
{
    ifstream file(nameOfFile);
    if (!file.is_open())
    {
        cout << "Erorr open file!" << endl;
        return;
    }
    string type;
    while (file >> type)
    {
        if (type == "Disk")
        {
            string name, recordLabel, date, band, nameOfAlbum;
            int numberOfProducts;
            float basePrice;
            bool typology;
            file >> name >> numberOfProducts >> basePrice >> typology >> recordLabel >> date >> band >> nameOfAlbum;
            productsList.push_back(make_unique<Disk>(name, numberOfProducts, basePrice, typology, recordLabel, date, band, nameOfAlbum));
        }
        else if (type == "Clothes")
        {
            string name, color, brand;
            int numberOfProducts;
            float basePrice;
            file >> name >> numberOfProducts >> basePrice >> color >> brand;
            productsList.push_back(make_unique<Clothes>(name, numberOfProducts, basePrice, color, brand));
        }
        else
        {
            cout << "The type is not in list!" << endl;
        }
    }
    file.close();
}

// Function for verify if the shop has a minim number of products in stoc
bool verifyNumberOfProducts(const vector<unique_ptr<Product>>& productsList)
{
    int numberOfDisk = 0, numberOfClothes = 0;
    for (const auto& product : productsList)
    {
        string type = product->getTypology();
        if (type == "Disk")
            numberOfDisk++;
        else if (type == "Clothes")
            numberOfClothes++;
    }
    return numberOfDisk >= 2 && numberOfClothes >= 2;
}

// Function for menu
// Option 1
void addEmployee(vector<unique_ptr<Employee>>& employeeList)
{
    system("cls");
    cout << "What type of employee do you want to add?" << endl;
    cout << "1. Manager" << endl;
    cout << "2. Assistant" << endl;
    cout << "3. Operator" << endl;
    cout << "Enter your option: ";
    int option;
    cin >> option;
    switch (option)
    {
        case 1:
            employeeList.push_back(make_unique<Manager>());
            cin >> *employeeList.back();
            break;
        case 2:
            employeeList.push_back(make_unique<Assistant>());
            cin >> *employeeList.back();
            break;
        case 3:
            employeeList.push_back(make_unique<Operator>());
            cin >> *employeeList.back();
            break;
        default:
            cout << "Invalid option!" << endl;
    }
}

// Option 2
void deleteEmployee(vector<unique_ptr<Employee>>& employeeList)
{
    system("cls");
    cout << "Enter the index of the employee to be deleted (1 - " << employeeList.size() << "): ";
    int index;
    cin >> index;
    if (index < 1 || index > employeeList.size())
    {
        cout << "Invlid index!" << endl;
    }
    else
    {
        employeeList.erase(employeeList.begin() + (index - 1));
        cout << "Employee was delete" << endl;
    }
}

// Option 3
void editSecondName(vector<unique_ptr<Employee>>& employeeList)
{
    system("cls");
    cout << "Enter the index of the employee to be deleted (1 - " << employeeList.size() << "): ";
    int index;
    cin >> index;
    if(index < 1 || index > employeeList.size())
    {
        cout << "Invalid index!" << endl;
    }
    else
    {
        employeeList[index - 1]->editSecondName();
    }
}

// Option 4
void displayEmployeeData(vector<unique_ptr<Employee>>& employeeList)
{
    system("cls");
    cout << "Enter the index of the employee to be deleted (1 - " << employeeList.size() << "): ";
    int index;
    cin >> index;
    if (index < 1 || index > employeeList.size())
    {
        cout << "Invalid index!" << endl;
    }
    else
    {
        cout << *employeeList[index - 1] << endl;
    }
}

// Option 5
void displayAllEmployeeData(vector<unique_ptr<Employee>>& employeeList)
{
    system("cls");
    if (employeeList.empty())
    {
        cout << "The List is empty!" << endl;
    }
    else
    {
        cout << "Employee list:" << endl;
        for (int i = 0; i < employeeList.size(); ++i)
        {
            cout << "Employee " << i + 1 << ":" << endl;
            cout << *employeeList[i] << endl;
        }
    }
}

// Function for first option
void employeeManagement(vector<unique_ptr<Employee>>& employeeList)
{
    system("cls");
    int option;
    do
    {
        system("cls");
        cout << "Employee managemnt" << endl << endl;
        cout << "Choose one of the options below!" << endl;
        cout << "1. Add employee." << endl;
        cout << "2. Delete employee." << endl;
        cout << "3. Edit secondName." << endl;
        cout << "4. Display employee data." << endl;
        cout << "5. Display all employee data." << endl;
        cout << "6. Close this section." << endl << endl;
        cout << "Enter your option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            addEmployee(employeeList);
            sleep(5);
            break;
        case 2:
            system("cls");
            deleteEmployee(employeeList);
            sleep(5);
            break;
        case 3:
            system("cls");
            editSecondName(employeeList);
            sleep(5);
            break;
        case 4:
            system("cls");
            displayEmployeeData(employeeList);
            sleep(20);
            break;
        case 5:
            system("cls");
            displayAllEmployeeData(employeeList);
            sleep(20);
            break;
        case 6: 
            system("cls");
            cout << "Close this section. Thank you!" << endl;
            sleep(5);
            break;
        default:
            system("cls");
            cout << "Invalid option!" << endl;
            sleep(5);
            break;
        }
    } while(option != 6);   
}