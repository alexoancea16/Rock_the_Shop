// Header to implementation main functionality 
#include <iostream>
#include <fstream>

#include <vector>
#include <memory>

#include "Employee.h"
#include "Manager.h"
#include "Assistant.h"
#include "Operator.h"
#include "Product.h"
#include "Clothes.h"
#include "Disk.h"

// Function for read the list of employee from file and create a list
void readEmployeesFromFile(const string&, vector<unique_ptr<Employee>>&);
// Function for verify if the shop has a minim number of employee
bool verifyNumberOfEmployees(const vector<unique_ptr<Employee>>&);

// Function for read the list of product from file and create a list
void readProductsFromFile(const string&, vector<unique_ptr<Product>>&);
// Function for verify if the shop has a minim number of products in stoc
bool verifyNumberOfProducts(const vector<unique_ptr<Product>>&);

// Function for menu

// Function for first option
// Suboptions
void addEmployee(vector<unique_ptr<Employee>>&);
void employeeManagement(vector<unique_ptr<Employee>>&);

// Function for second option
void productManagement();