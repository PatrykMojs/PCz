#include <iostream>
#include <math.h>

using namespace std;

class point
{
	double p[3];
	
	public:
		
	point()
	{
		p[0]=0;
		p[1]=0;
		p[2]=0;
	}
	
	point(float x, float y, float z)
	{
		p[0]=x;
		p[1]=y;
		p[3]=z;
	}
	
	point(double pkt[3])
	{
		for(int i=0; i<3; i++)
			p[i]=pkt[i];
	}
	
	double distance(point& p2)
	{
		return sqrt(pow((p[0]-p2[0]),2)+pow((p[1]-p2[1]),2)+pow((p[2]-p2[2]),2));
	}
	
	double distance(point p2) const
	{
		return sqrt(pow((p[0]-p2[0]),2)+pow((p[1]-p2[1]),2)+pow((p[2]-p2[2]),2));
	}
	
	double & operator[](int n) 
	{
		return p[n];
	}

	const double& operator[](int n) const 
	{
		return p[n];
	}
		
};

ostream& operator<<(ostream& out, point p)
{
	for(int i=0; i<3; i++)
	{
		out << p[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, point& p)
{
	in >> p[0] >> p[1] >> p[2];
	return in;
}

point operator+(point& p1, point& p2)
{
	point tmp;
	for(int i=0; i<3; i++)
		tmp[i]=p1[i]+p2[i];
	return tmp;
}

point operator-(point& p1,const point& p2)
{
	point tmp;
	for(int i=0; i<3; i++)
		tmp[i]=p1[i]-p2[i];
	return tmp;
}

point operator*(double zm,point& p)
{
	point tmp;
	for(int i=0; i<3; i++)
		tmp[i]=zm*p[i];
	return tmp;
}

point operator*(point& p,double zm)
{
	point tmp;
	for(int i=0; i<3; i++)
		tmp[i]=zm*p[i];
	return tmp;
}

bool operator<(const point& p1, const point& p2)
{
	if(p1.distance(point())<p2.distance(point()))
		return true;
	
}

bool operator==( point & p1, point  p3)
 {
 	if(p1.distance(point()) == p3.distance(point()))
 		return true;
 	else
 		return false;
 }

int main()
{
	double x[2][3] = {{1.0, 1.0, 1.0},{1.0, 2.0, 3.0}};
	point p1(x[0]), p2(x[1]);
	const point p3(0.4, 0.2, 0.1);

	cout << p1 << ", " << p2 << '\n';
	cout << p3[0] << ' ' << p3[1] << ' ' << p3[2] << '\n';
	cout << p1.distance(point()) << ", "<< p3.distance(p1) << '\n';
	cout << p1 + p2 << ", " << p1 - p3 << '\n';
	cout << 3.14 * p2 << ", " << p2 * 3.14 << '\n';
	cout << (p1 < p3) << ", " << (p1 == point(1.0, 1.0, 1.0)) << '\n';
	cin >> p1;
	cout << p1 << '\n';
	
	return 0;
}
