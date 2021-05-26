#ifndef DZIAL_H
#define DZIAL_H

#include<bits/stdc++.h>
using namespace std;

class Section
{
    string name; // nazwa sekcji
    vector<string> vinyl; // plyty w danej sekcji
    
    public:
    Section(string nameIN, vector<string> vinylIN); // konstruktor klasy
    Section(const Section& obj); // konstruktor kopiujacy klasy
    string getName(); // getter nazwy
    vector<string> getVinyl(); // getter listy z plytami
    void setName(string nameIN); // setter imienia
    void setVinyl(vector<string> vinylIN); // setter listy plyt
    friend ostream& operator<<(ostream& os, Section& obj); // przeciazenie operatora <<
    friend bool operator==(Section& obj1, Section& obj2); // przeciazenie operatora ==
    friend bool operator!=(Section& obj1, Section& obj2); // przeciazenie operatora !=
    Section& operator=(Section& obj);
};

#endif