#ifndef CREDIT_H
#define CREDIT_H
#include <bits/stdc++.h>
#include <ostream>

using namespace std;
class Credit
{
private:
    double debt; // dług kredytu
    int installment; // pozostała ilość rat
    int startingInstallment; // startowa ilość rat
    double rate; // rata kredytu ustalana na podstawie ilości rat
public:
    Credit();
    Credit(double debt1, int installment1); // konstruktor kredytu
    void set_debt(double debt1); // setter długu kredytu
    void set_installment(int installment1); // setter ilości rat
    double get_debt(); // getter długu kredytu
    int get_installment(); // getter ilości rat
    int get_startingInstallment(); // początkowa ilość rat
    double get_rate(); // getter misięcznej raty
    double calculate_rate(); // obliczenie raty
    void loan_repayment(); // spłacanie kredytu
    friend ostream& operator<<(ostream& os, Credit& sel); // wypisywanie całego obiektu
};

#endif