#include "employee.h"
#include <utility>

Employee::Employee(){}
Employee::Employee(std::string firstName){//konstruktor domyślny
    e_firstName = firstName;
}

Employee::Employee(const Employee& c){//konstruktor kopiujący
    e_firstName = c.e_firstName;
}

void Employee::set_firstName(std::string firstName) {e_firstName = firstName;}
std::string Employee::get_firstName() {return e_firstName;}
double Employee::get_salary(){return salary;}