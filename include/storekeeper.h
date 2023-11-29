#ifndef STOREKEEPER_H
#define STOREKEEPER_H

#include <iostream>
#include <vector>
#include "employee.h"

using namespace std;

class StoreKeeper : public Employee
{
private:
    bool useForklift; // wydział inżyniera
    const double CMag = 1.5; // wydajność magazyniera
public:
    StoreKeeper();
    StoreKeeper(string name, StoreKeeper storyKeeper); // konstruktor
    StoreKeeper(bool useForklift1); // konstruktor
    bool get_forklift(); // getter umiejętności obsługi wózka widłowego
    const double get_CMag(); // getter wydajności magazyniera
    void set_forklift(bool useForklift1); // setter umiejętności obsługi wózka widłowego
};

#endif