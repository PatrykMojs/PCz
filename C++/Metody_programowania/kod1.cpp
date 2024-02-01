#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct SStudent //struktura stworzona zgodnie z trescia zadania
{
	string imie;
	string nazwisko;
	unsigned int nr_indeksu;	
};

//---------------- kropka 1-----------------------------------

bool wczytaj(ifstream& wejscie, SStudent*& s, unsigned& n) //funkcja zwracajaca prawde lub falsz 
{
	wejscie >> n; 										  

	if(n > 0)
	{
		s = new SStudent[n];							   //stworzenie tablicy dynamicznej struktur
		for(unsigned i=0; i<n; i++)
		{
			wejscie >> s[i].imie >> s[i].nazwisko >> s[i].nr_indeksu; //pobranie z pliku danych do tablicy
		}
		return true; 
	}
	else
		return false;
}

//---------------- kropka 2-----------------------------------

void wyswietl(const SStudent& dane) //funkcja wyswietla jeden obiekt struktury 
{
	cout << dane.imie << " " << dane.nazwisko << " " << dane.nr_indeksu << endl;
}

//---------------- kropka 3-----------------------------------

void wyswietl(const SStudent* dane, const unsigned n) //funkcja wyswietla wszystkie elementy struktury
{	
	for(unsigned i=0; i<n; i++)
	{
		wyswietl(dane[i]);		
	}	
}

//---------------- kropka 4-----------------------------------

void edycja(SStudent* d, const unsigned n) //funkcja edycja ktora pozwala edytowac kazdy element tablicy struktur 
{
	unsigned int zm, wybor;
	
	cout << endl;
	cout << "Czy chcesz zmienic dowolny element tablicy? " << endl; 
	cout << "Tak wcisnij-1 " << endl;							    
	cout << "Nie wcisnij-0 " << endl;	                            
	cin >> zm;
	
	system("cls"); //uzyto ze wzgledu na czytelnosc ekranu wynikowego
	
	while(zm!=0)
	{
		cout << "Co chcesz zmienic w tablicy? " << endl; //pytanie uzytkownika ktora kolumne chce zmienic "imie" "nazwisko" "nr_indeksu"
		cout << " >> Opcja 1: Imie <<" << endl;
		cout << " >> Opcja 2: Nazwisko <<" << endl;
		cout << " >> Opcja 3: Numer indeksu <<" << endl;
		
		cin >> wybor;
		
		switch(wybor)
		{
			case 1:
				{
					unsigned int a;
					cout << "Podaj numer wiersza w ktorym chcesz zmienic imie: "; 
					cin >> a;										              
					cout << "zmien imie studenta " << endl;
					cin >> d[a-1].imie;
					
				}
			break;
			case 2:
				{
					unsigned int b;
					cout << "Podaj numer wiersza w ktorym chcesz zmienic nazwisko: "; 
					cin >> b;                                                         
					cout << "zmien nazwisko studenta " << endl;
					cin >> d[b-1].nazwisko;
				}
			break;
			case 3:
				{
					unsigned int c;
					cout << "Podaj numer wiersza w ktorym chcesz zmienic numer indeksu: "; 
					cin >> c;                                                              
					cout << "zmien numer indeksu studenta " << endl;
					cin >> d[c-1].nr_indeksu;
				}
			break;
			default: 
			{
				cout << "Podano zla opcje !!! " << endl;
			}
			break;
		}
		
		wyswietl(d,n);
		
		cout << "Czy chcesz zmienic dowolny element tablicy? " << endl;
		cout << "Tak wcisnij-1 " << endl;
		cout << "Nie wcisnij-0 " << endl;
		cin >> zm;
		
		system("cls");
	}
}

//---------------- kropka 5-----------------------------------

void zapisz(ostream& wyj, const SStudent* dane, const unsigned n) //funkcja zapisujaca wszystkie elementy do pliku
{
    wyj << n << endl;
    for(unsigned i = 0; i < n; i++)
        wyj << dane[i].imie << " " << dane[i].nazwisko << " " << dane[i].nr_indeksu << endl;
}

void usun(SStudent* d) //dodatkowa funkcja ktora zwalnia pamiec ze wzgledu na tablice dynamiczna
{
	if(d)
	{
		delete [] d;
		d=nullptr;
	}
}

main()
{
	SStudent* dane=nullptr;
	unsigned int n=0;
	
	ifstream wejscie("zadanie1.txt");
	
	if(wejscie.good() && wczytaj(wejscie, dane, n))
	{
		ofstream wyjscie("plik.txt");
		if(wyjscie.good())
		{
			wyswietl(*dane);
			cout << endl;
			wyswietl(dane,n);
			edycja(dane,n);
			zapisz(wyjscie,dane,n);
			wyjscie.close();
		}
		wejscie.close();
		usun(dane);
	
	}
		
	
	return 0;
}
