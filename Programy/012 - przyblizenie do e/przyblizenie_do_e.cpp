#include <iostream>
#include <iomanip>
using namespace std;

void wer_wiertnik();
void wer_wiet();

int main()
{
	wer_wiertnik();
	wer_wiet();
	return 0;
}

void wer_wiertnik()
{
	double a,s;
	a=1.0;
	s=0.0;
	int licznik=1;
	while (a>0)
	{
		s=s+a;
		a=a/licznik;
		licznik++;
	}
	cout <<setprecision(17)<< s<<endl;
}

void wer_wiet()
{
	const int N =100000;
	int a[N];
	int s[N];
	bool koniec = false;
	for (int i=0;i<N;i++) a[i]=s[i]=0;
	a[0]=1;
	int tmp=0;
	int r=0;
	int l=1;
	int n=1;
	while (!koniec)
		{
			for(int i=N-1;i>=0;i--)
			{
				tmp=tmp+s[i]+a[i];
				s[i]=tmp%10;
				tmp=tmp/10;
			}
			r=0;
			tmp=0;
			koniec=true;
			for(int i=0;i<N;i++)
			{
				tmp=r*10+a[i];
				r=tmp%n;
				a[i]=tmp/n;
				if(a[i]>0)koniec=false;
			}
			tmp=0;
            n++;

		}
    cout<<s[0]<<".";
    for(int i=1;i<N;i++) cout<<s[i];
}
