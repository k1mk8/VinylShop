// #ifndef CLIENT_H
#define CLIENT_H

#include<string>
#include<iostream>
#include<map>

class Client
{
private:
    std::string m_firstName; // imie klienta
    std::string m_lastName; // nazwisko klienta
    std::string m_favouriteGenre; // ulubiony gatuenk
    std::string m_favouriteArtist; // ulubiony artysta
    std::map<std::string, int> shopping_list; // lista zakupow
public:
    Client(std::string firstName, std::string lastName, std::string favouriteGenre, std::string favouriteArtist); // konstruktor klienta
    Client(const Client&); // konstruktor kopiujacy
    void set_firstName(std::string firstName); // setter imienia
    void set_lastName(std::string lastName); // setter nazwiska
    void set_favouriteGenre(std::string favouriteGenre); // setter ulubionego gatunku
    void set_favouriteArtist(std::string favouriteArtist); // setter ulubionego artysty
    std::string get_firstName(); // getter imienia
    std::string get_lastName(); // getter nazwiska
    std::string get_favouriteGenre(); // getter ulubionego gatunku
    std::string get_favouriteArtist(); // getter ulubionego artsty
    std::map<std::string, int>get_shopping_list(); // getter listy zakupow
    void print_shopping_list(); // wyswietla liste zakupow klienta
    void addToShoppingList(std::string name, int number);
    friend std::ostream& operator<<(std::ostream& os, Client& c); // przeciazenie operatora <<
    friend bool operator==(Client& l, Client& r); // przeciazenie operatora ==
    friend bool operator!=(Client& l, Client& r); // przeciazenie operatora !=
    Client& operator=(const Client& c);
};

// ##endif