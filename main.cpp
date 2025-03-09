// Rock the Shop - Store management system
// Main program with principals functionalities

#include <iostream>
#include <fstream>

#include "Implementation.h"

using namespace std;

int main()
{
    // Vector for employee
    vector<unique_ptr<Employee>> listEmployees;
    readEmployeesFromFile("Employee.txt", listEmployees); // Read employee from file
    // Vector for product
    vector<unique_ptr<Product>> listProducts;
    readProductsFromFile("Product.txt", listProducts);

    // Vector for order
    vector<Order> listOrder;
    readOrderFromFile("Order.txt", listOrder, listProducts);

    // Queue for aviable orders
    queue<Order> availableOrders;

    // Create the menu
    int option;
    do
    {
        if(!verifyNumberOfEmployees(listEmployees))
        {
            cout << "The store cannot operate. At least one manager, three operators, and one assistant are required." << endl;
            return 1;
        }
        if(!verifyNumberOfProducts(listProducts))
        {
            cout << "The store cannot function. It is necessary to have at least two products of each type (Records, VintageRecords, Items)." << endl;
            return 1;
        }
        system("cls");
        cout << "Rock the shop" << endl << endl;
        cout << "Choose one of the options below!" << endl;
        cout << "1. Employee management." << endl;
        cout << "2. Product management." << endl;
        cout << "3. Order management." << endl;
        cout << "4. Close program." << endl << endl;
        cout << "Enter your option: ";
        cin >> option;
        switch (option)
        {
            case 1:
                system("cls");
                employeeManagement(listEmployees);  
                break;
            case 2:
                system("cls");
                productManagement(listProducts);
                break;
            case 3:
                system("cls");
                orderManagement(listOrder, listProducts, availableOrders, listEmployees);
                break;
            case 4:
                system("cls");
                cout << "Close the program! Thank you!" << endl;
                break;
            default:
                system("cls");
                cout << "Invlid option!" << endl;
                break;
        }
    } while (option != 4);
    return 0;
}