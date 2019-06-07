#pragma once
#include "Budzet.hpp"

class Menu
{
private:
    string file;
    Budzet b;
    Wydatek wyd;
public:
    void pokaz_menu();
    void wyswietl_wydatek();
    //void wyswietl_wszystkie_wydatki();
};
