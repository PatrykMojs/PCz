#include <iostream>

using namespace std;

class adres
{
	string _miasto, _kod_pocztowy, _ulica;
	unsigned _numer_ulicy;
	
	public:
	
	adres()
	{
		_numer_ulicy=0;	
	}	
	
	adres(string miasto, string kod_pocztowy, string ulica, unsigned numer_ulicy)
	{
		_miasto=miasto;
		_kod_pocztowy=kod_pocztowy;
		_ulica=ulica;
		_numer_ulicy=numer_ulicy;
	}
	
	string& miasto()
	{
		return _miasto;
	}
	
	string& kodpocztowy()
	{
		return _kod_pocztowy;
	}
	
	string& ulica()
	{
		return _ulica;
	}
	
	unsigned& numerulicy()
	{
		return _numer_ulicy;
	}
	
	string miasto() const
	{
		return _miasto;
	}
	
	string kodpocztowy() const
	{
		return _kod_pocztowy;
	}
	
	string ulica() const
	{
		return _ulica;
	}
	
	unsigned numerulicy() const
	{
		return _numer_ulicy;
	}
	
	friend ostream& operator<<(ostream& out,const adres& a);
	
};

ostream& operator<<(ostream& out,const adres& a)
	{
		out << a.miasto() << " " << a.kodpocztowy() << " " << a.ulica() << " " << a.numerulicy() << endl;
		return out;
	}

class osoba
{
	string _imie, _nazwisko;
	unsigned _wiek;
	adres* adr;
	
	
	public:
		
	osoba()
	{
		_wiek=0;
		adr=nullptr;
	}
	
	osoba(string imie, string nazwisko, unsigned wiek, const adres& a)
	{
		_imie=imie;
		_nazwisko=nazwisko;
		_wiek=wiek;
		adr=new adres;
		*adr=a;	
	}
	
	osoba(const osoba& o)
	{
		_imie=o._imie;
		_nazwisko=o._nazwisko;
		_wiek=o._wiek;
		adr=new adres;
		*adr=*o.adr;
	}
	
	osoba& operator=(const osoba &o) 
	{
			if(&o != this ) 
			{
				_imie = o._imie;
				_nazwisko = o._nazwisko;
				_wiek = o._wiek;
				
				if(adr!=0) 
					delete adr;
				adr = new adres;
				*adr = *o.adr;
			}
			return *this;
	}
	
	string& imie()
	{
		return _imie;
	}
	
	string& nazwisko()
	{
		return _nazwisko;
	}
	
	unsigned& wiek()
	{
		return _wiek;
	}
	
	friend ostream& operator<<(ostream& out,const osoba o);	
	
	~osoba()
	{
		delete[] adr;	
	}
};

ostream& operator<<(ostream& out,const osoba o)
{
	if(o.adr!=0)
	{
		return out << o._imie << " " << o._nazwisko << " " << o._wiek << *o.adr << endl; 
	}else
		return out << o._imie << " " << o._nazwisko << " " << o._wiek << 0 << endl;
		
}

int main()
{
	adres* wsk = new adres("Czestochowa", "42-200", "Dabrowskiego", 73);
	cout << *wsk << '\n';
	adres a1(*wsk);
	delete wsk;

	const adres* wsk1 = new adres("Warszawa", "00-950", "Mysliwiecka", 357);
	cout << a1 << '\n';
	cout << *wsk1 << '\n';

	adres a2;
	cout << a2 << '\n';
	a2 = a1;
	cout << a2 << '\n';

	osoba o("Jan", "Kos", 25, *wsk1);
	cout << o << '\n';
	osoba o1(o);
	cout << o1 << '\n';

	osoba o2;
	cout << o2 << '\n';
	o2 = o1;
	cout << o2 << '\n';
	delete wsk1;
	
	return 0;
}
