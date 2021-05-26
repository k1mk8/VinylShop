#include <bits/stdc++.h>
#include "shop.h"

using namespace std;

Shop::Shop(vector<Section> l_of_sec, vector<Seller> l_of_sel, vector<Vinyl> l_of_vin, vector<Client> l_of_cli)
{
    list_of_sections = l_of_sec;
    list_of_sellers = l_of_sel;
    list_of_vinyls = l_of_vin;
    list_of_clients = l_of_cli;
}
Shop::Shop(const Shop& S)
{
    list_of_sections = S.list_of_sections;
    list_of_sellers = S.list_of_sellers;
    list_of_vinyls = S.list_of_vinyls;
    list_of_clients = S.list_of_clients;
}
void Shop::set_sections(vector<Section> l_of_sec) {list_of_sections=l_of_sec;}
void Shop::set_sellers(vector<Seller> l_of_sel) {list_of_sellers=l_of_sel;}
void Shop::set_vinyls(vector<Vinyl> l_of_vin) {list_of_vinyls=l_of_vin;}
void Shop::set_clients(vector<Client> l_of_cli) {list_of_clients=l_of_cli;}
void Shop::add_section(Section S) {list_of_sections.push_back(S);}
void Shop::add_seller(Seller S) {list_of_sellers.push_back(S);}
void Shop::add_vinyl(Vinyl V) {list_of_vinyls.push_back(V);}
void Shop::add_client(Client C) {list_of_clients.push_back(C);}
vector<Section> Shop::get_sections() {return list_of_sections;}
vector<Seller> Shop::get_sellers() {return list_of_sellers;}
vector<Vinyl> Shop::get_vinyls() {return list_of_vinyls;}
vector<Client> Shop::get_clients() {return list_of_clients;}