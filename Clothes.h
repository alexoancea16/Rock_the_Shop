// Clothes class - subclass of the Product class
// Type of employee

#include "Product.h"

#pragma once

using namespace std;

class Clothes : public Product
{
    private: 
        string color;
        string brand;
    
    public:
        Clothes() = default; // Default constructor
        Clothes(string, int, float, string, string); // Default constructor with arguments

        // Methods for read and display data
        friend ostream& operator<<(ostream&, Clothes&);
        friend istream& operator>>(istream&, Clothes&);

        // Method for calculate price
        float getPrice();

        // Method for returnning typology: clothes
        string getTypology() const override;
};