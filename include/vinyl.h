#ifndef PLYTY_H
#define PLYTY_H

#include <bits/stdc++.h>
using namespace std;

class Vinyl
{
private:
    string name; // nazwa plyty
    string artist; // wykonawca plyty
    int quantity; // ilosc na stanie
    string price_category; // kategoria cenowa
    string genre; // gatunek muzyki
public:
    Vinyl();
    Vinyl(string name1, string artist1, int quantity1, string price_categ, string genre1); // konstruktor obiektu plyty
    Vinyl(const Vinyl& V); // konstruktor kopiujacy
    void set_name(string name1); // setter nazwy
    void set_artist(string artist1); // setter wykonawcy
    void set_quantity(int quantity1); // setter ilosci na stanie
    void set_price_category(string price_categ); // setter kategorii cenowej
    void set_genre(string genre1); // setter gatunku
    string get_name() const; // getter nazwy
    string get_artist() const; // getter wykonawcy
    int get_quantity() const; // getter ilosci
    string get_price_category() const; // getter kategorii cenowej
    string get_genre() const; // getter gatunku
    friend ostream& operator<<(ostream& os, Vinyl& V); // przeciazenie operatora ==
    friend bool operator==(const Vinyl& V1, const Vinyl& V2); // przeciazenie operatora ==
    friend bool operator!=(Vinyl& V1, Vinyl& V2); // przeciazenie operatora != 
    Vinyl& operator=(const Vinyl& V);
};
#endif