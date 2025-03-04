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

// Method for editing products
void Product::editProduct()
{
    int option;
    cout << "What atribute do you want to edit?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Number of produts" << endl;
    cout << "3. Base price" << endl;
    cout << "Enter your option: ";
    cin >> option;
    switch(option)
    {
        case 1:
            cout << "Enter the new name: ";
            cin.ignore();
            getline(cin, name);
            cout << "The name was updated!" << endl;
            break;
        case 2: 
            cout << "Enter the new number of produts: ";
            cin >> numberOfProducts;
            cout << "The number of products was updated!" << endl;
            break;
        case 3:
            cout << "Enter the new base price: ";
            cin >> basePrice;
            cout << "The base price was updated!" << endl;
            break;
        default:
            break;
    }
}

// Method for edit product detail
void Product::editProductDetails()
{
    int option;
    cout << "What detail do you want to edit?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Number of products" << endl;
    cout << "3. Base price" << endl;
    cout << "Enter your option (1-3): ";
    cin >> option;
    switch (option)
    {
        case 1:
            cout << "Enter the new name: ";
            cin.ignore();
            getline(cin, name);
            cout << "The name was updated!" << endl;
            break;
        case 2:
            cout << "Enter the new number of products: ";
            cin >> numberOfProducts;
            cout << "Number of products was updated!" << endl;
            break;
        case 3:
            cout << "Enter the new base price";
            cin >> basePrice;
            cout << "The base price was updated!" << endl;
            break;
        default:
            cout << "Invalid option!" << endl;
    }
}