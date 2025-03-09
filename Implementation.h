// Header to implementation main functionality 
#include <iostream>
#include <fstream>
#include <unistd.h>

#include <vector>
#include <queue>
#include <memory>
#include <chrono>
#include <thread>

#include "Employee.h"
#include "Manager.h"
#include "Assistant.h"
#include "Operator.h"
#include "Product.h"
#include "Clothes.h"
#include "Disk.h"
#include "Order.h"

// Function for read the list of employee from file and create a list
void readEmployeesFromFile(const string&, vector<unique_ptr<Employee>>&);
// Function for verify if the shop has a minim number of employee
bool verifyNumberOfEmployees(const vector<unique_ptr<Employee>>&);

// Function for read the list of product from file and create a list
void readProductsFromFile(const string&, vector<unique_ptr<Product>>&);
// Function for verify if the shop has a minim number of products in stoc
bool verifyNumberOfProducts(const vector<unique_ptr<Product>>&);

// Function for read the list of order from file and create a list
void readOrderFromFile(const string&, vector<Order>&, const vector<unique_ptr<Product>>&);

// Function for menu

// Function for first option
// Suboptions
void addEmployee(vector<unique_ptr<Employee>>&);
void deleteEmployee(vector<unique_ptr<Employee>>&);
void editSecondName(vector<unique_ptr<Employee>>&);
void displayEmployeeData(vector<unique_ptr<Employee>>&);
void displayAllEmployeeData(vector<unique_ptr<Employee>>&);
void employeeManagement(vector<unique_ptr<Employee>>&);

// Function for second option
// Suboption
void addProduct(vector<unique_ptr<Product>>&);
void deleteProduct(vector<unique_ptr<Product>>&);
void editProduct(vector<unique_ptr<Product>>&);
void displayProductsDetails(vector<unique_ptr<Product>>&);
void displayAllProductsDetails(vector<unique_ptr<Product>>&);
void productManagement(vector<unique_ptr<Product>>&);

// Function for third option
// Suboption
void displayAllOrders(vector<Order>&, const vector<unique_ptr<Product>>&);
void manageAviableOrders(queue<Order>&, vector<unique_ptr<Employee>>&);
void orderManagement(vector<Order>&, const vector<unique_ptr<Product>>&, queue<Order>&, vector<unique_ptr<Employee>>&);