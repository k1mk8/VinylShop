#ifndef GAME_H
#define GAME_H
#include <bits/stdc++.h>
#include <ostream>
#include "concern.h"

using namespace std;
class Game
{
private:
    unique_ptr<Concern> concern; // koncern gry
public:
    Game();
    Game(string nameConcern); // konstruktor kredytu
    ~Game() = default; // destruktor
    void starting_workers(); // ustawienie początkowych pracowników
    string interface(); // interface wyświetlany na ekranie
    int player_action(); // akcja gracza
    int randomInt(int min, int max);
    string generateRandomName();

};

#endif