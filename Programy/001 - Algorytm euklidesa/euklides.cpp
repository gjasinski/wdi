#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int eukludes(int a, int b);
int euklidesmodulo(int a, int b);

int main()
{
	int liczba1, liczba2;
	cin >> liczba1 >> liczba2;
	cout << eukludes(liczba1, liczba2)<<endl<<euklidesmodulo(liczba1,liczba2);
	cin >> liczba1;
	return 0;
}

int eukludes(int a, int b)
{
	while (a!=b)
	{
		if(a>b)
		{
			a=a-b;	
		}
		else
		{
			b=b-a;
		}
	}
	return a;
}


int euklidesmodulo(int a, int b)
{
	int c=0;
	if (a<b)
	{
		c=a;
		a=b;
		b=c;
		c=0;
	}
	while (b!=0)
	{
		c=a%b;
		a=b;
		b=c;
		
	}
	return a;
}
