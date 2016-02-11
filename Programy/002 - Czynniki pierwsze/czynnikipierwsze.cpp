#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void ver_1(int liczba);
void ver_2(int liczba);
void ver_3(int liczba);


int main()
{
	int l=987654381;
//	cin >> l;
	ver_1(l);
	cout << endl;
	ver_2(l);
	cout << endl;
	ver_3(l);
	cin >>l;
	return 0;
}

void ver_1(int liczba)
{
	int b = 2;
	while (liczba > 1)
	{
		if(liczba % b == 0)
		{
			cout << b << " ";
			liczba = liczba / b;
		}
		else b++;
	}
}

void ver_2(int liczba)
{
	while (liczba % 2 == 0)
	{
		cout << "2 ";
		liczba = liczba / 2;
	}
	int b =3;
	while (liczba > 1)
	{
		if(liczba % b == 0)
		{
			cout << b << " ";
			liczba = liczba / b;
		}
		else b=b+2;
	}
}

void ver_3(int liczba)
{
	int s = sqrt(liczba);
	while (liczba % 2 == 0)
	{
		cout << "2 ";
		liczba = liczba / 2;
	}
	int b =3;
	while (liczba > 1 && b < s)
	{
		if(liczba % b == 0)
		{
			cout << b << " ";
			liczba = liczba / b;
		}
		else b=b+2;
	}
}
