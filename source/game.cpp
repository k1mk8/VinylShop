#include "game.h"
#include "concern.tpp"
#include <utility>
using namespace std;

Game::Game(){
    starting_workers();
}
Game::Game(string nameConcern) : concern(make_unique<Concern>(nameConcern)) {
    starting_workers();
}
void Game::starting_workers(){
    concern->add_employee(generateRandomName(), Engineer("Robotyka i automatyka"));
    concern->add_employee(generateRandomName(), StoreKeeper(true));
    concern->add_employee(generateRandomName(), Marketer(50));
    concern->add_employee(generateRandomName(), Worker(35.5));
}
string Game::interface(){
    cout << "Twój aktualny stan konta to:\n" << concern->get_accountBalance() << "\n\n";
    cout << "Twoja aktualna wartość firmy to:\n" << concern->get_concernValue() << "\n\n";
    cout << "Wybierz akcję do wykonania w następnym miesiącu lub zakończ turę, oto lista możliwych poleceń i działań:\n";
    cout << "lp - wylistuj pracowników zatrudnionych w firmie\n";
    cout << "zinz - zatrudnij inżyniera\n";
    cout << "zmag - zatrudnij magazyniera\n";
    cout << "zmkt - zatrudnij marketera\n";
    cout << "zrob - zatrudnij robotnika\n";
    cout << "kred - weź kredyt, w następnych krokrach wybierzesz kwotę oraz czas spłaty\n";
    cout << "kt - zakończ turę i wyświetl stan firmy na początku nastepnego miesiąca\n\n";
    cout << "wpisz wybraną komendę do terminala\n";
    string playerInput;
    cin >> playerInput;
    while(playerInput != "lp" && playerInput != "zinz" && playerInput != "zmag" && playerInput != "zmkt" && playerInput != "zrob" && playerInput != "kred" && playerInput != "kt"){
        cout << "\nNiewłaściwa komenda!\n";
        cout << "Wprowadź komendę ponownie\n";
        cin >> playerInput;
    }
    return playerInput;
}
int Game::player_action(){
    if(concern->get_accountBalance() < 0 ) {
        cout << "Twój aktualny stan konta to:\n" << concern->get_accountBalance() << "\n\n";
        cout << "Twoja aktualna wartość firmy to:\n" << concern->get_concernValue() << "\n\n";
        return 0;
    }
    else if(concern->get_concernValue() - concern->credits_rate() - concern->workers_salary() >= concern->get_expectedConcernValue()){
        cout << "Twój aktualny stan konta to:\n" << concern->get_accountBalance() << "\n\n";
        cout << "Twoja aktualna wartość firmy to:\n" << concern->get_concernValue() << "\n\n";
        return 2;
        }
    string playerInput = interface();
    if(playerInput == "kt"){
        cout << "Zakończyłeś podany miesiąc! Zajmujemy się sprzedażą produktów i obliczymy Twoją wartość w następnym miesiącu!\n\n\n";
        concern->calculate_at_month_end();
    }
    else if(playerInput == "lp"){concern->display_employee();}
    else if(playerInput == "zinz"){concern->add_employee(generateRandomName(), Engineer("Robotyka i automatyka")); concern->modify_number_of_employees("engineer");}
    else if(playerInput == "zmag"){concern->add_employee(generateRandomName(), StoreKeeper(true));concern->modify_number_of_employees("storekeeper");}
    else if(playerInput == "zmkt"){concern->add_employee(generateRandomName(), Marketer(50));concern->modify_number_of_employees("marketer");}
    else if(playerInput == "zrob"){concern->add_employee(generateRandomName(), Worker(35.5));concern->modify_number_of_employees("worker");}
    else if(playerInput == "kred"){concern->take_loan();}
    return 1;
}

int Game::randomInt(int min, int max){return min + rand() % (max - min + 1);}
string Game::generateRandomName(){
    vector<string> availableNames = {"Anna", "Bob", "Catherine", "David", "Emma", "Frank", "Grace", "Henry", "Kristopher", "Lena", "Marie"};
    int index = randomInt(0, availableNames.size() - 1);
    return availableNames[index];
}


