#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	int n = 0;
	int s = 0;
	int k = 0;
	cin >> x;
	k = 1;
	s = 0;
	n = 0;
	while (s <= x)
	{
		s=s+k;
		n=n+1;
		k=k+2;
	}
	cout << n-1;
	return 0;
}
