// Order class 

#include <iostream>
#include <vector>
#include <memory>
#include <chrono>

#include "Product.h"

using namespace std;

class Order
{
    private:
        int id;
        chrono::system_clock::time_point orderTime;
        int processingTime;
        vector<unique_ptr<Product>> orderedProducts;
        float totalValue;
    
    public:
        static int idCount; // Static variable to count order id

        Order(); // Default constructor
        Order(chrono::system_clock::time_point, int, vector<unique_ptr<Product>>, float); // Default constructor with arguments

        // Method for read and display data
        friend ostream& operator<< (ostream&, const Order&);
        friend istream& operator>> (istream&, Order&);
};