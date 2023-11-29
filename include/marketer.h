#ifndef MARKETER_H
#define MARKETER_H

#include <iostream>
#include "employee.h"

using namespace std;

class Marketer : public Employee
{
private:
    int follows; // obserwujący marketera
    const double CMkt = 1.5; // wydajność marketera
public:
    Marketer();
    Marketer(string name, Marketer marketer); // konstruktor
    Marketer(int follows1); // konstruktor
    int get_follows(); // getter obserwujących
    const double get_CMkt(); // getter wydajności marketera
    void set_follows(int follows1); // setter obserwujących
};

#endif