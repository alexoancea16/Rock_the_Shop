// Functionalty of Disk class

#include "Disk.h"

// Default constructor with arguments
Disk::Disk(string name, int numberOfProducts, float basePrice,bool type, string recordLabel, string date, string band, string nameOfAlbum) :
    Product(name, numberOfProducts, basePrice), type(type), recordLabel(recordLabel), date(date), band(band), nameOfAlbum(nameOfAlbum) {}

// Methods for display data
ostream& operator<<(ostream& dev, Disk& disk)
{
    dev << "Disk" << endl;
    dev << (Product&)disk;
    if(disk.type == true)
        dev << "Type: " << "CD" << endl;
    else
        dev << "Type: " << "Vinil" << endl;
    dev << "Record Label: " << disk.recordLabel << endl;
    dev << "Date: " << disk.date << endl;
    dev << "Band: " << disk.band << endl;
    dev << "Name of album: " << disk.nameOfAlbum << endl;
    return dev;
}

// Methods for read data
istream& operator>>(istream& dev, Disk& disk)
{
    dev >> (Product&)disk;
    cout << "Type(1 = cd | 0 = vinil): ";
    dev >> disk.type;
    cout << "Record Label: ";
    dev >> disk.recordLabel;
    cout << "Data: ";
    dev >> disk.date;
    cout << "Band: ";
    dev >> disk.band;
    cout << "Name of album:";
    dev >> disk.nameOfAlbum;
    return dev;
}

// Method for calculate price
float Disk::getPrice()
{
    return basePrice + 5;
}