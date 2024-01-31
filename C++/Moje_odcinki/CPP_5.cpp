/* W dzisiejszym odcinku przedstawie kod realizujący
   obliczanie iloczynu skalarnego. Do tego będą 
   potrzebne nam dwie tablice dwuwymiarowe. */

#include <iostream>

using namespace std;

void wypelnij(int** A, int** B, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Podaj A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Podaj B[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> B[i][j];
        }
    }
}

void wyswietl(int** A, int** B, const int n)
{
    cout << "Tablica A: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "| ";

        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }

        cout << "| " << endl;
    }

    cout << "Tablica B: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "| ";

        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }

        cout << "| " << endl;
    }
}

int iloczyn_skalarny(int** A, int** B, const int n)
{
    int wynik=0, tmp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp = A[i][j];
            tmp *= B[i][j];
            wynik += tmp;
        }
    }

    return wynik;
}

void zwolnij(int** A, int** B, const int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
        delete[] B[i];
    }

    delete[] A;
    delete[] B;
}

int main()
{
    int n;

    cout << "Podaj rozmiar tablicy: ";
    cin >> n;

    int** A = new int* [n];
    int** B = new int* [n];

    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        B[i] = new int[n];
    }

    wypelnij(A, B, n);
    system("cls");
    wyswietl(A, B, n);
    cout << endl;
    int wynik = iloczyn_skalarny(A, B, n);

    cout << "Iloczyn skalarny wynosi => " << wynik << endl;

    zwolnij(A, B, n);

    return 0;
}
