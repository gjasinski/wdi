/*
Wyrazy budowane s� z liter a..z. Dwa wyrazy �wa��� tyle samo je�eli: maj� t� sam� liczb� 
samog�osek oraz sumy kod�w ascii liter z kt�rych s� zbudowane s� identyczne, na przyk�ad �ula� -> 
117 108 97 oraz �exe� 101 120 101. Prosz� napisa� funkcj� bool wyraz( string s1, string s2), kt�ra 
sprawdza czy jest mo�liwe zbudowanie wyrazu z podzbioru liter zawartych w s2 wa��cego tyle co 
wyraz s1. Dodatkowo funkcja powinna wypisa� znaleziony wyraz.
*/

#include<iostream>

using namespace std;

bool wyraz(string s1, string s2);
bool wyrazRekurencja(string wyraz, string wynik, int waga, int samogloski, int n);

int main()
{
    if(wyraz("kote", "ayrg"))cout<<"TAK";
    else cout<<"nie";
}

//Funkcja sprawdzaj�ca czy litera jest samog�osk�
bool samogloska(char l)
{
    return l=='a' or l=='e' or l=='o' or l=='u' or l=='y';
}

//funkcja zwracaj�ca czy da si� utworzy� taki ci�� znak�w jak by�o to potrzebne w poleceniu
bool wyraz(string s1, string s2)
{
    int samogloski1, samogloski2, waga1, waga2;
    samogloski1=0;
    for(int i=0;i<s1.length();i++)
        if(samogloska(s1[i])) samogloski1++;
    samogloski2=0;
    for(int i=0;i<s2.length();i++)
        if(samogloska(s2[i])) samogloski2++;
    if(samogloski1>samogloski2) return false;//sprawdzan czy jest wgl mo�liwe utoworzenie takiego ci�gu znak�w(ilo�� samog�osek w s2 nusi by� conajmniej tak du�a jak w s1)
    waga1=0;
    for(int i=0;i<s1.length();i++)
        waga1+=(int)s1[i];
    waga2=0;
    for(int i=0;i<s2.length();i++)
        waga2+=(int)s2[i];
    if (waga1>waga2) return false;//sprawdzan czy jest wgl mo�liwe utoworzenie takiego ci�gu znak�w(waga s2 musi by� conajmniej taka jak s1)
    return wyrazRekurencja(s2,"",waga1,samogloski1,s2.length());
}

bool wyrazRekurencja(string wyraz, string wynik, int waga, int samogloski, int n)//wyrazRekurencja("test","a",10,2,4);
{
    bool koniec=false;
        if(waga==0 and samogloski==0)//warunek sprawdzaj�cy czy znale�li�my ten wyraz kt�rego szumay
        {
            cout<<wynik<<endl;
            return true;
        }
        else
        {
             if(n>0)//warunek ko�ca rekurencji
             {
                char znak;
                for(int i=0;i<wyraz.length() and !koniec;i++)//przchodzimy po ka�dym znaku wyrazu i wywolujemy rekurencje
                {
                    if((int)wyraz[i]>90)//gdy zabieramy jaki� znak zamieniamy go na cyfr� 0, dlatego sprawdzamy czy znak to litera
                    {
                        znak=wyraz[i];
                        wyraz[i]=(char)48;
                        if(samogloska(znak)) koniec=wyrazRekurencja(wyraz,wynik+znak,waga-(int)znak,samogloski-1,n-1);//sprawdzenie czy znak jest samog�osk�
                        else    koniec=wyrazRekurencja(wyraz,wynik+znak,waga-(int)znak,samogloski,n-1);
                        wyraz[i]=znak;
                    }
                }
            }
        }
    return koniec;
}
