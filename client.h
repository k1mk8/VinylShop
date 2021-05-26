#ifndef CLIENT_H
#define CLIENT_H

#include<string>
#include<iostream>
#include<vector>

class Client
{
private:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_favouriteGenre;
    std::string m_favouriteArtist;
    std::vector<std::pair<std::string, int> > shopping_list; // zmienilem na liste tego, co chce kupic klient
public:
    Client(std::string firstName, std::string lastName, std::string cardNumber, std::string favouriteGenre, std::string favouriteArtist);
    Client(const Client&);
    void set_firstName(std::string firstName);
    void set_lastName(std::string lastName);
    void set_favouriteGenre(std::string favouriteGenre);
    void set_favouriteArtist(std::string favouriteArtist);
    std::string get_firstName();
    std::string get_lastName();
    std::string get_favouriteGenre();
    std::string get_favouriteArtist();
    std::vector<std::pair<std::string, int> > get_shopping_list();
    void print_shoppingCart();
    friend std::ostream& operator<<(std::ostream& os, Client& c);
    friend bool operator==(Client& l, Client& r);
    friend bool operator!=(Client& l, Client& r);
    Client& operator=(const Client& c);
};

#endif