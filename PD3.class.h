#include<bits/stdc++.h>
using namespace std;

class Section
{
    string name;
    string description;
    string location;
    string number_of_shelves;
    string shelf_keeper;
    vector<string> vinyl;
    
    public:
    Section(string nameIN, string descriptionIN, string locationIN, string number_of_shelvesIN, string shelf_keeperIN, vector<string> vinylIN)
    {
        //tworzymy nowy obiekt na podstawie wejscia od uzytkownika
        name = nameIN;
        description = descriptionIN;
        location = locationIN;
        number_of_shelves = number_of_shelvesIN;
        shelf_keeper = shelf_keeperIN;
        vinyl = vinylIN;
    }
    
    Section(const Section& obj)
    {
        //tworzymy nowy obiekt na podstawie innego obiektu
        name = obj.name;
        description = obj.description;
        location = obj.location;
        number_of_shelves = obj.number_of_shelves;
        shelf_keeper = obj.shelf_keeper;
        vinyl = obj.vinyl;
    }

    string getName()
    {
        return name;
    }

    string getDescription()
    {
        return description;
    }    
    
    string getLocation()
    {
        return location;
    }

    string getNumber_of_shelves()
    {
        return number_of_shelves;
    }
    
    string getShelf_keeper()
    {
        return shelf_keeper;
    }
    
    vector<string> getVinyl()
    {
        return vinyl;
    }

    void setName(string nameIN)
    {
        name = nameIN;
    }

    void setDescription(string descriptionIN)
    {
        description = descriptionIN;
    }
        
    void setLocation(string locationIN)
    {
        location = locationIN;
    }
        
    void setNumber_of_shelves(string number_of_shelvesIN)
    {
        number_of_shelves = number_of_shelvesIN;
    }
        
    void setShelf_keeper(string shelf_keeperIN)
    {
        shelf_keeper = shelf_keeperIN;
    }
    
    void setVinyl(vector<string> vinylIN)
    {
        vinyl = vinylIN;
    }

    friend ostream& operator<<(ostream& os, Section& obj)
    {
        //operator << umozliwia wypisywanie parametrow obiektu
        os << "Nazwa: " << obj.getName() << "\n";
        os << "Opis: " << obj.getDescription() << "\n";
        os << "Lokalizacja: " << obj.getLocation() << "\n";
        os << "liczba regalow: " << obj.getNumber_of_shelves() << "\n";
        os << "Opiekun: " << obj.getShelf_keeper() << "\n";
        vector<string> vinyl = obj.getVinyl();
        os << "Płyty zawierające się w dziale:\n";
        for(auto it = vinyl.begin(); it != vinyl.end(); it++)os << int(it - vinyl.begin()) + 1 << ". '" << *it << "'\n";
        return os;
    }

    friend bool operator==(Section& obj1, Section& obj2)
    {
        //operator == umozliwia porownywanie obiektow
        if(obj1.getName() == obj2.getName())
            if(obj1.getDescription() == obj2.getDescription())
                if(obj1.getLocation() == obj2.getLocation())
                    if(obj1.getNumber_of_shelves() == obj2.getNumber_of_shelves())
                        if(obj1.getShelf_keeper() == obj2.getShelf_keeper())
                            if(obj1.getVinyl() == obj2.getVinyl())
                                return 1;
        return 0;
    }

    friend bool operator!=(Section& obj1, Section& obj2)
    {
        //operator != umozliwia porownywanie obiektow
        if(obj1.getName() == obj2.getName())
            if(obj1.getDescription() == obj2.getDescription())
                if(obj1.getLocation() == obj2.getLocation())
                    if(obj1.getNumber_of_shelves() == obj2.getNumber_of_shelves())
                        if(obj1.getShelf_keeper() == obj2.getShelf_keeper())
                            if(obj1.getVinyl() == obj2.getVinyl())
                                return 0;
        return 1;
    }

    Section& operator=(Section& obj)
    {
        //operator = umozliwia nadpisywanie obiektu podanym obiektem
        this -> setName(obj.getName());
        this -> setDescription(obj.getDescription());
        this -> setLocation(obj.getLocation());
        this -> setNumber_of_shelves(obj.getNumber_of_shelves());
        this -> setShelf_keeper(obj.getShelf_keeper());
        this -> setVinyl(obj.getVinyl());
        return obj;
    }
};