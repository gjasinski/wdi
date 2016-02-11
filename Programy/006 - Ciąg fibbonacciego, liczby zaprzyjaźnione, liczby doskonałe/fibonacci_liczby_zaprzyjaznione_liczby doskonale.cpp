#include <iostream>
#include <fstream>

using namespace std;

void fibbonacci();
void liczby_doskonale();
void liczby_zaprzyjaznione();
int suma_podzielnikow(int l);

int main()
{
	//fibbonacci();
	//liczby_doskonale();
	liczby_zaprzyjaznione();
	return 0;
}

void fibbonacci()
{
	int max = 1000000;
	int a = 0;
	int b = 1;
	int c = 0;
	int i=0;
	while (a<max)
	{
		cout << i << ": " << a<<endl;
		c = a+b;
		b = a;
		a = c;
		i++;
		
	}
}

void liczby_doskonale()
{
	long long int max =33550336;
	long long int liczba = 2;
	long long int j = 1;
	long long int s = 0;
	cout <<"liczby doskonale:"<<endl;
	fstream plik( "plik_l_d.txt", ios::out );
	while (liczba<max)
	{
		s=-liczba;
		j=1;
		while(j*j<liczba)
		{
			if(liczba%j==0) s = s + j + liczba/j;
			j=j+1;
		}
		if(j*j==liczba) s = s +j;
	if (s==liczba) {cout << s << endl; plik << s <<endl;}
	liczba = liczba+1;
	}
	cin>>j;	
	plik.close();
}

void liczby_zaprzyjaznione()
{
	//int max = 1000000000;
	int max = 1000000;
	int a = 0;
	fstream plik( "plik_l_z.txt", ios::out );
	
	for (int liczba = 1;liczba<max;liczba++)
	{
		a=suma_podzielnikow(liczba);
		
		if (suma_podzielnikow(a)==liczba&&a!=liczba&&liczba<a) 
		{
			cout << liczba <<" "<<a<<endl;

           	plik << liczba << " " << a<<endl;

		}
	}
	plik.close();
}

int suma_podzielnikow(int l)
{
	int s=-l;
	int j=1;
	while(j*j<l)
		{
			if(l%j==0) s = s + j + l/j;
			j=j+1;
		}
	if(j*j==l) s = s +j;
	return s;	
}

