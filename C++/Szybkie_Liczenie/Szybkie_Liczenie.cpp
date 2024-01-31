#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

clock_t start, stop;
int a, b, wynik, odp;
short int cyfry = 1, wybor = 1;

int main()
{
    for (;;)
    {
        cout << "Podaj z ilu cyfr maksymalnie ma sie skladac liczba(1-4): "; 
        cin >> cyfry;

        switch (cyfry)
        {
        case 1:
            cyfry = 10;
            break;
        case 2:
            cyfry = 100;
            break;
        case 3:
            cyfry = 1000;
            break;
        case 4:
            cyfry = 10000;
            break;
        default:
            exit(0);
            break;
        }

        cout << "Podaj czy chcesz dodawac czy odejmowac(1-dodawanie,2-odejmowanie): "; 
        cin >> wybor;

        srand(time(NULL));
        a = (rand() % cyfry) - 1;
        b = (rand() % cyfry) - 1;

        cout << "Pierwsza liczba: " << a << endl << "Druga liczba: " << b << endl;

        if (wybor == 1)
        {
            wynik = a + b;
        }
        else if (wybor == 2)
        {
            wynik = a - b;
        }
        else
        {
            exit(0);
        }

        cout << "Podaj wynik: ";
        start = clock();
        cin >> odp;

        if (odp == wynik)
        {
            stop = clock();
            cout << "Dobra odpowiedz !" << endl;
            cout << "Czas odpowiedzi to: " << (double)(stop - start) / CLOCKS_PER_SEC << " sekund." << endl << endl;
        }
        else
        {
            cout << "Zla odpowiedz." << endl << endl;
        }
    }
    return 0;
}