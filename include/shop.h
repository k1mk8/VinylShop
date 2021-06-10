#ifndef SKLEP_H
#define SKLEp_H
#include <bits/stdc++.h>
#include "section.h"
#include "vinyl.h"
#include "seller.h"
#include "client.h"

using namespace std;

class Shop // klasa odpowiadajaca za sklep
{
private:
    vector <Section*> list_of_sections; // wektor trzymajacy liste dzialow
    vector <Seller*> list_of_sellers; // wektor trzymajacy liste sprzedawcow
    vector <Vinyl*> list_of_vinyls; // wektor trzymajacy liste plyt
    vector <Client*> list_of_clients; // wektor trzymajacy liste klientow
public:
    Shop(); // pusty konstruktor
    Shop(vector<Section*> l_of_sec, vector<Seller*> l_of_sel, vector<Vinyl*> l_of_vin, vector<Client*> l_of_cli); // konstruktor sklepu
    Shop(const Shop& S); // konstruktor kopiujacy
    void set_sections(vector<Section*> l_of_sec); // setter listy dzialow
    void set_sellers(vector<Seller*> l_of_sel); // setter listy sprzedawcow
    void set_vinyls(vector<Vinyl*> l_of_vin); // setter listy plyt
    void set_clients(vector<Client*> l_of_cli); // setter listy klientow
    void add_section(Section* S); // dodaje dzial do listy
    void add_seller(Seller* S); // dodaje sprzedawce do listy
    void add_vinyl(Vinyl* V); // dodaje plyte do listy
    void add_client(Client* C); // dodaje klienta do listy
    string getVinylGenre(string name); //zwraca gatunek muzyczny podanej płyty
    vector<Section*> get_sections(); // zwraca wektor obiektow dzialow
    vector<Seller*> get_sellers(); // zwraca wektor obiektow sprzedawcow
    vector<Vinyl*> get_vinyls(); // zwraca wektor obiektow plyt
    vector<Client*> get_clients(); // zwraca wektor obiektow klientow
};
#endif