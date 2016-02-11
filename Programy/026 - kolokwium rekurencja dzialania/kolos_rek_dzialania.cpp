#include <iostream>

using namespace std;

int A(int liczba)
{
        int tmp1,tmp2;
        tmp1=liczba%10;
        liczba/=10;
        tmp2=liczba%10;
        liczba=liczba*100+tmp1*10+tmp2;
        return liczba;
}
int B(int liczba)
{
    return 3*liczba;
}

int C(int liczba)
{
    int tmp1,tmp2;
    tmp1=tmp2=0;
    while(liczba>0)
    {
        tmp1*=10;
        tmp1+=tmp2;
        tmp2=liczba%10;
        liczba/=10;
    }
    while(tmp1>0)
    {
        liczba*=10;
        liczba+=tmp1%10;
        tmp1/=10;
    }
    return liczba;
}
string szukajOperacji(int x, int y);
int main()
{
    cout<<szukajOperacji(6,1);

}

string operacje(int x, int y, int n, string wynik)
{
    string w="";
    if(x==y) return wynik;
    if(n==0) return "";
    if(x>9) w=operacje(A(x),y,n-1,wynik+"A");
    if(w=="") w=operacje(B(x),y,n-1,wynik+"B");
    if(x>9 and w=="") w=operacje(C(x),y,n-1,wynik+"C");
    return w;
}

string szukajOperacji(int x, int y)
{
    if(x!=y) return operacje(x, y, 7, "");
    return "";
}
