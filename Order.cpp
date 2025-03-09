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
Order::Order(chrono::system_clock::time_point time, int processingTime, int numDistinctProducts, vector<pair<int, int>> products, bool stockAvailable, float totalValue) :
    orderTime(time), processingTime(processingTime), numDistinctProducts(numDistinctProducts), orderedProducts(products), stockAvailable(stockAvailable), totalValue(totalValue) 
{
    idCount++;
    id = idCount;
}

// Method to display the order details
ostream& operator<<(ostream& dev, const Order& order)
{
    dev << "Order Id: " << order.id << endl;
    dev << "Processing time: " << order.processingTime << endl;
    dev << "Number of distinct products: " << order.numDistinctProducts << endl;
    dev << "Total value: " << order.totalValue << endl;
    dev << "Ordered products (code, quantity):" << endl;
    for (const auto& product : order.orderedProducts)
    {
        dev << "Product code: " << product.first << ", Quantity: " << product.second << endl;
    }
    return dev;
}

// Method to read the order details
istream& operator>>(istream& dev, Order& order)
{
    time_t orderTimeRaw;
    cout << "Enter the order time (timestamp): ";
    dev >> orderTimeRaw;
    order.orderTime = chrono::system_clock::from_time_t(orderTimeRaw);
    cout << "Enter the processing time: ";
    dev >> order.processingTime;
    cout << "Enter the number of distinct products: ";
    dev >> order.numDistinctProducts;
    order.orderedProducts.clear();
    for(int i = 0; i < order.numDistinctProducts; i++)
    {
        int productCode, quantity;
        cout << "Enter product code and quantity: ";
        dev >> productCode >> quantity;
        order.orderedProducts.push_back({productCode, quantity});
    }
    order.stockAvailable = false;
    order.totalValue = 0;
    return dev;
}

// Method to calculate the total value of the order & status
void Order::setOrder(const vector<unique_ptr<Product>>& inventory)
{
    totalValue = 0;
    stockAvailable = true;
    for (const auto& orderedProduct : orderedProducts)
    {
        int productCode = orderedProduct.first;
        int quantity = orderedProduct.second;
        bool productFound = false;
        // Search the product in the inventory by its code
        for (const auto& product : inventory)
        {
            if (product->getCode() == productCode)
            {
                productFound = true;
                // Check if there is enough stock
                if (product->getNumberOfProducts() < quantity)
                {
                    stockAvailable = false;
                }
                else
                {
                    totalValue += product->getPrice() * quantity;
                    product->stockUpdate(quantity);
                    break;
                } 
            }
        }
        // If any product is not found, mark stock as unavailable
        if (!productFound)
        {
            stockAvailable = false;
        }
    }
}

// Method for display data
void Order::displayOrder(const vector<unique_ptr<Product>>& productsList) const
{
    cout << "Order Id: " << id << endl;
    cout << "Processing time: " << processingTime << " seconds" << endl;
    cout << "Number of distinct products: " << numDistinctProducts << endl;
    cout << "Total value: " << totalValue << endl;
    cout << "Ordered products (code, name, quantity):" << endl;
    for (const auto& orderedProduct : orderedProducts)
    {
        int productCode = orderedProduct.first;
        int quantity = orderedProduct.second;
        string productName = "Invalid"; 
        for (const auto& product : productsList)
        {
            if (product->getCode() == productCode)
            {
                productName = product->getName();
                break;
            }
        }
        cout << "Product code: " << productCode << ", Name: " << productName << ", Quantity: " << quantity << endl;
    }
    cout << "Status: " << stockAvailable << endl;
    cout << endl;
}

int Order::getId() const 
{
    return id;
}

int Order::getProcessingTime() const
{
    return processingTime;
}

bool Order::getAviableOrder() const
{
    return stockAvailable;
}

float Order::getTotalValue() const
{
    return totalValue;
}