#include <iostream>
#include "Menu.hpp"
#include "Budzet.hpp"
#include "fstream"
#include "iomanip"

using namespace std;

void Menu::pokaz_menu()
{
    cout << "-------------------------------------------------"<<endl;
    cout << "----------------- Budzet Domowy -----------------"<<endl;
    cout << "-------------------------------------------------"<<endl;
    cout << "1 - Podaj kwote do dyspozycji w tym miesiacu"<<endl;
    cout << "2 - Wybierz wydatek"<<endl;
    cout << "3 - Wynik"<<endl;
    cout << "4 - Zakoncz"<<endl;
    cout << "-------------------------------------------------"<<endl;
    cout << "Podaj numer operacji: "<<endl;
    char odp;
    cin >> odp;
    switch(odp)
    {
    case '1':
        b.podaj_kwote();
        break;
    case '2':
        cout << "S - Staly"<<endl;
        cout << "J - Jednorazowy"<<endl;
        cout << "N - Nieregularny"<<endl;
        cout << "W - Wroc do menu"<<endl;
        char o;
        cin>>o;
        switch(o)
        {
            case 'S':
            case 's':
                cout<<"Wydatek staly"<<endl;
                file="wydatki stale.dat";
                break;
            case 'J':
            case 'j':
                cout<<"Wydatek jednorazowy"<<endl;
                break;
            case 'N':
            case 'n':
                cout<<"Wydatek nieregularny"<<endl;
                break;
            case 'W':
            case 'w':
                pokaz_menu();
                break;
        }
        break;
    case '3':
        cout << "Wynik"<<endl;
        break;
    case '4':
        exit(EXIT_SUCCESS);
        break;
    }
}

void Menu::wyswietl_wydatek()
{
    ifstream fin;
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << "Lista twoich aktualnych wydatkow stalych: "<<endl;
        while (fin.read((char *) &wyd, sizeof wyd))
        {
            cout<<setw(20)<< wyd.nazwa<<": "
                <<setprecision(2)<<setw(12)<<wyd.kwota<<endl;
        }
    fin.close();
    }
    ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
    if(!fout.is_open())
    {
        cerr << "Nie mozna otworzyc pliku "<<file<<" do zapisu.\n";
        exit(EXIT_FAILURE);
    }
    cout<<"Podaj nowy wydatek (aby zakonczyc, wprowadz pusty wiersz)\n";
    cin.get(wyd.nazwa,20);
    while (wyd.nazwa[0] != '\0')
    {
        cout<<"Podaj kwote: ";
        cin>>wyd.kwota;
        cin.ignore();
        fout.write((char *) &wyd, sizeof wyd);
        cout<<"Podaj nowy wydatek (aby zakonczyc, wprowadz pusty wiersz)\n";
        cin.get(wyd.nazwa,20);
    }
    fout.close();
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << "Lista twoich aktualnych wydatkow stalych: "<<endl;
        while (fin.read((char *) &wyd, sizeof wyd))
        {
            cout<<setw(20)<< wyd.nazwa<<": "
                <<setprecision(2)<<setw(12)<<wyd.kwota<<endl;
        }
    fin.close();
    }
    cout<<"Koniec."<<endl;
}




