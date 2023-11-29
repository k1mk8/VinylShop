#include "concern.h"
#include <limits>
using namespace std;

Concern::Concern(){
    apply_constants();
}
Concern::Concern(string name1)
{
    apply_constants();
    name = name1;
}

void Concern::apply_constants(){
    numberOfStaff["engineer"] = 1; 
    numberOfStaff["marketer"] = 1; 
    numberOfStaff["storekeeper"] = 1;
    numberOfStaff["worker"] = 1; 
    staffProductivity["CI"] = 70;
    staffProductivity["CMag"] = 70; 
    staffProductivity["CMkt"] = 70; 
    staffProductivity["CR"] = 70; 
}
void Concern::display_employee() const{
    for (const auto& employee : employees) {
        visit([](const auto& emp) {
            cout << "Imię pracownika: " << emp->get_firstName() << " Wynagrodzenie pracownika: " << emp->get_salary()<< "\n";
        }, employee);
    }
}
void Concern::modify_number_of_employees(string profession){++numberOfStaff[profession];}
string Concern::get_name() {return name;}
double Concern::get_accountBalance() {return accountBalance;}
double Concern::get_concernValue(){return concernValue;}
double Concern::get_expectedConcernValue(){return expectedConcernValue;}
void Concern::set_name(string name1) {name = name1;}
void Concern::set_accountBalance(double accountBalance1) {accountBalance = accountBalance1;}
void Concern::take_loan(){
    double loanAmount;
    int loanDuration;
    string input;
    while (true) {
        cout << "Podaj kwotę pożyczki: ";
        cin >> input;

        try {
            size_t pos;
            loanAmount = stod(input, &pos);
            if (pos == input.length()) {
                break;
            }
        } catch (const invalid_argument&) {
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawny format liczby. Spróbuj ponownie." << endl;
    }
    while (true) {
        cout << "Podaj długość pożyczki (w miesiącach): ";
        cin >> input;

        try {
            size_t pos;
            loanDuration = stoi(input, &pos);

            if (pos == input.length()) {
                break;
            }
        } catch (const invalid_argument&) {
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawny format liczby całkowitej. Spróbuj ponownie." << endl;
    }
    if(loanDuration > maxTimeOfCredit){
        cout<<"Maksymalna długość czasu kredytu to: " << maxTimeOfCredit << " Spróbuj ponownie\n";
        return;
    }
    else if(loanAmount > maxMultipleOfConcernValue * concernValue){
        cout<<"Maksymalna kwota kredytu, który może aktualnie wziąć to: " << maxMultipleOfConcernValue * concernValue << " Spróbuj Ponownie\n";
        return;
    }
    Credit credit(loanAmount, loanDuration);
    auto creditArray = make_unique<Credit[]>(1);
    creditArray[0] = credit;
    credits.emplace_back(move(creditArray));
    cout << "Gratulacje udało Ci się zaciągnąć kredy o wartości: " << loanAmount << " Na okres: " << loanDuration <<"\n";
    set_accountBalance(get_accountBalance() + loanAmount);
}

void Concern::calculate_at_month_end(){
    double salaries = workers_salary();
    double rates = credits_rate();
    double income = calculate_income();
    double revenue = income - rates - salaries;
    set_accountBalance(get_accountBalance() + revenue);
    if(previousConcernValue.size() < monthsOfConcernValue){
        previousConcernValue.push(revenue);
    }
    else {
        previousConcernValue.pop();
        previousConcernValue.push(revenue);
    }
    calculate_concernValue();
}

double Concern::workers_salary(){
    double concernSalary = 0;
    for (const auto& employee : employees) {
        visit([&concernSalary](const auto& emp) {
            concernSalary += emp->get_salary();
        }, employee);
    }
    return concernSalary;
}

double Concern::credits_rate(){
    double rates = 0.0;
    int installment;
    if(!credits.empty()){
        auto it = credits.begin();
        while (it != credits.end()) {
            installment = 1;
            for (int i = 0; i < 1; ++i) {
                Credit& credit = (*it)[i];
                credit.loan_repayment();
                rates += credit.get_rate();
                installment = credit.get_installment();
                if(installment == 0){
                    it = credits.erase(it);
                }
                else{++it;}
            }
        }
    }
    return rates;
}

double Concern::calculate_income(){
    int maximumProducts = int(numberOfStaff["worker"] * staffProductivity["CR"]);
    int storeCapacity = int(numberOfStaff["storekeeper"] * staffProductivity["CMag"]);
    int soldProducts = min(maximumProducts, storeCapacity);
    int demand = int(numberOfStaff["marketer"] * staffProductivity["CMkt"]);
    soldProducts = min(soldProducts, demand);
    double income = soldProducts * (numberOfStaff["engineer"] * staffProductivity["CI"]);
    return income;
}

void Concern::calculate_concernValue(){
    queue<double> temporaryQ = previousConcernValue;
    double summaryValue = 0.0;
    while(!temporaryQ.empty()){
        summaryValue += temporaryQ.front();
        temporaryQ.pop();
    }
    if(!previousConcernValue.empty()){
        concernValue = round((summaryValue / monthsOfConcernValue) * 100.0) / 100.0;
    }
    else {concernValue = 0.0;}
}