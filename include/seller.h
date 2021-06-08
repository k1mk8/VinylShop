#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>

using namespace std;

class Seller
{
    string name; // inicjuje imie pracownika
    string surname; // inicjuje nazwisko pracownika
    string permission_level; // inicjuje zakres dostepu pracownika
    string login; // inicjuje login pracownika
    string password; // inicjuje haslo pracownika
    vector <string> thematic_sections; // inicjuje wektor z działaniami 
    bool status; // zajetosc pracownika 
public:
    Seller(string name1, string surname1, string login, string password, string per_level, vector<string> them_sect); // konstruktor
    Seller(const Seller& sel); // konstruktor kopiujacy
    string Get_name(); // getter imienia
    string Get_surname(); // getter nazwiska
    string Get_permission_level(); // getter dostepu
    string Get_login(); // getter loginu
    string Get_password(); // getter hasla
    bool Get_status(); // getter statusu
    vector <string> Get_thematic_sections(); // getter sekcji
    void Set_name(string name1); // setter imienia
    void Set_surname(string surname1); // setter nazwiska
    void Set_login(string login1); // setter wieku
    void Set_password(string password1); // setter pensji
    void Set_permission_level(string perm_lvl); // setter dostepu
    void Set_thematic_sections(string section); // setter sekcji
    void Set_status(bool status1); // setter statusu
    friend ostream& operator<<(ostream& os, Seller& sel); // wypisywanie całego obiektu
    friend bool operator!=(Seller& sel, Seller& sel1); // przeciazenie operatora !=
    friend bool operator==(Seller& sel, Seller& sel1); // przeciazenie operatora ==
};

#endif