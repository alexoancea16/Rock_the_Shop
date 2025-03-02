// Functionalty of Clothes class

#include "Clothes.h"

// Default constructor with arguments
Clothes::Clothes(string name, int numberOfProducts, float basePrice, string color, string brand) :
    Product(name, numberOfProducts, basePrice), color(color), brand(brand) {}

// Methods for display data
ostream& operator<<(ostream& dev, Clothes& clothes)
{
    dev << "Clothes" << endl;
    dev << (Product&)clothes;
    dev << "Color: " << clothes.color << endl;
    dev << "Brand: " << clothes.brand << endl;
    return dev;
}

// Methods for read data
istream& operator>>(istream& dev, Clothes& clothes)
{
    dev >> (Product&)clothes;
    cout << "Color: ";
    dev >> clothes.color;
    cout << "Brand: ";
    dev >> clothes.brand;
    return dev;
}

// Method for calculate price
float Clothes::getPrice()
{
    return basePrice + 20;
}