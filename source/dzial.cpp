#include<bits/stdc++.h>
#include"dzial.h"
using namespace std;

Section::Section(string nameIN, vector<string> vinylIN)
{
    name = nameIN;
    vinyl = vinylIN;
}
Section::Section(const Section& obj)
{
    name = obj.name;
    vinyl = obj.vinyl;
}
string Section::getName() {return name;}
vector<string> Section::getVinyl() {return vinyl;}
vector<pair <string, Section> > list_of_sections;
void Section::setName(string nameIN) {name=nameIN;}
void Section::setVinyl(vector<string> vinylIN) {vinyl = vinylIN;}
ostream& operator<<(ostream& os, Section& obj)
{
    os << "Nazwa: " << obj.getName() << "\n";
    vector<string> vinyl = obj.getVinyl();
    os << "Płyty zawierające się w dziale:\n";
    for(auto it = vinyl.begin(); it != vinyl.end(); it++)os << int(it - vinyl.begin()) + 1 << ". '" << *it << "'\n";
    return os;
}
bool operator==(Section& obj1, Section& obj2)
{
    if(obj1.getName() == obj2.getName())
        if(obj1.getVinyl() == obj2.getVinyl())
            return 1;
    return 0;
}
bool operator!=(Section& obj1, Section& obj2)
{
    if(obj1.getName() == obj2.getName())
        if(obj1.getVinyl() == obj2.getVinyl())
            return 0;
    return 1;
}
Section& Section::operator=(Section& obj)
{
    this -> setName(obj.getName());
    this -> setVinyl(obj.getVinyl());
    return obj;
}
    // void Create()
    // {
    //     cout << "Tworzenie nowego dzialu\n";

    //     cout << "Prosze podac nazwe dzialu:\n";
    //     string name;
    //     getline(cin, name);
    //     getline(cin, name);

    //     cout << "Prosze podac opis dzialu:\n";
    //     string description;
    //     getline(cin, description);

    //     cout << "Prosze podac lokalizacje dzialu:\n";
    //     string location;
    //     getline(cin, location);

    //     cout << "Prosze podac rozmiar dzialu:\n";
    //     string number_of_shelves;
    //     getline(cin, number_of_shelves);

    //     cout << "Prosze podac opiekuna dzialu:\n";
    //     string shelf_keeper;
    //     getline(cin, shelf_keeper);

    //     string input;
    //     vector<string> vinyl;
    //     cout << "Prosze podac kolejne plyty zawierajace sie w dziale, po wpisaniu pozycji nalezy wcisnac enter\n";
    //     cout << "By skonczyc prosze wpisac koniec i wcisnac enter:\n";
    //     while(1)
    //     {
    //         getline(cin, input);
    //         if(input == "koniec")
    //             break;
    //         vinyl.push_back(input);
    //     }
    //     //tworzymy nowy obiekt
    //     Section obj(name, description, location, number_of_shelves, shelf_keeper, vinyl);
    //     //zapisujnemy go na vektorze
    //     list_of_sections.push_back({name, obj});
    // }

    // void change(Section obj, int id)
    // {
    //     cout << "Wpisz liczbę by dokonac zmiany:\n";
    //     cout << "[1] Zmiana nazwy\n";
    //     cout << "[2] Zmiana opisu\n";
    //     cout << "[3] Zmiana lokalizacji\n";
    //     cout << "[4] Zmiana liczby regalów\n";
    //     cout << "[5] Zmiana opiekuna\n";
    //     cout << "[6] Zmiana płyt zawierających się w dziale\n";
    //     cout << "[0] Anuluj\n";
    //     string choice;
    //     cin >> choice;
    //     if(choice == "1")
    //     {
    //         cout << "Podaj nowa nazwe: ";
    //         string name;
    //         getline(cin, name);
    //         getline(cin, name);
    //         obj.setName(name);
    //         list_of_sections[id].first = name;
    //     }
    //     if(choice == "2")
    //     {
    //         cout << "Podaj nowy opis: ";
    //         string description;
    //         getline(cin, description);
    //         getline(cin, description);
    //         obj.setDescription(description);
    //     }
    //     if(choice == "3")
    //     {
    //         cout << "Podaj nową lokalizację: ";
    //         string localisation;
    //         getline(cin, localisation);
    //         getline(cin, localisation);
    //         obj.setLocation(localisation);
    //     }
    //     if(choice == "4")
    //     {
    //         cout << "Podaj nową liczbę regalów: ";
    //         string number_of_shelves;
    //         getline(cin, number_of_shelves);
    //         getline(cin, number_of_shelves);
    //         obj.setNumber_of_shelves(number_of_shelves);
    //     }
    //     if(choice == "5")
    //     {
    //         cout << "Podaj nowego opiekuna: ";
    //         string shelf_keeper;
    //         getline(cin, shelf_keeper);
    //         getline(cin, shelf_keeper);
    //         obj.setShelf_keeper(shelf_keeper);
    //     }
    //     if(choice == "6")
    //     {
    //         vector<string> input;
    //         string vinyl;
    //         getline(cin, vinyl);
    //         cout << "Prosze podac kolejne plyty zawierajace sie w dziale, po wpisaniu pozycji nalezy wcisnac enter\n";
    //         cout << "By skonczyc prosze wpisac koniec i wcisnac enter:\n";
    //         while(1)
    //         {
    //             getline(cin, vinyl);
    //             if(vinyl == "koniec")
    //                 break;
    //             input.push_back(vinyl);
    //         }
    //         obj.setVinyl(input);
    //     }
    //     //aktualizujemy obiekt na vektorze zmienionym obiektem
    //     list_of_sections[id].second = obj;
    // }

    // void del(Section obj)
    // {
    //     int b = 0;
    //     for(int i = 0; i + 1 < list_of_sections.size(); i++)
    //     {
    //         if(list_of_sections[i].second == obj)
    //         {
    //             b = i;
    //         }
    //         if(list_of_sections[i].second != obj)
    //             ;
    //         if(b)
    //         {
    //             //przepisujemy aktualny vektor
    //             list_of_sections[i].first = list_of_sections[i+1].first;
    //             list_of_sections[i].second = list_of_sections[i+1].second;
    //         }
    //     }
    //     //na koncu zostaje nasz obiekt usuwamy go
    //     list_of_sections.pop_back();
    // }

    // void Interface()
    // {
    //     while(1)
    //     {
    //         cout << "Wpisz '1' aby stworzyc nowy dział\n";
    //         cout << "Wpisz '2' aby sprawdzic parametry działów\n";
    //         cout << "Wpisz '3' aby edytowac działy\n";
    //         cout << "Wpisz '4' aby usunac dział\n";
    //         cout << "Wpisz '5' aby skopiowac dział\n";
    //         cout << "Wpisz '0' aby zakonczyc\n";
    //         string choice;
    //         cin >> choice;
    //         if(choice == "1")Create();
    //         if(choice == "2")
    //         {
    //             cout << "By odczytac wprowadz numer dzialu z listy ponizej:\n";
    //             for(auto it = list_of_sections.begin(); it != list_of_sections.end(); it++)
    //             {
    //                 cout << int(it - list_of_sections.begin()) + 1 << " " << it -> first << "\n";
    //             }
    //             int section;
    //             cin >> section;
    //             if(section < 1 || section > list_of_sections.size())
    //                 cout << "Brak takiego dzialu\n";
    //             else
    //                 cout << list_of_sections[section - 1].second;
    //         }
    //         if(choice == "3")
    //         {
    //             cout << "By wprowadzic zmiany wprowadz numer dzialu z listy ponizej:\n";
    //             for(auto it = list_of_sections.begin(); it != list_of_sections.end(); it++)
    //             {
    //                 cout << int(it - list_of_sections.begin()) + 1 << " " << it -> first << "\n";
    //             }
    //             int section;
    //             cin >> section;
    //             if(section < 1 || section > list_of_sections.size())
    //                 cout << "Brak takiego dzialu\n";
    //             else
    //                 change(list_of_sections[section - 1].second, section - 1);
    //         }
    //         if(choice == "4")
    //         {
    //             cout << "By usunać dzial podaj jego numer z listy ponizej:\n";
    //             for(auto it = list_of_sections.begin(); it != list_of_sections.end(); it++)
    //             {
    //                 cout << int(it - list_of_sections.begin()) + 1 << " " << it -> first << "\n";
    //             }
    //             int section;
    //             cin >> section;
    //             if(section < 1 || section > list_of_sections.size())
    //                 cout << "Brak takiego dzialu\n";
    //             else
    //                 del(list_of_sections[section - 1].second);
    //         }
    //         if(choice == "5")
    //         {
    //             cout << "By skopiowac dzial podaj jego numer z listy ponizej:\n";
    //             for(auto it = list_of_sections.begin(); it != list_of_sections.end(); it++)
    //             {
    //                 cout << int(it - list_of_sections.begin()) + 1 << " " << it -> first << "\n";
    //             }
    //             int section;
    //             cin >> section;
    //             if(section < 1 || section > list_of_sections.size())
    //                 cout << "Brak takiego dzialu\n";
    //             else
    //                 list_of_sections.push_back({list_of_sections[section - 1].first, Section(list_of_sections[section - 1].second)});
    //         }
    //         if(choice == "0")break;
    //     }
    // }

int main()
{
    // Interface();
    return 0;
}