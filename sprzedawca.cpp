#include <iostream>
#include "sprzedawca.h"
#include <cstdlib>

using namespace std;

Seller::Seller(string name1, string surname1, string login1, string password1, string per_level, vector<string> them_sect)
{
    name = name1; // przypisuje imie
    surname = surname1; // przypisuje nazwisko
    login = login1; // przypisuje wiek
    password = password1; // przypisuje pensja
    permission_level = per_level; // przypisuje zakres dostepu
    thematic_sections = them_sect; // przypisuje sekcje
}

Seller::Seller(const Seller& sel)
{
    name = sel.name;
    surname = sel.surname;
    login = sel.login;
    password = sel.password;
    permission_level = sel.permission_level;
    thematic_sections = sel.thematic_sections;
}
string Seller::Get_name() {return name;}// getter imienia
string Seller::Get_surname() {return surname;} // getter nazwiska
string Seller::Get_permission_level() {return permission_level;} // getter poziomu dostepu
string Seller::Get_login() {return login;} // getter loginu
string Seller::Get_password() {return password;} // getter hasla
vector <string> Seller::Get_thematic_sections() {return thematic_sections;} // getter obslugiwanych sekcji
void Seller::Set_name(string name1) {name=name1;} // setter imienia
void Seller::Set_surname(string surname1) {surname=surname1;} // setter nazwiska
void Seller::Set_login(string login1) {login=login1;} // setter loginu
void Seller::Set_password(string password1) {password=password1;} // setter hasla
void Seller::Set_permission_level(string perm_lvl) {permission_level=perm_lvl;} //setter poziomu dostepu
void Seller::Set_thematic_sections(string section) {thematic_sections.push_back(section);} // setter obslugiwaneg dzialu
ostream& operator<<(ostream& os, Seller& sel)
{
    os <<"Imie sprzedawcy: "<< sel.Get_name() <<"\n";
    os <<"Nazwisko sprzedawcy: "<< sel.Get_surname() <<"\n";
    os <<"Login sprzedawcy: "<< sel.Get_login() <<"\n";
    os <<"Haslo sprzedawcy: "<< sel.Get_password() <<"\n";
    os <<"Poziom uprawnien sprzedawcy: "<< sel.Get_permission_level() <<"\n";
    os <<"Obslugiwane stanowiska sprzedawcy:\n";
    vector <string> sections = sel.Get_thematic_sections();
    for(int i=0; i<sections.size(); i++)
    {
        os <<sections[i]<<endl;
    }
    return os;
}
bool operator!=(Seller& sel, Seller& sel1)
{
    if(sel.Get_name() == sel1.Get_name()) // porownujemy poszcegolne parametry
        if(sel.Get_surname() == sel1.Get_surname())
            if(sel.Get_login() == sel1.Get_login())
                if(sel.Get_password() == sel1.Get_password())
                    if(sel.Get_permission_level() == sel1.Get_permission_level())
                        if(sel.Get_thematic_sections() == sel1.Get_thematic_sections())
                            return 0;
    return 1;
}
bool operator==(Seller& sel, Seller& sel1)
{
    if(sel.Get_name() == sel1.Get_name())
        if(sel.Get_surname() == sel1.Get_surname())
            if(sel.Get_login() == sel1.Get_login())
                if(sel.Get_password() == sel1.Get_password())
                    if(sel.Get_permission_level() == sel1.Get_permission_level())
                        if(sel.Get_thematic_sections() == sel1.Get_thematic_sections())
                            return 1;
    return 0;
}
vector < pair < string, Seller > > sel;
void permission() // wypisowanie dostepnych opcji
{
    cout<<"Podaj uprawnienia pracownika z nizej podanych:\n Stazysta\n Pracownik \n Kierownik \n Administrator \n Wlasciciel\n";
}
bool check_permission(string data) // sprawdzanie poprawnosci dostepu
{
    if(data == "Stazysta")
    {
        return 1;
    }
    else
    if(data == "Pracownik")
    {
        return 1;
    }
    else
    if(data == "Kierownik")
    {
        return 1;
    }
    else
    if(data == "Administrator")
    {
        return 1;

    }
    else
    if(data == "Wlasciciel")
    {
        return 1;
    }
    return 0;
}
bool check_numbers(string data) // sprawdzanie czy podane dane to liczba
{
    for(int i=0;i<data.size();i++)
    {
        if(data[i] < '0' || data[i] > '9')
        {
            cout<<"Zle dane!\n";
            return 1;
        }
    }
    return 0;
}
vector <string> load_data() // wczytywanie danych do utworzenia obiektu klasy
{
    cout<<"Prosimy o wprowadzenie danych sprzedawcy"<<endl;
    string data;
    vector <string> all_data; // stworzenie wektora zwracajacego wszystkie dane
    
    cout<<"Podaj imie pracownika"<<endl;
    cin>>data; // wczytanie imienia
    all_data.push_back(data); // wrzucenie go na wektor

    cout<<"Podaj nazwisko pracownika"<<endl;
    cin>>data; // wczytanie nazwiska
    all_data.push_back(data); // wrzucenie go na wektor

    cout<<"Podaj wiek pracownika"<<endl;
    cin>>data; // wczytanie wieku
    while(check_numbers(data)) // sprawdzenie czy to liczba
    {
        cin>>data;
    }
    all_data.push_back(data); // wrzucenie na wektor

    cout<<"Podaj zarobki pracownika"<<endl;
    cin>>data; // wczytanie zarobkow
    while(check_numbers(data)) // sprawdzenie czy to liczba
    {
        cin>>data;
    }
    all_data.push_back(data); // wrzucenie na wektor

    permission();
    cin>>data;
    while(!check_permission(data)) // sprawdzenie czy podano odpowienie pozwolenia
    {
        cout<<"Zle dane!\n";
        cin>>data;
    }
    all_data.push_back(data); // wrzucenie na wektor

    cout<<"Podaj dzialy, jesli chcesz zakonczyc wpisz END\n";
    getline(cin, data);
    while(1) // wczytywanie dzialow do momentu zakoczenia wczytywania
    {
        getline(cin, data);
        if(data == "END")
        {
            break;
        }
        all_data.push_back(data); // wrzucanie dzialow na wektor
    }
    return all_data; // zwrocenie wektora z danymi
}
void option() // funckja wypisuje opcje
{
    cout<<"1 - Dodaj sprzedawce\n";
    cout<<"2 - Zmien dostęp określonego sprzedawcy\n";
    cout<<"3 - Dodaj dzial obslugiwany przez okreslonego sprzedawce\n";
    cout<<"4 - Wysietl informacje o sprzedawcy\n";
    cout<<"5 - Zakonczenie\n";
}
void sellers() // funckja wypisuje istniejacych sprzedawcow
{
    for(int i=0;i<sel.size();i++)
    {
        cout<<sel[i].first<<" "<<sel[i].second.Get_name()<<" "<<sel[i].second.Get_surname()<<endl;
    }
}
int main()
{
    return 0;
}
