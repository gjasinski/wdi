#include <iostream>
#include <string>
using namespace std;
const int N=6;
int t[]={1,2,3,8,13,19};
bool waga1(int w, int p, int suma);
bool waga1b(int w, int p, int suma);
bool waga2(int w, int p);
bool waga2b(int w, int p);
void wagaWypisz(int w, int p, string wynik);
int main()
{
    if(waga2(18,0)) cout<<"OK"; else cout<<"ZLE";
    cout<<endl;
    if(waga2(100,0)) cout<<"OK"; else cout<<"ZLE";
    wagaWypisz(18,0,"");
    }

bool waga1(int w, int p, int suma)//waga1(15,0,0);
{
/*
    Funkcja rekurencyjna
    zwiekszmy sume tak aby doszła do w.
    Ciężarki można dawać tylko na jedną szalkę.
*/
    if(suma==w) return true;
    if(suma>w) return false;
    if(p==N) return false;
    return waga1(w,p+1,suma+t[p]) or waga1(w,p+1,suma);
}

bool waga2(int w, int p)//waga2(15,0);
{
/*
    Funkcja rekurencyjna
    zmniejszamy w tak aby doszło do zera.
    Ciężarki można dawać tylko na jedną szalkę.
*/
    if(w==0) return true;
    if(w<0) return false;
    if(p==N) return false;
    return waga2(w-t[p],p+1) or waga2(w,p+1);
}
bool waga1b(int w, int p, int suma)//waga1b(15,0,0);
{
/*
    Funkcja rekurencyjna
    zwiekszmy sume tak aby doszła do w.
    Ciężarki można dawać na obie szalki.
*/
    if(suma==w) return true;
    if(p==N) return false;
    return waga1b(w,p+1,suma+t[p]) or waga1b(w,p+1,suma) or waga1b(w+t[p],p+1,suma);
}

bool waga2b(int w, int p)//waga2b(15,0);
{
/*
    Funkcja rekurencyjna
    zmniejszamy w tak aby doszło do zera.
    Ciężarki można dawać na obie szalki.
*/
    if(w==0) return true;
    if(p==N) return false;
    return waga2b(w-t[p],p+1) or waga2b(w,p+1)or waga2b(w+t[p],p+1);
}
void wagaWypisz(int w, int p, string wynik)//wagawypisz(15,0,"");
{
/*
    Funkcja wypisuje jakie ciezarki uzylismy do zwżenia
*/
    if(w==0)cout<<wynik;
    else
    {
        if(p<N)
        {
           // wagaWypisz(w-t[p],p+1,wynik+ " " + to_string(t[p]);
            wagaWypisz(w-t[p],p+1,wynik);
        }
    }

}


