#ifndef CONCERN_H
#define CONCERN_H

#include<variant>
#include<bits/stdc++.h>
#include"credit.h"
#include"engineer.h"
#include"marketer.h"
#include"storekeeper.h"
#include"worker.h"
#include<vector>

using namespace std;

class Concern
{
private:
    string name; // nazwa firmy
    double accountBalance = 10000.0; // stan konta
    vector<unique_ptr<Credit[]> > credits; // kredyty firmy
    using work = variant<unique_ptr<Engineer>, unique_ptr<Marketer>, unique_ptr<StoreKeeper>, unique_ptr<Worker> >; // jeden z pracowników
    const int monthsOfConcernValue = 6; // liczby miesięcy, z której liczona jest wartość koncernu
    vector<work> employees; // vector pracowników
    queue <double> previousConcernValue; // kolejka przetrzymująca poprzednie wartości firmy
    const int maxTimeOfCredit = 12; // maksymalna długość kredytu
    const double maxMultipleOfConcernValue = 3.0; // maksymalna wartość kredytu w stosunku do wartości firmy
    double concernValue = 0.0; // wartość firmy
    double expectedConcernValue = 100000; // oczekiwana wartość firmy do wygranej
    map <string, int> numberOfStaff; // licznik poszczególnych typów pracowników
    map <string, double> staffProductivity; // mapa z przyporządkowaną produktywnością pracowników
public:
    Concern();
    Concern(string name1); // konstruktor firmy
    void apply_constants(); // ustawienie stałych
    template <typename T> void add_employee(string name, T&& employeeDetails); // dodawanie pracowników
    void modify_number_of_employees(string profession);
    void display_employee() const; // wyświetlanie pracowników
    string get_name(); // zwraca nazwę firmy
    double get_accountBalance(); // zwraca stan konta firmy
    double get_concernValue(); // zwraca wartość firmy
    double get_expectedConcernValue(); // zwraca wartość koncernu, którą trzeba osiągnąć
    void set_name(string name1); // setter nazwy firmy
    void set_accountBalance(double accountBalance1); // setter stanu konta
    void take_loan(); // branie kredytu
    void calculate_at_month_end(); // obliczenia na koniec tury
    double workers_salary(); // obliczenie wynagrodzenia do zapłacenia pracownikom
    double credits_rate(); // obliczenie miesięcznych rat kredytu
    double calculate_income(); // obliczanie przychodu
    void calculate_concernValue(); // obliczanie wartości firmy
};

#endif