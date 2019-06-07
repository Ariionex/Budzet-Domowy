#include <iostream>
#include "Menu.hpp"
#include "Budzet.hpp"
#include <fstream>
#include <iomanip>

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
        cout<<"Koniec."<<endl;
        exit(EXIT_SUCCESS);
        break;
    }
}

void Menu::wyswietl_wydatek()
{
    fstream finout;
    finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
    int ct = 0;
    if (!(finout.is_open()))
        {
            cout<<"Nie ma takiego pliku, ale zaraz to naprawimy :)"<<endl;
            ofstream fout(file);
            cout<<"Puf... i juz mamy"<<endl;
        }
    else if(finout.is_open())
    {
        finout.seekg(0);
        cout<<"Oto aktualna zawartosc pliku"<<endl;
        while(finout.read((char *) &wyd, sizeof wyd))
        {
            cout<<ct++<<": "<<setw(20)<<wyd.nazwa<<": "
            <<setprecision(4)<<setw(12)<<wyd.kwota<<endl;
        }
        if(finout.eof())
            finout.clear();
        else
        {
            cerr<<"Blad przy probie odczytu pliku "<<file<<"."<<endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        cerr<<"Nie mozna otworzyc pliku "<<file<<" -- koniec pracy programu."<<endl;
        exit(EXIT_FAILURE);
    }

    cout<<"Chcesz dodac nowy rekord, usunac czy zmodyfikowac aktualny ?"<<endl;
    cout<<"N - Nowy"<<endl;
    cout<<"M - Modyfikuj"<<endl;
    cout<<"U - Usun pozycje"<<endl;
    cout<<"C - Cofnij do Menu"<<endl;
    char odp;
    cin>>odp;
    if(odp=='N'||odp=='n')
    {
        cout<<"Podaj nowy wydatek (aby zakonczyc, wprowadz pusty wiersz)\n";
        cin.ignore();
        getline(cin,wyd.nazwa);
        while (!wyd.nazwa.empty())
        {
            cout<<"Podaj kwote: ";
            cin>>wyd.kwota;
            cin.ignore();
            streampos max = ct * sizeof wyd;
            finout.seekg(max);
            ct++;
            finout.write((char*) &wyd, sizeof wyd)<<flush;
            cout<<"Podaj nowy wydatek (aby zakonczyc, wprowadz pusty wiersz)\n";
            getline(cin,wyd.nazwa);
        }
    wyswietl_wydatek();
    }
    else if(odp=='M'||odp=='m')
    {
        cout<<"Podaj numer rekordu ktory chcesz zmienic: "<<endl;
        long rec;
        while(cin>>rec)
        {
        cin.ignore();
        if(rec<0 || rec>=ct)
        {
            cerr<<"Nieprawidlowy numer rekordu -- koniec pracy programu."<<endl;
            exit(EXIT_FAILURE);
        }
        streampos place = rec * sizeof wyd;
        finout.seekg(place);
        if(finout.fail())
        {
            cerr<<"Blad podczas wyszukiwania pozycji"<<endl;
            exit(EXIT_FAILURE);
        }
        finout.read((char *) &wyd, sizeof wyd);
        cout<<"Twoj wybor:"<<endl;
        cout<<rec<<": "<<setw(20)<<wyd.nazwa<<": "
        <<setprecision(4)<<setw(12)<<wyd.kwota<<endl;
        if(finout.eof())
            finout.clear();
        //cout<<"Podaj nazwe wydatku: ";
        //getline(cin,wyd.nazwa);
        cout<<"Podaj kwote wydatku: ";
        cin>>wyd.kwota;
        finout.seekp(place);
        finout.write((char *) &wyd, sizeof wyd)<<flush;
        if (finout.fail())
        {
            cerr << "Blad przy probie zapisu";
            exit(EXIT_FAILURE);
        }
        cout<<"Czy chcesz zmodyfikowac jeszcze jeden rekord ?"<<endl;
        cout<<"T/N"<<endl;
        char o;
        cin>>o;
        if(o=='N' || o=='n')
            break;
        cin.ignore();
        cout<<"Podaj numer rekordu ktory chcesz zmienic: "<<endl;
        }
        ct = 0;
        finout.seekg(0);
        cout<<"Oto nowa zawartosc pliku "<<endl;
        while(finout.read((char *) &wyd, sizeof wyd))
        {
            cout<<ct++<<": "<<setw(20)<<wyd.nazwa<<": "
            <<setprecision(4)<<setw(12)<<wyd.kwota<<endl;
        }
        finout.close();
        pokaz_menu();
    }
    else if(odp=='U'||odp=='u')
        {
            //cout<<"Ktora pozycje chcesz usunac ?"<<endl;
            cout<<"Funkcja aktualnie w trakcie tworzenia"<<endl;
            cout<<"Zapraszam do menu"<<endl;
            pokaz_menu();

        }
    else if(odp=='C'||odp=='c')
        pokaz_menu();
    else
    {
        cout<<"Nie ma takiej odpowiedzi, sprobuj ponownie."<<endl;
        wyswietl_wydatek();
    }
}


