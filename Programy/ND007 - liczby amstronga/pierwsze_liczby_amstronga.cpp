#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
//exp(2*log(10));10^2

void l_pierwsze();

int main()
{
	l_pierwsze();
	return 0;
}

void l_pierwsze()
{
	int max =1000000000;
	int liczba=9;
	int j,i,suma,b;
	bool flaga;
	
	
	//fstream plik( "plik_l_z.txt", ios::out );
	/*for (int i=2;i<max;i=i+1)
	{
		j=2;
		flaga = false;
		while (j*j<max&&flaga==false)
		{
			if(i%j==0) flaga=true; else j=j+1;
		}
		
		
		if (!flaga) plik << i << " ";
		
	}*/
	
	while(liczba <max)
	{
		liczba=liczba+1;
		j=2;
		flaga = false;
		while (j*j<=liczba&&flaga==false)
		{
			if(liczba%j==0) flaga=true; else j=j+1;
		}
		if(flaga==false)
		{
			i=1;
			suma=0;
			while(exp(i*log(10))<liczba) i=i+1;	
			b=liczba;
			while(b>0)
			{
				suma=suma+(b%10)^i;
				//suma=suma+exp(i*log(b%10));
				b=b/10;   
			}
			if(suma==liczba) cout <<liczba<<" ";
		}
	}
	cin >>j;
	//plik.close();
}
