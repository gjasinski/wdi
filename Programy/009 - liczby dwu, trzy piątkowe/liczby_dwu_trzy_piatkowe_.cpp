#include <iostream>
#include <cmath>
using namespace std;

void sp_1();
void sp_2();

int main()
{
	sp_1();
	sp_2();
	return 0;
}

void sp_1()
{
	int licz,d,t,p,n;
	licz=0;
	d=t=p=1;
	n=130;
	while (d<=n)
	{
		t=1;
		p=1;
		while(t<=n)
		{	
			p=d*t;
			
			while(p<=n)
			{
				p=p*5;
				licz=licz+1;
			}
			t=t*3;
		}
		d=d*2;
	}
	cout<<endl<<licz;
}

void sp_2()
{
	
	int licz,d,t,p,n;
	licz=1;
	d=t=p=1;
	n=130;
	while (d<=n)
	{
		t=1;
		p=1;
		while(t<=n)
		{	
			p=d*t;
			licz=licz+(log(n/d)/log(5));
			if(log(n/d)/log(5)<0.5 and p<n) licz++;
			t=t*3;
		}
		d=d*2;
	}
	cout<<endl<<licz;
}
