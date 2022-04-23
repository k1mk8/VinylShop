#ifndef DZIAL_H
#define DZIAL_H

#include<bits/stdc++.h>
#include "vinyl.h"
using namespace std;

class Section
{
    private:
    string name; // nazwa sekcji
    vector<Vinyl*> vinyl; // plyty w danej sekcji

    public:
    Section(string nameIN); // konstruktor klasy
    Section(const Section& obj); // konstruktor kopiujacy klasy
    string getName() const; // getter nazwy
    vector<Vinyl*> getVinyl() const; // getter listy z plytami
    void setName(string nameIN); // setter imienia
    void setVinyl(vector<Vinyl*> vinylIN); // setter listy plyt
    void addVinyl(Vinyl* vinylIN); // dodaje plyte do listy
    Vinyl* getVinylInSection(string name); //zwraca płytę z sekcji
    friend ostream& operator<<(ostream& os, Section& obj); // przeciazenie operatora <<
    friend bool operator==(const Section& obj1, const Section& obj2); // przeciazenie operatora ==
    friend bool operator!=(Section& obj1, Section& obj2); // przeciazenie operatora !=
    Section& operator=(const Section& obj);
};

#endif