#ifndef PLYTY_H
#define PLYTY_H

#include <bits/stdc++.h>
using namespace std;

class Vinyl
{
private:
    string name;
    string artist;
    int quantity;
    string price_category;
public:
    Vinyl(string name1, string artist1, int quantity1, string price_categ);
    Vinyl(const Vinyl& V);
    void set_name(string name1);
    void set_artist(string artist1);
    void set_quantity(int quantity1);
    void set_price_category(string price_categ);
    string get_name();
    string get_artist();
    int get_quantity();
    string get_price_category();
    friend ostream& operator<<(ostream& os, Vinyl& V);
    friend bool operator==(Vinyl& V1, Vinyl& V2);
    friend bool operator!=(Vinyl& V1, Vinyl& V2);
    Vinyl& operator=(const Vinyl& V);
};
#endif