#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<bits/stdc++.h>

class Employee
{
private:
    std::string e_firstName; // imie klienta
protected:
    double salary = 100.0; // pensja pracownika
public:
    Employee();
    Employee(std::string firstName); // konstruktor klienta
    Employee(const Employee&); // konstruktor kopiujacy
    void set_firstName(std::string firstName); // setter imienia
    double get_salary(); // getter wynagrodzenia
    std::string get_firstName(); // getter imienia
};

#endif