/*
Wyrazy budowane s¹ z liter a..z. Dwa wyrazy „wa¿¹” tyle samo je¿eli: maj¹ tê sam¹ liczbê 
samog³osek oraz sumy kodów ascii liter z których s¹ zbudowane s¹ identyczne, na przyk³ad „ula” -> 
117 108 97 oraz „exe” 101 120 101. Proszê napisaæ funkcjê bool wyraz( string s1, string s2), która 
sprawdza czy jest mo¿liwe zbudowanie wyrazu z podzbioru liter zawartych w s2 wa¿¹cego tyle co 
wyraz s1. Dodatkowo funkcja powinna wypisaæ znaleziony wyraz.
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

//Funkcja sprawdzaj¹ca czy litera jest samog³osk¹
bool samogloska(char l)
{
    return l=='a' or l=='e' or l=='o' or l=='u' or l=='y';
}

//funkcja zwracaj¹ca czy da siê utworzyæ taki ci¹¿ znaków jak by³o to potrzebne w poleceniu
bool wyraz(string s1, string s2)
{
    int samogloski1, samogloski2, waga1, waga2;
    samogloski1=0;
    for(int i=0;i<s1.length();i++)
        if(samogloska(s1[i])) samogloski1++;
    samogloski2=0;
    for(int i=0;i<s2.length();i++)
        if(samogloska(s2[i])) samogloski2++;
    if(samogloski1>samogloski2) return false;//sprawdzan czy jest wgl mo¿liwe utoworzenie takiego ci¹gu znaków(iloœæ samog³osek w s2 nusi byæ conajmniej tak du¿a jak w s1)
    waga1=0;
    for(int i=0;i<s1.length();i++)
        waga1+=(int)s1[i];
    waga2=0;
    for(int i=0;i<s2.length();i++)
        waga2+=(int)s2[i];
    if (waga1>waga2) return false;//sprawdzan czy jest wgl mo¿liwe utoworzenie takiego ci¹gu znaków(waga s2 musi byæ conajmniej taka jak s1)
    return wyrazRekurencja(s2,"",waga1,samogloski1,s2.length());
}

bool wyrazRekurencja(string wyraz, string wynik, int waga, int samogloski, int n)//wyrazRekurencja("test","a",10,2,4);
{
    bool koniec=false;
        if(waga==0 and samogloski==0)//warunek sprawdzaj¹cy czy znaleŸliœmy ten wyraz którego szumay
        {
            cout<<wynik<<endl;
            return true;
        }
        else
        {
             if(n>0)//warunek koñca rekurencji
             {
                char znak;
                for(int i=0;i<wyraz.length() and !koniec;i++)//przchodzimy po ka¿dym znaku wyrazu i wywolujemy rekurencje
                {
                    if((int)wyraz[i]>90)//gdy zabieramy jakiœ znak zamieniamy go na cyfrê 0, dlatego sprawdzamy czy znak to litera
                    {
                        znak=wyraz[i];
                        wyraz[i]=(char)48;
                        if(samogloska(znak)) koniec=wyrazRekurencja(wyraz,wynik+znak,waga-(int)znak,samogloski-1,n-1);//sprawdzenie czy znak jest samog³osk¹
                        else    koniec=wyrazRekurencja(wyraz,wynik+znak,waga-(int)znak,samogloski,n-1);
                        wyraz[i]=znak;
                    }
                }
            }
        }
    return koniec;
}
