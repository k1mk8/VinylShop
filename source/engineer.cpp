#include <iostream>
#include "engineer.h"
#include <cstdlib>
using namespace std;

Engineer::Engineer(){
    salary = 3500.0;
}
Engineer::Engineer(string name1, Engineer engineer)
{
    salary = 3500.0;
    set_firstName(name1); // przypisanie imienia
    faculty = engineer.get_faculty(); // przypisane wydziału
}
Engineer::Engineer(string faculty1){faculty = faculty1;salary=3500.0;} // przypisane wydziału}
string Engineer::get_faculty() {return faculty;}// getter wydziału
const double Engineer::get_CI() {return CI;} // getter wydajności
void Engineer::set_faculty(string faculty1) {faculty=faculty1;} // setter wydziału