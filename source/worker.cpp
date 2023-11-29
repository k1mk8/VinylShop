#include <iostream>
#include "worker.h"
#include <cstdlib>
using namespace std;

Worker::Worker(){salary = 1500.0;}
Worker::Worker(string name1, Worker worker)
{
    salary = 1500.0;
    set_firstName(name1); // przypisanie imienia
    shoeSize = worker.get_shoeSize(); // przypisane wydziału
}
Worker::Worker(double shoeSize1){salary = 1500.0;shoeSize = shoeSize1;} // przypisane wydziału
double Worker::get_shoeSize() {return shoeSize;}// getter rozmiaru buta
const double Worker::get_CR() {return CR;}// getter rozmiaru buta
void Worker::set_shoeSize(double shoeSize1) {shoeSize=shoeSize1;} // setter rozmiaru buta
