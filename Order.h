// Order class 

#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <utility>

#include "Product.h"

using namespace std;

class Order
{
    private:
        int id;
        chrono::system_clock::time_point orderTime; // The moment the order was placed
        int processingTime; // Processing time
        int numDistinctProducts; // Number of distinct products in the order
        vector<pair<int, int>> orderedProducts; // Product code and quantity
        bool stockAvailable; // True if all ordered products are available in stock
        float totalValue; 
    
    public:
        static int idCount; // Static variable to count order id

        Order(); // Default constructor
        Order(chrono::system_clock::time_point, int, int, vector<pair<int, int>>, bool = false, float = 0); // Default constructor with arguments

        // Method for read and display data
        friend ostream& operator<< (ostream&, const Order&);
        friend istream& operator>> (istream&, Order&);

        // Method to calculate the total value of the order & status
        void setOrder(const vector<unique_ptr<Product>>& inventory);

        // Method for display order
        void displayOrder(const vector<unique_ptr<Product>>& productsList) const;

        int getId() const;
        int getProcessingTime() const;
        bool getAviableOrder() const;
        float getTotalValue() const;
};