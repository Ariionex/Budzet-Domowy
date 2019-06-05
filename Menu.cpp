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
        pokaz_menu();
        break;
    case '2':
        cout << "S - Staly"<<endl;
        cout << "J - Jednorazowy"<<endl;
        cout << "N - Nieregularny"<<endl;
        cout << "A - Wyswietl listy wszysktich wydatkow"<<endl;
        cout << "W - Wroc do menu"<<endl;
        char o;
        cin>>o;
        switch(o)
        {
            case 'S':
            case 's':
                cout<<"Wydatek staly"<<endl;
                file="wydatki stale.dat";
                wyswietl_wydatek();
                break;
            case 'J':
            case 'j':
                cout<<"Wydatek jednorazowy"<<endl;
                file="wydatki jednorazowe.dat";
                wyswietl_wydatek();
                break;
            case 'N':
            case 'n':
                cout<<"Wydatek nieregularny (rocznie)"<<endl;
                file="wydatki nieregularne.dat";
                wyswietl_wydatek();
                break;
            case 'A':
            case 'a':
                cout<<"Wszystkie wydatki"<<endl;
            case 'W':
            case 'w':
                pokaz_menu();
                break;
        }
        break;
    case '3':
        cout << "Wynik"<<endl;
        b.pokaz_wynik();

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
    if (!(fin.is_open()))
        {
            cout<<"Nie ma takiego pliku, ale zaraz to naprawimy :)"<<endl;
            ofstream fout(file);
            cout<<"Puf... i juz mamy"<<endl;
        }
    else if (fin.is_open())
    {
        cout << "Lista twoich aktualnych wydatkow: "<<endl;
        while (fin.read((char *) &wyd, sizeof wyd))
        {
            cout<<setw(20)<< wyd.nazwa<<": "
                <<setprecision(4)<<setw(12)<<wyd.kwota<<endl;
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
    cin.ignore();
    getline(cin,wyd.nazwa);
    while (!wyd.nazwa.empty())
    {
        cout<<"Podaj kwote: ";
        cin>>wyd.kwota;
        cin.ignore();
        fout.write((char *) &wyd, sizeof wyd);
        cout<<"Podaj nowy wydatek (aby zakonczyc, wprowadz pusty wiersz)\n";
        getline(cin,wyd.nazwa);
    }
    fout.close();
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << "Lista twoich aktualnych wydatkow: "<<endl;
        while (fin.read((char *) &wyd, sizeof wyd))
        {
            cout<<setw(20)<< wyd.nazwa<<": "
                <<setprecision(4)<<setw(12)<<wyd.kwota<<endl;
        }
    fin.close();
    }
    cout<<"Chcesz wrocic do menu ?"<<endl;
    cout<<"T/N"<<endl;
    char odp;
    cin>>odp;
    if (odp=='T'||odp=='t')
        pokaz_menu();
    else
        cout<<"Koniec."<<endl;
        exit(EXIT_SUCCESS);
}





