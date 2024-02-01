#include <iostream>
#include <new>

using namespace std;

class Paczka
{
	string _adres;
	float _wartosc;
	
	public:
	
	Paczka()
	{
		_wartosc=0;	
	}	
	
	Paczka(string adres, float wartosc)
	{
		_adres=adres;
		_wartosc=wartosc;
	}
	
	string& adres()
	{
		return _adres;
	}
	
	float& wartosc()
	{
		return _wartosc;
	}
	
	string adres() const
	{
		return _adres;
	}
	
	float wartosc() const 
	{
		return _wartosc;
	}
	
	
};

ostream& operator<<(ostream& out, Paczka p)
{
	out << p.adres() << " " << p.wartosc() << " ";
	return out;
}

class Osoba
{
	string _imie, _nazwisko;
	
	public:
	
	Osoba(){}
	Osoba(string imie, string nazwisko)
	{
		_imie=imie;
		_nazwisko=nazwisko;	
	}	
	
	string& imie()
	{
		return _imie;
	}
	
	string& nazwisko()
	{
		return _nazwisko;
	}
	
	const string imie() const
	{
		return _imie;
	}
	
	const string nazwisko() const
	{
		return _nazwisko;
	}
	
	friend ostream& operator<<(ostream& out, Osoba os);
	friend bool operator==(const Osoba& o1,const Osoba& o2);
};

ostream& operator<<(ostream& out, Osoba os)
{
	out << os.imie() << " " << os.nazwisko() << " ";
	return out;
}

bool operator==(const Osoba& o1,const Osoba& o2)
{
	if(o1.imie()==o2.imie() && o1.nazwisko()==o2.nazwisko())
		return true;
	else
		return false;
}

class Kurier:public Osoba 
{
	Paczka* p;
	int _rozmiar;
	
	public:
		
	Kurier()
	{
		p=nullptr;
		_rozmiar=0;
	}
	
	Kurier(const Kurier& Obiekt)
	{
		_rozmiar=Obiekt._rozmiar;
		
		p=new Paczka[_rozmiar];
		
		for(int i=0; i<_rozmiar; i++)
			p[i]=Obiekt.p[i];
	}
	
	Kurier(const Paczka* t, const Paczka* tEnd)
	{
		_rozmiar=tEnd-t;
		p=new Paczka[_rozmiar];

		if(p==0)
        	throw "error";
        	
		for(int i=0; i<_rozmiar; i++)
		{
			p[i]=t[i];
		}
	}
	
	Kurier& operator=(const Kurier& Obiekt)
	{
		if( this == &Obiekt )
        	return *this;
        
        if(_rozmiar!=Obiekt._rozmiar)
        {
        	delete[] p;
        	
        	_rozmiar=Obiekt._rozmiar;
        	p=new Paczka[_rozmiar];
		}
		
		for(int i=0; i<_rozmiar; i++)
		{
			p[i]=Obiekt.p[i];
		}
		
		return *this;
	}
	
	Kurier operator+(Paczka& Obiekt)
	{
		Kurier zmienna;
		
		zmienna._rozmiar=_rozmiar+1;
		zmienna.p=new Paczka[zmienna._rozmiar];
		
		for(int i=0; i<_rozmiar-1; i++)
		{
			zmienna.p[i]=p[i];
		}
		
		zmienna.p[zmienna._rozmiar-1]=Obiekt;
		return zmienna;
	}
	
	Paczka operator[](int index)
	{
		if(index>=_rozmiar)
			throw "error";
		return p[index];
	}
	
	float wartosc()
	{
		if(_rozmiar==0)
			return 0;
		float suma=0;
		for(int i=0; i<_rozmiar; i++)
		{
			suma+=p[i].wartosc();
		}
		
		return suma;
	}
	
  	~Kurier()
  	{
    	if(p)
      		delete[] p;
  	}
  
};

bool operator==(Osoba &o1, Osoba &o2)
{
  if (o1.imie()==o2.imie() && o1.nazwisko()==o2.nazwisko())
  {
    return true;
  }
  return false;
}

ostream &operator<<(ostream &out, Paczka &os)
{
  out << os.adres() << " " << os.wartosc() << endl;
  return out;
}

int main()
{
  Paczka p[] = {
    Paczka("Dabrowskiego 33", 123.00), 
    Paczka("NMP 12", 40.00),
    Paczka("Armii Krakowej 4", 30.00), 
    Paczka("Andersa 6", 51.00),
    Paczka("Kukuczki 13", 12.00), 
    Paczka("Skrzyneckiego 5", 40.00), 
  };

  Osoba o1("Jan", "Kowalski");
  cout << "---- 1 ----" << endl;
  cout << o1 << endl;
  
  {
      Osoba o2(o1);
      cout << "---- 2 ----" << endl;
      cout << o2 << endl;
      
      cout << "---- 3 ----" << endl;
      cout << boolalpha << (o1 == o2) << endl;
      
      Osoba o3;
      cout << "---- 4 ----" << endl;
      cout << o3 << endl;

      o3 = o2;
      cout << "---- 5 ----" << endl;
      cout << o3 << endl;
      
  }   

  cout << "---- 6 ----" << endl;
  cout << o1 << endl;
      
  Kurier k1(p, p+3);
  cout << "---- 7 ----" << endl;
  cout << k1.wartosc() << endl;

  Kurier k2;
  cout << "---- 8 ----" << endl;
  cout << k2.wartosc() << endl;

  {
    Kurier k3(k1);
    cout << "---- 9 ----" << endl;
    cout << k3.wartosc() << endl;

    k2 = k3;
    cout << "---- 10 ----" << endl;
    cout << k2.wartosc() << endl;

    k1 = k1 + p[4]; 
    k1 = k1 + p[5];

    cout << "---- 11 ----" << endl;
    cout << k1.wartosc() << endl;

  }

  cout << "---- 12 ----" << endl;
  cout << k2.wartosc() << endl;

  try{
    Kurier k4(p, p+3);
    cout << "---- 13 ----" << endl;
    for(int i=0; i<10; ++i){
      cout << k4[i] << ",";
    }
    cout << endl;
  }
  catch(...){
    cout << "---- 14 ----" << endl;
    cout << "Wyjatek" << endl;
  }

  return 0;
}
