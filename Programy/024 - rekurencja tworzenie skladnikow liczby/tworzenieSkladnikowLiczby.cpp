#include <iostream>
#include <sstream>

using namespace std;

void sumy(int liczba, int skladnik, string wynik);

string liczby[10]={"0","1","2","3","4","5","6","7","8","9"};
int main()
{
    sumy(10,1,"");
}

string intToStr(int l)//zamiania int na str
{
    string w="";
    int tmp=0;
    while(l>0)
    {
        tmp*=10;
        tmp+=l%10;
        l/=10;
    }
    while(tmp>0)
    {
            w+=liczby[tmp%10];
            tmp/=10;
    }
    return w;
}

void sumy(int liczba, int skladnik, string wynik)
{
    if(liczba==0)
    {
        cout<<wynik<<endl;
        return;
    }
    if(liczba>0)
    {
        for(int i=skladnik;i<=liczba;i++)
            sumy(liczba-i, i, wynik+" "+intToStr(i));
    }
}




