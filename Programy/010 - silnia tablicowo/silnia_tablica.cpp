#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
	fstream plik( "silnia.txt", ios::out );
	//static int size = 1000000;
	//int silnia = 110000;
	static int size = 1000000;
	int silnia = 200000;
	short tab[size];
	tab[size-1]=1;
	for (int i=0;i<size-1;i=i+1)
	{
		tab[i]=0;
	}
	
	int b,bufor;
	b=bufor=0;
	int j;
	
	int k=size-2;
	int s=1;
	for (int i=size-1;i>=size-silnia;i=i-1)
	{
		bufor=0;
		j=size-1;
		while (j>k)
		{
			b=tab[j]*s+bufor;
			tab[j]=b%10;
			bufor=b/10;
			j=j-1;
		}
		while(bufor>0)
		{
			tab[j]=bufor%10;
			bufor=bufor/10;
			j=j-1;
		}
		k=j-1;
		s=s+1;
	}
	while(bufor>0)
	{
		tab[j]=bufor%10;
		bufor=bufor/10;
		j=j-1;
	}
	j=0;
	while(tab[j]==0) j=j+1;
	cout<<"ilosc liczb:"<<size-j<<endl;
	plik <<"ilosc liczb:"<<size-j<<endl;
	/*cin>>s;
	for (j;j<size;j=j+1)
	{
		cout<<tab[j];
		plik << tab[j];
	}*/
	return 0;
}
