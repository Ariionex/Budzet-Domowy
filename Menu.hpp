#pragma once
#include "Budzet.hpp"

class Menu
{
public:
    string file;
    Budzet b;
    Wydatek wyd;
    //double kwota;
    ////////////////
    void pokaz_menu();
    void wyswietl_wydatek();
    //void wyswietl_wszystkie_wydatki();
};
