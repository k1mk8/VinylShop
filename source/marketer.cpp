#include <iostream>
#include "marketer.h"
#include <cstdlib>
using namespace std;

Marketer::Marketer(){salary = 2500.0;}
Marketer::Marketer(string name1, Marketer marketer)
{
    salary = 2500.0;
    set_firstName(name1); // przypisanie imienia
    follows = marketer.get_follows(); // przypisane liczby obserwującyh
}
Marketer::Marketer(int follows1){salary = 2500.0;follows = follows1;} // przypisane liczby obserwującyh
int Marketer::get_follows() {return follows;}// getter wydziału
const double Marketer::get_CMkt() {return CMkt;}// getter wydajności marketera
void Marketer::set_follows(int follows1) {follows=follows1;} // setter wydziału
