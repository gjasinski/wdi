#include<iostream>

using namespace std;
void cw1g(int N);
void wypiszOdKonca(int liczba)
{
    if(liczba>0)
    {
        cout<<liczba%10;
        wypiszOdKonca(liczba/10);

    }
}
string hexNumber(int liczba)
{
    if(liczba==0) return "0";
    if(liczba==1) return "1";
    if(liczba==2) return "2";
    if(liczba==3) return "3";
    if(liczba==4) return "4";
    if(liczba==5) return "5";
    if(liczba==6) return "6";
    if(liczba==7) return "7";
    if(liczba==8) return "8";
    if(liczba==9) return "9";
    if(liczba==10) return "A";
    if(liczba==11) return "B";
    if(liczba==12) return "C";
    if(liczba==13) return "D";
    if(liczba==14) return "E";
    if(liczba==15) return "F";
}
void decToHex(int liczba)
{
    if(liczba>0)
    {
        decToHex(liczba/16);
        cout<<hexNumber(liczba%16);
    }

}
int main()
{
    //cw1g(5);
    //wypiszOdKonca(3456789);
    decToHex(125986);
}



void cw1(int liczba, int n, int N)
{
    cout<<liczba<<endl;
    if(n<=N)
    {
        if(n%2==0)  cw1(liczba+2,n+1,N);
        else        cw1(liczba*2,n+1,N);
    }

}
void cw1g(int N)
{
    if(N>0)
    {
        cw1(2,2,N);
    }
}
