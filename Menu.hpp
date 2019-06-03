#pragma once
#include "Budzet.hpp"

class Menu
{
public:
    const char * file;
    Budzet b;
    Wydatek wyd;
    //double kwota;
    ////////////////
    void pokaz_menu();
    void wyswietl_wydatek();
};
