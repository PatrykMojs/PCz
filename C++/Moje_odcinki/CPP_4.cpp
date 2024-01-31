/*  Język C++
    Kod ma za zadanie przedstawienie podstawowych obliczeń
    takich jak: dodawanie, odejmnowanie, dziele oraz mnożenie tablicy */

#include <iostream>

using namespace std;

void dodaj(int *tab)
{
    int suma = 0;

    for (int i = 0; i < 5; i++)
    {
        suma += tab[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (i < 4)
        {
            cout << tab[i] << "+";
        }
        else
        {
            cout << tab[i] << "=";
        }
    }

    cout << suma << endl;
}

void odejmij(int* tab)
{
    int roznica = tab[0];

    for (int i = 1; i < 5; i++)
    {
        roznica -= tab[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (i < 4)
        {
            cout << tab[i] << "-";
        }
        else
        {
            cout << tab[i] << "=";
        }
    }

    cout << roznica << endl;
}

void pomnoz(int* tab)
{
    int iloczyn = 1;

    for (int i = 0; i < 5; i++)
    {
        iloczyn *= tab[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (i < 4)
        {
            cout << tab[i] << "*";
        }
        else
        {
            cout << tab[i] << "=";
        }
    }

    cout << iloczyn << endl;
}

void podziel(int* tab)
{
    float iloraz = 1;

    for (int i = 0; i < 5; i++)
    {
        iloraz /= tab[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (i < 4)
        {
            cout << tab[i] << "*";
        }
        else
        {
            cout << tab[i] << "=";
        }
    }

    cout << iloraz << endl;
}

int main()
{
    char znak, TakNie;
    int tablica_liczb_clkowitych[5];

    do {

        for (int i = 0; i < 5; i++)
        {
            cout << "Podaj " << i + 1 << " liczbe: ";
            cin >> tablica_liczb_clkowitych[i];
        }

        system("cls");

        cout << "----------------------------------" << endl;
        cout << " >>> Wybierz co ma sie wykonac <<<" << endl;
        cout << "  *** Dodawanie calej tablicy *** " << endl;
        cout << " *** Odejmowanie calej tablicy *** " << endl;
        cout << "  *** Mnozenie calej tablicy *** " << endl;
        cout << "  *** Dzielenie calej tablicy *** " << endl;
        cout << "----------------------------------" << endl;
        cout << "      >>> Co wybierasz? <<< " << endl;

        cin >> znak;

        switch (znak)
        {
        case '+':
            dodaj(tablica_liczb_clkowitych);
            break;
        case '-':
            odejmij(tablica_liczb_clkowitych);
            break;
        case '*':
            pomnoz(tablica_liczb_clkowitych);
            break;
        case '/':
            podziel(tablica_liczb_clkowitych);
            break;
        }

        cout << "Czy chcesz powtorzyc operacje?(T/N)";
        cin >> TakNie;
    } while (TakNie=='T');
    
    return 0;
}
