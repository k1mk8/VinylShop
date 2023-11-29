#include "credit.h"
#include <utility>
#include <cmath>

Credit::Credit(){}
Credit::Credit(double debt1, int installment1){//konstruktor domyślny
    debt = debt1;
    installment = installment1;
    startingInstallment = installment1;
    rate = calculate_rate();
}

void Credit::set_debt(double debt1) {debt = debt1;}
void Credit::set_installment(int installment1) {installment = installment1;}
double Credit::get_debt() {return debt;}
int Credit::get_installment() {return installment;}
int Credit::get_startingInstallment() {return startingInstallment;}
double Credit::get_rate() {return rate;}
double Credit::calculate_rate(){
    double interest = pow(1.02, installment);
    double monthRate = round(((debt * interest) / startingInstallment) * 100) / 100.0;
    return monthRate;
}
void Credit::loan_repayment(){
    --installment;
}

ostream& operator<<(ostream& os, Credit& sel) // przeciążenie operatora wypisania
{
    os <<"Kwota kredytu: "<< sel.get_debt() <<"\n";
    os <<"Ilość rat: "<< sel.get_startingInstallment() <<"\n";
    os <<"Misięczna rata: "<< sel.get_rate() <<"\n";
    return os;
}
