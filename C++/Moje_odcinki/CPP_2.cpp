/*  Język C++
    Kod ma za zadanie przedstawienie podstawowych obliczeń
    takich jak: dodawanie, odejmnowanie, dziele oraz mnożenie
    za pomocą funkcji wywoływanych we funkcji main */
#include <iostream>

using namespace std;

int Dodawanie(int l1, int l2)
{
    return l1 + l2;
}

int Odejmowanie(int l1, int l2)
{
    int wynik;
    wynik = l1 - l2;
    return wynik;
}

void Mnozenie(int l1, int l2)
{
    int wynik;
    wynik = l1 * l2;
    cout << "Wynik mnozenia: " << l1 << "*" << l2 << "=" << wynik << endl;
}

void Dzielenie(int l1, int l2)
{
    cout << "Wynik dzielenia: " << l1 << "/" << l2 << "=" << (float)l1 / l2 << endl;
}

int main()
{
    int liczba1, liczba2;

    cout << "Podaj pierwsza liczbe: ";
    cin >> liczba1;
    cout << "Podaj druga liczbe: ";
    cin >> liczba2;

    cout << "Wynik dodawania: " << liczba1 << "+" << liczba2 << "=" << Dodawanie(liczba1, liczba2) << endl;
    cout << "Wynik odejmowania: " << liczba1 << "-" << liczba2 << "=" << Odejmowanie(liczba1, liczba2) << endl;
    Mnozenie(liczba1, liczba2);
    Dzielenie(liczba1, liczba2);

    return 0;
}

