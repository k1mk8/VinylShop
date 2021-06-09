#include <bits/stdc++.h>
#include "include/shop.h"
#include <random>
#include <chrono>

using namespace std;
Shop shop;

void read_Vinyls()
{
    FILE* file;
    file = fopen("Vinyls.txt", "r");
    char letter;
    int counter = 0;
    string title, artist, price_category, quantity, genre;
    while(letter != EOF)
    {
        if(counter == 5)
        {
            Vinyl vinyl(title, artist, stoi(quantity), price_category, genre);
            shop.add_vinyl(vinyl);
            for(int i = 0; i < shop.get_sections().size(); i++)
            {
                if(shop.get_sections()[i].getName() == genre)
                    shop.get_sections()[i].addVinyl(vinyl);
            }
            title = artist = price_category = quantity = genre = "";
            counter = 0;
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
            quantity += letter;
        if(counter == 3)
            price_category += letter;
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
    file = fopen("Sellers.txt", "r");
    char letter;
    int counter;
    bool status;
    string forname, name, login, password, permmission_level, thematic_sections_str;
    vector<Section> thematic_sections;
    while(letter != EOF)
    {
        if(counter == 6)
        {
            string help = "";
            for(int i = 0; i < thematic_sections_str.size(); i++)
            {
                if(thematic_sections_str[i] == ',')
                {
                    for(int j = 0; j < shop.get_sections().size(); j++){
                        if(shop.get_sections()[j].getName() == help){
                            thematic_sections.push_back(shop.get_sections()[j]);
                            break;
                        }
                    }
                    help = "";
                    continue;
                }
                help += thematic_sections_str[i];
            }
            Seller seller(forname, name, login, password, permmission_level, thematic_sections);
            shop.add_seller(seller);
            forname = name = login = password = permmission_level = thematic_sections_str = "";
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


int checkInput(int range){//sprawdza czy wartość jest liczbą oraz czy jest mniejsza lub równa podanemu parametrowi
    char a;
    int x;
    std::cin >> a;
    if(isdigit(a)){
        std::cin.unget();
        std::cin >> x;
        if(x <= range) return x;
        else 
        {
            std::cout << "Nieprawidlowa wartosc!" << std::endl;
            return -1;
        }
    }
    std::cout << "Nieprawidlowa wartosc!" << std::endl;
    return -1;//zwraca -1 gdy wartość jest niepoprawna
}


int main()
{
    create_Sections();
    read_Vinyls(); //nie działa
    read_Sellers(); //działa, ale jakoś dziwnie (dokleja na koniec sekcje wszystkich poprzednich sprzedawców)
    cout << "Podaj czas trwania symulacji: " << endl;
    int timeLimit = checkInput(999);
    cout << "Podaj liczbe klientow: " << endl;
    int clientLimit = checkInput(999);
    string firstNames[] = {"Adam", "Bartlomiej", "Anna", "Szymon", "Natalia", "Zuzanna", "Karol", "Jakub", "Dominika", "Piotr", "Ryszard", "Aneta", "Karolina", "Wiktoria", "Marek"};
    string lastNames[] = {"Chmielewski", "Suraj", "Obroslak", "Zając", "Mazur", "Pelc", "Golianek", "Gil", "Baran", "Wieleba", "Bielak", "Wnuczek", "Zuń", "Malysz", "Kubica"};
    string artists[] = {"AC/DC", "Aerosmith", "Arctic Monkeys", "Budka Suflera", "Green Day", "Linkin Park", "Metallica", "Queen", "Toto", "Mac Miller", "Eminem", "Bjork", "Mozart", "Vivaldi", "Britney Spears"};
    string genres[] = {"Rock", "Alternative", "Indie", "Hip_hop", "Blues", "Electronic", "Jazz", "Classic", "Pop", "Reggae"};
    unsigned seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    for(int time = 0; time < timeLimit; time++){
        if(shop.get_clients().size() < clientLimit)
        {
            int number1 = uniform_int_distribution<int>(0, 14)(generator);
            int number2 = uniform_int_distribution<int>(0, 14)(generator);
            int number3 = uniform_int_distribution<int>(0, 9)(generator);
            int number4 = uniform_int_distribution<int>(0, 14)(generator);
            Client client = Client(firstNames[number1], lastNames[number2], genres[number3], artists[number4]);
            /*for(int i = 0; i < 4; i++){
                number1 = uniform_int_distribution<int>(0, 309)(generator);
                number2 = uniform_int_distribution<int>(0, 5)(generator);
                client.addToShoppingList(shop.get_vinyls()[number1].get_name(), number2);
            }*/
            shop.add_client(client);
            //cout << client << endl;
        }
        else{
            vector<Client> clients = shop.get_clients();
            for(int i = 0; i < clients.size(); i++){
                if(clients[i].get_shopping_list().size() == 0) continue;
                for(auto it = clients[i].get_shopping_list().begin(); it != clients[i].get_shopping_list().end(); it++){
                    string name = it->first;
                    int number = it->second;
                    string genre = shop.getVinylGenre(it->first);
                    Seller seller;
                    Vinyl vinyl;
                    for(int j = 0; j < shop.get_sellers().size(); j++){
                        seller = shop.get_sellers()[j];
                        for(int k = 0; k < seller.Get_thematic_sections().size(); k++){
                            if(seller.Get_thematic_sections()[k].getName() == genre){
                                seller.Set_status(false);
                                vinyl = seller.getVinyl(name, genre);
                            }
                        }
                    }
                    if(number <= vinyl.get_quantity()){
                        vinyl.set_quantity(vinyl.get_quantity() - number);
                        cout << "Klient " << clients[i].get_firstName() << " " << clients[i].get_lastName() << "kupuje " << number << vinyl.get_name() << "z kategorii cenowej" << vinyl.get_price_category() << "od " << seller.Get_name() << endl;
                    }
                    else{
                        //zamawianie
                    }
                }
            }
        }
        char a;
        cout << "Czy kontynuowac? (t/n)";
        while(a != 't'){
            cin >> a;
        }
    }
    return 0;
}