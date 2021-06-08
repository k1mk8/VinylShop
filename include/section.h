#ifndef DZIAL_H
#define DZIAL_H

#include<bits/stdc++.h>
#include "vinyl.h"
using namespace std;

class Section
{
    string name; // nazwa sekcji
    vector<Vinyl> vinyl; // plyty w danej sekcji
    
    public:
    Section(string nameIN, vector<Vinyl> vinylIN); // konstruktor klasy
    Section(const Section& obj); // konstruktor kopiujacy klasy
    string getName(); // getter nazwy
    vector<Vinyl> getVinyl(); // getter listy z plytami
    void setName(string nameIN); // setter imienia
    void setVinyl(vector<Vinyl> vinylIN); // setter listy plyt
    void addVinyl(Vinyl vinylIN); // dodaje plyte do listy
    friend ostream& operator<<(ostream& os, Section& obj); // przeciazenie operatora <<
    friend bool operator==(Section& obj1, Section& obj2); // przeciazenie operatora ==
    friend bool operator!=(Section& obj1, Section& obj2); // przeciazenie operatora !=
    Section& operator=(Section& obj);
};

#endif