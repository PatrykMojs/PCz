/*  Język C++
    Kod ma za zadanie przedstawienie podstawowych obliczeń
    takich jak: dodawanie, odejmnowanie, dziele oraz mnożenie
    za pomocą funkcji wywoływanych we funkcji main 
    ale to uzytkownik zadecyduje jakie obliczenie ma się wykonać */
#include <iostream>

using namespace std;

//Funkcje z poprzedniego odcinka

void Dodawanie(int l1, int l2)
{
    cout << "Wynik mdodawania: " << l1 << "+" << l2 << "=" << l1 + l2 << endl;
}

void Odejmowanie(int l1, int l2)
{
    cout << "Wynik odejmowania: " << l1 << "-" << l2 << "=" << l1 - l2 << endl;
}

void Mnozenie(int l1, int l2)
{
    cout << "Wynik mnozenia: " << l1 << "*" << l2 << "=" << l1 * l2 << endl;
}

void Dzielenie(int l1, int l2)
{
    cout << "Wynik dzielenia: " << l1 << "/" << l2 << "=" << (float)l1 / l2 << endl;
}

int main()
{
    int liczba1, liczba2;
    char znak, wybor='Y';

    do {

        cout << "Podaj pierwsza liczbe: ";
        cin >> liczba1;
        cout << "Podaj druga liczbe: ";
        cin >> liczba2;

        cout << "--------------------------" << endl;
        cout << "Jakie chcesz wykonac obliczenie?" << endl;
        cout << "Dodawanie >> + <<" << endl;
        cout << "Odejmowanie >> - <<" << endl;
        cout << "Mnozenie >> * <<" << endl;
        cout << "Dzielenie >> / <<" << endl;
        cout << "--------------------------" << endl;

        cout << "Jakie dzialanie matematyczne wybierasz? ";
        cin >> znak;

        switch (znak)
        {
        case '+':
            Dodawanie(liczba1, liczba2);
            break;
        case '-':
            Odejmowanie(liczba1, liczba2);
            break;
        case '*':
            Mnozenie(liczba1, liczba2);
            break;
        case '/':
            Dzielenie(liczba1, liczba2);
            break;
        }

        cout << "Czy chcesz cos jeszcze zrobic z tymi liczbami?(Y/N)";
        cin >> wybor;
        system("cls");
    } while (wybor != 'N');
    

    return 0;
}

