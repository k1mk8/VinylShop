#include <bits/stdc++.h>
#include "include/game.h"
#include "source/concern.tpp"
#include <random>
#include <chrono>

using namespace std;

int main()
{
    Game game("Fabryka butów");
    int game_status = game.player_action();
    while(game_status == 1){
        game_status = game.player_action();
    }
    if(game_status == 0){
        cout<< "Przykro nam, ale niestety Twoja firma zbankrutowała po ostatnim miesiącu, przez niewystarczającą ilość środków na koncie! Spróbuj jeszcze raz\n";
    }
    else if(game_status == 2){
        cout<< "Gratulacje! Stałeś się potentatem na rynku, a Twoja firma świetnie prosperuje. Teraz możesz się cieszyć zarobionymi pieniędzmi!\n";
    }
    return 0;
}