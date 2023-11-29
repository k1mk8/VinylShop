#include "concern.h"
using namespace std;

template <typename T>
void Concern::add_employee(std::string name, T&& employeeDetails) {
    employees.emplace_back(make_unique<T>(name, std::forward<T>(employeeDetails)));
}