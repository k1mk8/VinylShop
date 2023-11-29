#include <iostream>
#include "storekeeper.h"
#include <cstdlib>
using namespace std;

StoreKeeper::StoreKeeper(){salary = 2000.0;}
StoreKeeper::StoreKeeper(string name1, StoreKeeper storeKeeper)
{
    salary = 2000.0;
    set_firstName(name1); // przypisanie imienia
    useForklift = storeKeeper.get_forklift(); // przypisane umiejętności obsługi wózka widłowego
}
StoreKeeper::StoreKeeper(bool useForklift1){salary = 2000.0; useForklift = useForklift1;} // przypisane umiejętności obsługi wózka widłowego

bool StoreKeeper::get_forklift() {return useForklift;}// getter umiejętności obsługi wózka widłowego
const double StoreKeeper::get_CMag() {return CMag;}// getter wydajności magazyniera
void StoreKeeper::set_forklift(bool useForklift1) {useForklift=useForklift1;} // setter umiejętności obsługi wózka widłowego
