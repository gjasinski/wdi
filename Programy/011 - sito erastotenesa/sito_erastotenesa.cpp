#include <iostream>

using namespace std;

int main()
{
	const int N = 10000;
	bool tab[N+1];
	for (int i=0;i<=N;i++)
	{
		tab[i]=true;
	}
	tab[0]=tab[1]=false;
	for (int i=2;i*i<=N;i++)
	{
		if(tab[i]==true)
		{
			for(int j=i*i;j<=N;j=j+i) tab[j]=false;
		}
	}
	int licz=0;
	for (int i=0;i<=N;i++)
	{
		if(tab[i]==true) licz++;//cout<<i<<" ";
	}
	cout <<licz;
	return 0;
}
