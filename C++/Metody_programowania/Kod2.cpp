#include <iostream>
#include <math.h>

using namespace std;

class punkt
{
	float _x, _y;
	
	public:
	
	punkt()
	{
		_x=0;
		_y=0;
	}	
	
	punkt(float x, float y)
	{
		_x=x;
		_y=y;
	}
	
	float& x()
	{
		return _x; 
	}
	
	float& y()
	{
		return _y;
	}
	
	float x() const
	{
		return _x; 
	}
	
	float y() const
	{
		return _y;
	}
	
	float odleglosc(const punkt& p)
	{
		return sqrt(pow((_x-p.x()),2)+pow((_y-p.y()),2));
	}
};

class wielobok
{
	punkt* p;
	int _rozmiar;
	
	public:
		
	wielobok()
	{
		p=nullptr;
		_rozmiar=0;
	}
	
	wielobok(punkt* t, punkt* tEnd)
	{
		_rozmiar=tEnd-t;
		
		p=new punkt[_rozmiar];
		
		for(int i=0; i<_rozmiar; i++)
		{
			p[i]=punkt(t[i]);
		}
	}
	
	int& ilosc()
	{
		return _rozmiar;
	}
	
	int ilosc() const 
	{
		return _rozmiar;
	}
	
	~wielobok()
	{
		if(p)
		{
			delete[] p;	
		}	
	}
	
	punkt& Punkt(int ind)
	{
		return p[ind];
	}	
	
	void Punkty(const punkt* t, const punkt* tEnd)
	{
		_rozmiar=tEnd-t;
		
		p=new punkt[_rozmiar];
		
		for(int i=0; i<_rozmiar; i++)
		{
			p[i]=punkt(t[i]);
		}
	}
	
	float obwod()
	{
		float suma=0;
		
		for(int i=0; i<_rozmiar-1; i++)
		{
			suma+=p[i].odleglosc(p[i+1]);
		}
		
		suma+=p[0].odleglosc(p[_rozmiar-1]);
		
		return suma;
	}
};

int main()
{
    punkt p(2, 3); 
    cout << p.x() << ' ' << p.y() << '\n'; 
    
    p.x() = 1; 
    p.y() = 1; 
    cout << p.x() << ' ' << p.y() << '\n'; 
    cout << p.odleglosc(punkt()) << '\n'; 
    
    punkt t[] = { punkt(0, 1), punkt(0, 0), punkt(1, 0), punkt(1, 1) }; 
    wielobok w1(t, t+4); 
    cout << w1.obwod() << '\n'; 
    
    w1.Punkt(1) = punkt(0.5, 0.5); 
    cout << w1.obwod() << '\n'; 
    
    wielobok w2; 
    w2.Punkty(t, t+3); 
    cout << w2.obwod() << '\n'; 
    for (int i = 0; i < w2.ilosc(); ++i) 
        cout << w2.Punkt(i).x() << ' ' << w2.Punkt(i).y() << '\n'; 

     return 0;
}
