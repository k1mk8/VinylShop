#include <bits/stdc++.h>
#include "vinyl.h"

using namespace std;

Vinyl::Vinyl(string name1, string artist1, int quantity1, string price_categ, string genre1)
{
    name = name1;
    artist = artist1;
    quantity = quantity1;
    price_category = price_categ;
    genre = genre1;
}
Vinyl::Vinyl(const Vinyl& V)
{
    name = V.name;
    artist = V.artist;
    quantity = V.quantity;
    price_category = V.price_category;
    genre = V.genre;
}
void Vinyl::set_name(string name1) {name = name1;}
void Vinyl::set_artist(string artist1) {artist = artist1;}
void Vinyl::set_quantity(int quantity1) {quantity = quantity1;}
void Vinyl::set_price_category(string price_categ) {price_category = price_categ;}
void Vinyl::set_genre(string genre1) {genre = genre1;}
string Vinyl::get_name() const {return name;}
string Vinyl::get_artist() const {return artist;}
int Vinyl::get_quantity() const {return quantity;}
string Vinyl::get_price_category() const {return price_category;}
string Vinyl::get_genre() const {return genre;}
ostream& operator<<(ostream& os, Vinyl& V)
{
    string name = V.get_name();
    string artist = V.get_artist();
    int quantity = V.get_quantity();
    string price_category = V.get_price_category();
    string genre = V.get_genre();
    os << name << " " << artist << " " << quantity << " " << price_category;
    return os;
}
bool operator==(const Vinyl& V1, const Vinyl& V2)
{
    if(V1.get_name() == V2.get_name())
        if(V1.get_artist() == V2.get_artist())
            if(V1.get_quantity() == V2.get_quantity())
                if(V1.get_price_category() == V2.get_price_category())
                    if(V1.get_genre() == V2.get_genre())
                        return 1;
    return 0;
}
bool operator!=(Vinyl& V1, Vinyl& V2)
{
    if(V1.get_name() == V2.get_name())
        if(V1.get_artist() == V2.get_artist())
            if(V1.get_quantity() == V2.get_quantity())
                if(V1.get_price_category() == V2.get_price_category())
                    if(V1.get_genre() == V2.get_genre())
                        return 0;
    return 1;
}
Vinyl& Vinyl::operator=(const Vinyl& V)
{
    if(this == &V) return *this;
    name = V.name;
    artist = V.artist;
    quantity = V.quantity;
    price_category = V.price_category;
    genre = V.genre;
    return *this;
}