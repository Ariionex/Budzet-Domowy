#pragma once
#include <vector>

using namespace std;

class Wydatek
{
public:
    //enum{LI=20};
    string nazwa;
    double kwota;
    Wydatek(string naz = " ",double k =0) : nazwa(naz),kwota(k){}
};

class Budzet
{
private:
    double saldo; //saldo koncowe
    double cal_kwota; //calkowita kwota do dyspozycji
    Wydatek w;
    //vector<Wydatek> *wsk = nullptr;
public:
    void podaj_kwote();
    void wyswietl_wydatek(vector<Wydatek> );
    void pokaz_wynik();
    void wybierz_wydatek();
    double sumuj(string);
    double sumuj_wyd_niereg(string);

};

