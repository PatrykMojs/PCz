#include <iostream>

using namespace std;

class osoba
{
	protected:
	
	string _nazwisko;
	int _liczba_lat;
	
	public:
		
	osoba()
	{
		_liczba_lat=0;
	}
	
	osoba(string nazwisko, int wiek)
	{
		_nazwisko=nazwisko;
		_liczba_lat=wiek;
	}
	
	string& nazwisko()
	{
		return _nazwisko;
	}
	
	int& liczba_lat()
	{
		return _liczba_lat;
	}
	
	string nazwisko() const
	{
		return _nazwisko;
	}
	
	int liczba_lat() const
	{
		return _liczba_lat;
	}
	
	void pokaz()
	{
		cout << _nazwisko << " " << _liczba_lat << endl; 
	}
};

class pracownik: public osoba
{
	string _stanowisko;
	float _placa;
	
	public:
	
	pracownik():osoba()
	{
		_placa=0;
	}
		
	pracownik(string nazwisko, int wiek, string stanowisko, float placa):osoba(nazwisko, wiek)
	{
		_stanowisko=stanowisko;
		_placa=placa;
	}
	
	pracownik(const pracownik& p2)
	{
		_stanowisko=p2.stanowisko();
		_placa=p2.placa();
		_nazwisko=p2.nazwisko();
		_liczba_lat=p2.liczba_lat();
	}
	
	string& stanowisko()
	{
		return _stanowisko;
	}
	
	float& placa()
	{
		return _placa;
	}
	
	string stanowisko() const
	{
		return _stanowisko;
	}
	
	float placa() const 
	{
		return _placa;
	}
	
	void pokaz()
	{
		osoba::pokaz();
		cout << _stanowisko << " " << _placa << endl;
	}
	
};

int main()
{
	osoba os("Dolas", 26);
	os.pokaz();
	const pracownik pr1("Dyzma", 35, "mistrz", 1250.0);
	cout << pr1.nazwisko() << pr1.liczba_lat();
	cout << pr1.stanowisko() << pr1.placa();
	pracownik pr2(pr1);
	pr2.pokaz();
	pracownik pr3("Kos", 45, "kierownik", 2260.0);
	pr3.pokaz();
	pr3 = pr2;
	pr3.pokaz();
	osoba* w = &os;
	w->pokaz();
	w = &pr3;
	w->pokaz();
	static_cast<pracownik*>(w)->pokaz();
	
	return 0;
}
