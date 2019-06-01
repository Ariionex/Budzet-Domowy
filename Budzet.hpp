#pragma once
#include <vector>

using namespace std;

class Wydatek
{
public:
    char nazwa[20];
    double kwota;
    Wydatek(string naz = " ",double k =0) : nazwa(naz),kwota(k){}
};

class Budzet
{
private:
    double saldo; //saldo koncowe
    double cal_kwota; //calkowita kwota do dyspozycji
    vector<Wydatek> s_wydatek{}; //wydatek staly
    vector<Wydatek> j_wydatek{}; //wydatek jednorazowy
    vector<Wydatek> n_wydatek{}; //wydatek nieregularny
    //vector<Wydatek> *wsk = nullptr;
public:
    void podaj_kwote(Budzet  d);
    void dodaj_wydatek();
    void wyswietl_wydatek(vector<Wydatek> );
    void pokaz_wynik();
    void wybierz_wydatek();
    double sumuj(vector<Wydatek>, double);
    double sumuj_wyd_niereg(vector<Wydatek>, double);

};

