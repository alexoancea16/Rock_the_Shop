// Product class
// The base class to describe the main characteristics of all types of products

#include <iostream>
#include <string>
#include <ctime>
#pragma once

using namespace std;

class Product 
{
    protected:
        int code;
        string name;
        int numberOfProducts;
        float basePrice;
    
    public:
        static int codeCount;
        Product(); // Default constructor
        Product(string, int, float); // Default constructor with argumets
        
        // Methods for read and display data
        friend ostream& operator<<(ostream&, const Product&);
        friend istream& operator>>(istream&, Product&);

        // Methof for editing products
        void editProduct(); 

        // Method for returnning typology of product
        virtual string getTypology() const = 0;

        // Method for returnning price
        virtual float getPrice() const = 0; // Pure virtual method for price

        // Method for getter
        int getCode();
        int getNumberOfProducts();
        string getName();

        // Method for update stock
        void stockUpdate(int);

        // Another method
        void editProductDetails();
};