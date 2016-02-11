#include <iostream>
#include <cmath>

using namespace std;

int silnia(int l);
bool palindrom(int l);
void kombinacja(int l);

int main()
{
	//cout <<palindrom(23456789)<<endl;
	//cout <<palindrom(12344321)<<endl;
	kombinacja(2315);
	return 0;
}

int silnia(int l)
{
	int s;
	s=1;
	for (int i=1;i<l;i=i+1)
	{
		s=s*i;
		while(s%10==0) s=s/10;
		s=s%100;
	}
	return s%10;
}


bool palindrom(int l)
{
	int b=l;
	int p=0;
	while (b>0)
	{
		p=p*10+b%10;
		b=b/10;
	}
	if(l==p) return true; else return false;
}

void kombinacja(int l)
{
	int x=1;
	while (l>0)
	{
		x=x*10+l%10;
		l=l/10;
	}
	l=log10(x);
	int n=0;
	int y=0;
	int w=0;
	l=pow(2,l);

	for (int i=0;i<l;i=i+1)
	{
		n=i;
		y=x;
		w=0;
		while(n>0)
		{
			if(n%2==1) 	w=w*10+y%10;
			y=y/10;
			n=n/2;
		}
		if(w>0)cout << w<<endl;	
	}
}
