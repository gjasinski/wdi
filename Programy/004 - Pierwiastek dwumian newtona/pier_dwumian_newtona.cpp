#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double eps = 0.000001;
	double s = 0;
	double a = 0;
	double b = 1;
	cin >> s;
	
	while (abs(a-b)>eps)
	{
		a=b;
		b = ((s/b)+b)/2;
	}
	cout << (a+b)/2;
	return 0;	
}
