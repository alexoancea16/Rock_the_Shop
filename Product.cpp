// Functionalty of Product class

#include "Product.h"

int Product::codeCount = 0;

// Default constructor
Product::Product()
{
    codeCount++;
    code = codeCount;
}

// Default constructor with arguments
Product::Product(string name, int numberOfProducts, float basePrice):
    name(name),numberOfProducts(numberOfProducts),basePrice(basePrice)
{
    codeCount++;
    code = codeCount;
}

// Method for read and diplay data
istream& operator>>(istream& dev, Product &product)
{
    product.code = Product::codeCount++;
    cout << "Product Name: ";
    dev >> product.name;
    cout << "Number of product: ";
    dev >> product.numberOfProducts;
    cout << "Base Price: ";
    dev >> product.basePrice;
    return dev;
}

ostream& operator<<(ostream& dev, const Product& product)
{
    dev << "Product details" << endl;
    dev << "Code: " << product.code << endl;
    dev << "Name " << product.name << endl;
    dev << "Number of products: " << product.numberOfProducts << endl;
    dev << "Base Price: " << product.basePrice << endl;
    dev << endl;
    return dev;
}