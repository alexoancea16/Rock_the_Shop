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

// Function for read the list of order from file and create a list
void readOrderFromFile(const string& nameOfFile, vector<Order>& orders, const vector<unique_ptr<Product>>& inventory)
{
    ifstream file(nameOfFile);
    if (!file.is_open())
    {
        cout << "Erorr open file!" << endl;
        return;
    }
    time_t orderTimeRaw;
    int processingTime;
    int numDistinctProducts;
    vector<pair<int, int>> products;
    while (file >> orderTimeRaw >> processingTime >> numDistinctProducts) 
    {
        products.clear();
        for (int i = 0; i < numDistinctProducts; ++i) {
            int productCode, quantity;
            file >> productCode >> quantity;
            products.emplace_back(productCode, quantity);
        }
        auto orderTime = chrono::system_clock::from_time_t(orderTimeRaw);
        Order newOrder(orderTime, processingTime, numDistinctProducts, products);
        newOrder.setOrder(inventory);
        orders.push_back(newOrder);
    }
    file.close();
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

// Function for second option
// Function for menu
// Option 1
void addProduct(vector<unique_ptr<Product>>& productsList)
{
    cout << "What type of product do you want to add?" << endl;
    cout << "1. Disk" << endl;
    cout << "2. Clothes" << endl;
    cout << "Enter your option: ";
    int type;
    cin >> type;
    switch (type)
    {
        case 1:
            productsList.push_back(make_unique<Disk>());
            cin >> *productsList.back();
            break;
        case 2:
            productsList.push_back(make_unique<Clothes>());
            cin >> *productsList.back();
            break;
        default:
            cout << "Your option is not valid" << endl;
    }
}

// Option 2
void deleteProduct(vector<unique_ptr<Product>>& productsList)
{
    cout << "Enter the index of the employee to be deleted (1 - " << productsList.size() << "): ";
    int index;
    cin >> index;
    if (index < 1 || index > productsList.size())
    {
        cout << "Invalid indx!" << endl;
    }
    else
    {
        productsList.erase(productsList.begin() + (index - 1));
        cout << "Product was deleted" << endl;
    }
}

// Option 3
void editProduct(vector<unique_ptr<Product>>& productsList)
{
    cout << "Enter the index of the product to be edit (1 - " << productsList.size() << "): ";
    int index;
    cin >> index;
    if (index < 1 || index > productsList.size())
    {
        cout << "Invalid index!" << endl;
    }
    else
    {
        productsList[index - 1]->editProductDetails();
    }
}

// Option 4
void displayProductsDetails(vector<unique_ptr<Product>>& productsList)
{
    cout << "Enter the index of the product (1 - " << productsList.size() << "): ";
    int index;
    cin >> index;
    if (index < 1 || index > productsList.size())
    {
        cout << "Invalid index!" << endl;
    }
    else
    {
        cout << *productsList[index - 1] << endl;
    }
}

// Option 5
void displayAllProductsDetails(vector<unique_ptr<Product>>& productsList)
{
    if (productsList.empty())
    {
        cout << "The list is empty!" << endl;
    }
    else
    {
        cout << "Products list:" << endl;
        for (int i = 0; i < productsList.size(); ++i)
        {
            cout << "Product " << i + 1 << ":" << endl;
            cout << *productsList[i] << endl;
        }
    }
}

// Function for second option
void productManagement(vector<unique_ptr<Product>>& productsList)
{
    int option;
    do
    {
        system("cls");
        cout << "Product Management" << endl << endl;
        cout << "1. Add product." << endl;
        cout << "2. Delete product." << endl;
        cout << "3. Edit product." << endl;
        cout << "4. Display product details." << endl;
        cout << "5. Display all product details." << endl;
        cout << "6. Close this section." << endl << endl;
        cout << "Enter your option: ";
        cin >> option;
        switch(option)
        {
            case 1:
                system("cls");
                addProduct(productsList);
                sleep(5);
                break;
            case 2:
                system("cls");
                deleteProduct(productsList);
                sleep(5);
                break;
            case 3:
                system("cls");
                editProduct(productsList);
                sleep(5);
                break;
            case 4:
                system("cls");
                displayProductsDetails(productsList);
                sleep(15);
                break;
            case 5:
                system("cls");
                displayAllProductsDetails(productsList);
                sleep(15);
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
    }while(option != 6);
}

// Function for third option
// Suboption
void displayAllOrders(vector<Order>& orders, const vector<unique_ptr<Product>>& productsList)
{
    cout << "Orders: " << endl;
    for (const auto& order : orders) 
    {
        order.displayOrder(productsList);
    }
}

void orderManagement(vector<Order>& orders, const vector<unique_ptr<Product>>& productsList)
{
    int option;
    do
    {
        system("cls");
        cout << "Orders managemnt" << endl;
        cout << "1. Display orders" << endl;
        cout << "2. Power management the valid orders" << endl;
        cout << "3. Close this section" << endl;
        cout << "Enter your option: ";
        cin >> option;
        switch (option)
        {
            case 1:
                system("cls");
                displayAllOrders(orders,productsList);
                sleep(10);
                break;
            case 2:
                system("cls");
                break;
            case 3:
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
    } while (option != 3);  
}