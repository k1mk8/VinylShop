#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <vector>
#include "employee.h"

using namespace std;

class Worker : public Employee
{
private:
    double shoeSize; // rozmiar buta pracownika
    const double CR = 1.5; // wydajność robotnika
public:
    Worker();
    Worker(string name, Worker worker); // konstruktor
    Worker(double shoeSize1); // konstruktor
    double get_shoeSize(); // getter rozmiaru buta
    const double get_CR(); // getter rozmiaru buta
    void set_shoeSize(double shoeSize1); // setter rozmiaru buta
};

#endif