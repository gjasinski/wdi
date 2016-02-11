/*
2. Dane s¹ dwie liczby naturalne z których budujemy trzeci¹ liczbê. W budowanej liczbie musz¹
wyst¹piæ wszystkie cyfry wystêpuj¹ce w liczbach wejœciowych. Wzajemna kolejnoœæ cyfr ka¿dej z liczb
wejœciowych musi byæ zachowana. Na przyk³ad maj¹c liczby 123 i 75 mo¿emy zbudowaæ liczby 12375,
17523, 75123, 17253, itd. Proszê napisaæ funkcjê która wyznaczy ile liczb pierwszych mo¿na
zbudowaæ z dwóch zadanych liczb
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int tworzLiczby(string s1, string s2, string wynik);

int main()
{

    cout<<tworzLiczby("70","639","");
}

bool pierwsza(int l)//sprawdza czy liczba jest pierwsza
{
    if(l==1)return false;
    for(int i=2;i*i<=l;i++)
        if(l%i==0)return false;
    return true;
}
int strToInt(string s)//zamiania str na int
{
    int liczba=0;
    for(int i=0;i<s.length();i++)
    {
        liczba*=10;
        liczba+=(int)s[i]-48;
    }
    return liczba;
}
/*
    Funkcja rekurencyjna generujaca różne permutcje liczb.
    Funkcja zwraca ile jest wygenerowanych liczb które są l. pierwszymy.
*/
int tworzLiczby(string s1, string s2, string wynik)//tworzLiczby("12345","34567","66");
{
    int licz=0;
    int tmp;
    string tmps;
    if(s1.length()>0 or s2.length()>0)
    {
        if(s1.length()>0)
        {
            tmps=s1.substr(1);
            licz+=tworzLiczby(tmps,s2,wynik+s1[0]);
        }

        if(s2.length()>0)
        {
            tmps=s2.substr(1);
            licz+=tworzLiczby(s1,tmps,wynik+s2[0]);
        }
    }
    else
    {
        tmp=strToInt(wynik);
        if(pierwsza(tmp)) return licz+1; else return licz+0;
    }
    return licz;
}
