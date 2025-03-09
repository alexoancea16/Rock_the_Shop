// Disk class - subclass of the Product class
// Type of employee

#include "Product.h"

#pragma once

using namespace std;

class Disk : public Product
{
    private:
        bool type;
        string recordLabel;
        string date;
        string band;
        string nameOfAlbum;

    public:
        Disk() = default; // Default constructor
        Disk(string, int, float, bool, string, string, string, string); // Default constructor with arguments

        // Methods for read and display data
        friend ostream& operator<<(ostream&, Disk&);
        friend istream& operator>>(istream&, Disk&);

        // Method for calculate price
        float getPrice() const override;

        // Method for returnning typology: disk
        string getTypology() const override;
};