#include <bits/stdc++.h>
#include "section.h"
#include "vinyl.h"
using namespace std;

Section::Section(string nameIN, vector<Vinyl> vinylIN)
{
    name = nameIN;
    vinyl = vinylIN;
}
Section::Section(const Section& obj)
{
    name = obj.name;
    vinyl = obj.vinyl;
}
string Section::getName() const {return name;}
vector<Vinyl> Section::getVinyl() const {return vinyl;}
vector<pair <string, Section> > list_of_sections;
void Section::setName(string nameIN) {name=nameIN;}
void Section::setVinyl(vector<Vinyl> vinylIN) {vinyl = vinylIN;}
void Section::addVinyl(Vinyl vinylIN) {vinyl.push_back(vinylIN);}
Vinyl Section::getVinylInSection(string name){
    for(int i = 0; i < vinyl.size(); i++){
        if(vinyl[i].get_name() == name){
            return vinyl[i];
        }
    }
}
ostream& operator<<(ostream& os, Section& obj)
{
    os << "Nazwa: " << obj.getName() << "\n";
    vector<Vinyl> vinyl = obj.getVinyl();
    os << "Płyty zawierające się w dziale:\n";
    for(auto it = vinyl.begin(); it != vinyl.end(); it++)os << int(it - vinyl.begin()) + 1 << ". '" << *it << "'\n";
    return os;
}
bool operator==(const Section& obj1, const Section& obj2)
{
    if(obj1.getName() == obj2.getName())
        if(obj1.getVinyl() == obj2.getVinyl())
            return 1;
    return 0;
}
bool operator!=(Section& obj1, Section& obj2)
{
    if(obj1.getName() == obj2.getName())
        if(obj1.getVinyl() == obj2.getVinyl())
            return 0;
    return 1;
}
Section& Section::operator=(const Section& obj)
{
    this -> setName(obj.getName());
    this -> setVinyl(obj.getVinyl());
    return *this;
}