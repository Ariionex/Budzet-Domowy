#include <iostream>
#include "Budzet.hpp"

using namespace std;

void Budzet::podaj_kwote(Budzet  d)
{
    cout<<"Podaj kwote do dyspozycji: ";
    cin>>d.cal_kwota;
    cout<<endl;
    cout<<"Calkowita kwota wynosi: "<<d.cal_kwota<<endl;
}

/*void Budzet::dodaj_wydatek()
{
    string x;
    double y;
    char odp;
    char wybor;
    char rodzaj;
        cout<<"Ktore wydatki chcesz dodac ?"<<endl;
        cout<<"S - Wydatki stale"<<endl;
        cout<<"J - Wydatki jednorazowe"<<endl;
        cout<<"N - Wydatki nieregularne (kwartalnie)"<<endl;
        cin>>wybor;
    do{
        cout<<"Dodaj wydatek: "<<endl;
        cout<<"Nazwa: ";
        cin>>x;
        cout<<"Kwota: ";
        cin>>y;
        if(wybor == 's' || wybor == 'S')
            s_wydatek.emplace_back(Wydatek(x,y));
        else if(wybor == 'j' || wybor == 'J')
            j_wydatek.emplace_back(Wydatek(x,y));
        else if(wybor == 'n' || wybor == 'N')
            n_wydatek.emplace_back(Wydatek(x,y));
        else
            cout<<"Nie ma takiej opcji"<<endl;
        cout<<"Czy chcesz dodac jeszcze jeden wydatek ?"<<endl;
        cout<<"T/N"<<endl;
        cin>>odp;
    }while(odp=='t'||odp=='T');
    cout<<"Chcesz zmienic rodzaj wydatku ?"<<endl;
    cout<<"T/N"<<endl;
    cin>>rodzaj;
    if (rodzaj=='t'||rodzaj=='T')
        dodaj_wydatek();

}
void Budzet::wyswietl_wydatek(vector<Wydatek> w)
{
    for(auto a:w)
    {
        cout<<"Nazwa: "<<a.nazwa<<" Kwota: "<<a.kwota<<endl;
    }
}
void Budzet::wybierz_wydatek()
{
    char odp;
    cout<<"Ktore wydatki chcesz zobaczyc ?"<<endl;
    cout<<"S - Wydatki stale"<<endl;
    cout<<"J - Wydatki jednorazowe"<<endl;
    cout<<"N - Wydatki nieregularne (kwartalnie)"<<endl;
    cin>>odp;
    if(odp == 's' || odp == 'S')
        wyswietl_wydatek(s_wydatek);
    else if(odp == 'j' || odp == 'J')
        wyswietl_wydatek(j_wydatek);
    else if(odp == 'n' || odp == 'N')
        wyswietl_wydatek(n_wydatek);
    else
        cout<<"Nie ma takiej opcji"<<endl;
    cout<<"Czy chcesz zmienic wyswietlany wydatek ?"<<endl;
    cout<<"T/N"<<endl;
    cin>>odp;
    if (odp=='t'||odp=='T')
        wybierz_wydatek();
}
double Budzet::sumuj(vector<Wydatek> q, double  x)
{
    x=0;
    for(auto a:q)
    {
        x+=a.kwota;
    }
    return x;
}
void Budzet::pokaz_wynik()
{
    double cal_saldo;
    double suma;
    double saldo = cal_kwota;
    cal_saldo=saldo - (sumuj(s_wydatek, suma)+ sumuj_wyd_niereg(n_wydatek, suma)) - sumuj(j_wydatek, suma) ;
    cout<<"Zostanie Ci na koniec tego miesiaca: "<<cal_saldo<<endl;
}
double Budzet::sumuj_wyd_niereg(vector<Wydatek> q, double x)
{
    x=0;
    for(auto a:q)
    {
        (x+=a.kwota*4);
    }
    return x/10;
}*/
