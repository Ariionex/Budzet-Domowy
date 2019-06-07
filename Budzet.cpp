#include <iostream>
#include <fstream>
#include "Budzet.hpp"

using namespace std;

void Budzet::podaj_kwote()
{
    cout<<"Podaj kwote do dyspozycji w tym miesiacu: ";
    cin>>cal_kwota;
    cout<<endl;
    cout<<"Calkowita kwota wynosi: "<<cal_kwota<<endl;
}

double Budzet::sumuj(const string & f)
{
    double x=0.0;
    ifstream fin(f, ios_base::in | ios_base::binary);
    if(fin.is_open())
    {
        while(fin.read((char *) &w, sizeof w))
        {
            x+=w.kwota;
        }
    fin.close();
    }
    return x;
}

void Budzet::pokaz_wynik()
{
    double saldo = cal_kwota;
    cout<<"Wydatki stale w tym miesiacu: "<<sumuj("wydatki stale.dat")+sumuj_wyd_niereg("wydatki nieregularne.dat")<<" zl"<<endl;
    cout<<"Wydatki lacznie w tym miesiacu: "<<sumuj("wydatki stale.dat")+sumuj_wyd_niereg("wydatki nieregularne.dat")+sumuj("wydatki jednorazowe.dat")<<" zl"<<endl;
    saldo=cal_kwota-(sumuj("wydatki stale.dat")+sumuj_wyd_niereg("wydatki nieregularne.dat")+sumuj("wydatki jednorazowe.dat"));
    cout<<"Zostanie Ci na koniec tego miesiaca: "<<saldo<<" zl"<<endl;
}
double Budzet::sumuj_wyd_niereg(const string & f)
{
    double x=0.0;
    x=sumuj(f);
    return x/10;
}
