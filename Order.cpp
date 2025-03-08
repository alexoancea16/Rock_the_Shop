// Implementation for order class

#include "Order.h"

int Order::idCount = 0;

// Default constructor
Order::Order()
{
    idCount++;
    id = idCount;
}

// Default constructor with arguments
Order::Order(chrono::system_clock::time_point time, int processingTime, vector<unique_ptr<Product>> products, float totalValue) :
    orderTime(time), processingTime(processingTime), orderedProducts(products), totalValue(totalValue) 
{
    idCount++;
    id = idCount;
}

// Method for display data
ostream& operator<< (ostream& dev, const Order& order)
{
    dev << "Order Id: " << order.id << endl;
    dev << "Processing time: " << order.processingTime << endl;
    dev << "Total value: " << order.totalValue << endl;
    return dev;
}

// Method for read data
istream& operator>> (istream& dev, Order& order)
{
    time_t orderTimeRaw;
    cout << "Order: " << endl;
    cout << "Order time raw: ";
    dev >> orderTimeRaw;
    order.orderTime = chrono::system_clock::from_time_t(orderTimeRaw);
    cout << "Ordered products: ";
    
    return dev;
}