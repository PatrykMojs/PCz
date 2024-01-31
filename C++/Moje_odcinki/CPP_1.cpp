/*  Język C++
    Kod ma za zadanie przedstawienie podstawowych obliczeń
    takich jak: dodawanie, odejmnowanie, dziele oraz mnożenie 
    wszystko zapisujemy w funkcji góółównej "main()" */

#include <iostream>

using namespace std;

int main()
{
    int liczba1=1, liczba2=2; //typ całokwity
    float liczba3=2.4, liczba4=4.2; //typ zmiennoprzecinkowy pojedyńczej precyzji
    double liczba5=4.44, liczba6=8.21; //typ zmiennoprzecinkowy podwójnej precyzji

    //--------------------------------------------------------------------------------------

    //Dodawanie liczb całkowitych

    cout << liczba1 << "+" << liczba2 << "=" << liczba1 + liczba2 << endl;

    //Lub

    int wynik1=liczba1+liczba2;
    cout << liczba1 << "+" << liczba2 << "=" << wynik1 << endl;

    //--------------------------------------------------------------------------------------

    //Odejmowanie liczb zmiennoprzecinkowych pojedyńczej precyzji

    cout << liczba3 << "-" << liczba4 << "=" << liczba3 - liczba4 << endl;

    //Lub

    float wynik2 = liczba3 - liczba4;
    cout << liczba3 << "-" << liczba4 << "=" << wynik2 << endl;

    //--------------------------------------------------------------------------------------

    //Mnożenie liczby całokwietej dla lepszej czytelności

    cout << liczba1 << "*" << liczba2 << "=" << liczba1 * liczba2 << endl;

    //Lub

    int wynik3 = liczba1 * liczba2;
    cout << liczba1 << "*" << liczba2 << "=" << wynik3 << endl;

    //--------------------------------------------------------------------------------------

    //Dzielenie liczb zmiennoprzecinkowych podwójnej precyzji

    cout << liczba5 << "/" << liczba6 << "=" << liczba5 / liczba6 << endl;

    //Lub

    double wynik4 = liczba5 / liczba6;
    cout << liczba5 << "/" << liczba6 << "=" << wynik4 << endl;

    //Teraz zrobimy to samo ale dla liczb podawanych z klawiatury

    int liczba_podana1, liczba_podana2;

    cout << "Podaj pierwsza liczbe calkowita: ";
    cin >> liczba_podana1;
    cout << "Podaj druga liczbe calkowita: ";
    cin >> liczba_podana2;

    cout << "Suma: " << liczba_podana1 + liczba_podana2 << endl;
    cout << "Roznica: " << liczba_podana1 - liczba_podana2 << endl;
    cout << "Iloczyn: " << liczba_podana1 * liczba_podana2 << endl;
    cout << "Iloraz: " << (float)liczba_podana1 / liczba_podana2 << endl;

    return 0;
}
