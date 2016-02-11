#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	const int N=30;
	int tab[N];
	int liczba;
	int licz=0;
	cin>>liczba;
	srand( time( NULL ) );
	for (int i=0;i<N;i++) tab[i]=rand()%20+1;
	for(int i=0;i<N;i++)
	{
		if(liczba%tab[i]==0)
		{
			
			for(int j=i+1;j<N;j++)
			{
				if(tab[i]*tab[j]==liczba) licz++;
			}
		}
	}
	cout <<licz;
	return 0;
}
