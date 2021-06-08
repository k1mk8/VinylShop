#include <bits/stdc++.h>
#include "include/shop.h"

using namespace std;
Shop shop;

void read_Vinyls()
{
    FILE* file;
    file = fopen("Vinyls.txt", "r");
    char letter;
    int counter;
    string title, artist, price_category, quantity, genre;
    while(letter != EOF)
    {
        if(counter == 5)
        {
            Vinyl vinyl(title, artist, stoi(quantity), price_category, genre);
            shop.add_vinyl(vinyl);
            for(auto it = shop.get_sections().begin(); it != shop.get_sections().end(); it++)
            {
                if(it -> getName() == genre)
                    it -> addVinyl(vinyl);
            }
            title, artist, price_category, quantity, genre = "";
            counter %= 5;
        }
        letter = fgetc(file);
        if(letter == ';')
        {
            counter ++;
            continue;
        }
        if(counter == 0)
            title += letter;
        if(counter == 1)
            artist += letter;
        if(counter == 2)
            price_category += letter;
        if(counter == 3)
            quantity += letter;
        if(counter == 4)
            genre += letter;
    }
    fclose(file);
}


void create_Sections()
{
    Section Rock(Rock);
    shop.add_section(Rock);
    Section Alternative(Alternative);
    shop.add_section(Alternative);
    Section Indie(Indie);
    shop.add_section(Indie);
    Section Hip_hop(Hip_hop);
    shop.add_section(Hip_hop);
    Section Blues(Blues);
    shop.add_section(Blues);
    Section Electronic(Electronic);
    shop.add_section(Electronic);
    Section Jazz(Jazz);
    shop.add_section(Jazz);
    Section Classic(Classic);
    shop.add_section(Classic);
    Section Pop(Pop);
    shop.add_section(Pop);
    Section Reggae(Reggae);
    shop.add_section(Reggae);
}


void read_Sellers()
{
    FILE* file;
    file = fopen("Vinyls.txt", "r");
    char letter;
    int counter;
    bool status;
    string forname, name, login, password, permmission_level, thematic_sections_str;
    vector<string> thematic_sections;
    while(letter != EOF)
    {
        if(counter == 6)
        {
            string help = "";
            for(int i = 0; i < thematic_sections_str.size(); i++)
            {
                if(thematic_sections_str[i] == ',')
                {
                    thematic_sections.push_back(help);
                    help = "";
                    continue;
                }
                help += thematic_sections_str[i];
            }
            Seller seller(forname, name, login, password, permmission_level, thematic_sections);
            shop.add_seller(seller);
            forname, name, login, password, permmission_level = "";
            thematic_sections.clear();
            counter %= 6;
        }
        letter = fgetc(file);
        if(letter == ';')
        {
            counter ++;
            continue;
        }
        if(counter == 0)
            forname += letter;
        if(counter == 1)
            name += letter;
        if(counter == 2)
            login += letter;
        if(counter == 3)
            password += letter;
        if(counter == 4)
            permmission_level += letter;
        if(counter == 5)
            thematic_sections_str += letter;
    }
    fclose(file);
}


int main()
{
    create_Sections();
    read_Vinyls();
    read_Sellers();
    cout << shop.get_sellers()[2];
    return 0;
}