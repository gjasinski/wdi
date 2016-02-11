#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void metoda_1(int liczba);
void metoda_bisekcji_sposob_cwiczenia(int liczba);
void metoda_bisekcji_sposob_cwiczenia2(int liczba);

int main()
{
	int l;
	//cin >> l;
	//metoda_1(l);	
	//metoda_bisekcji_sposob_cwiczenia(2015);
	metoda_bisekcji_sposob_cwiczenia2(2015);
	return 0;
}

void metoda_1(int liczba)
{
	int i = 1;
	while(i*i<=liczba)
	{
		if(liczba%i==0) cout << i << " " << liczba/i<<endl;;
		i=i+1;
	}
	
}


void metoda_bisekcji_sposob_cwiczenia(int liczba)
{
	//<0.01
	double a,b,x,y;
	double eps=1e-6;
	cout<<setprecision(20);
	a=1;
	b=10;
	while(abs(b-a)>eps)
	{
		x=(a+b)/2.0;
		y=exp(x*log(x))-2015;
		if(y>0) b=x; else a=x;
	}
	cout<<x;
}

void metoda_bisekcji_sposob_cwiczenia2(int liczba)
{
	//<0.01
	double a,b,x,y;
	double eps=1e-6;
	cout<<setprecision(20);
	a=1;
	b=10;
	while(abs(b-a)>eps)
	{
		x=(a+b)/2.0;
		
		y=exp(exp(x*log(2))*log(x))-2015;
		if(y>0) b=x; else a=x;
	}
	cout<<x;
}
