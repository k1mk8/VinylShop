#ifndef ENGINEER_H
#define ENGINEER_H

#include <iostream>
#include <vector>
#include "employee.h"

using namespace std;

class Engineer : public Employee
{
private:
    std::string faculty; // wydział inżyniera
    const double CI = 1.5; // stała wydajności inżyniera
public:
    Engineer();
    Engineer(string name1, Engineer engineer);
    Engineer(string faculty1); // konstruktor
    string get_faculty(); // getter imienia
    const double get_CI(); // zwraca wydajność inżyniera
    void set_faculty(string faculty1); // setter imienia
};

#endif