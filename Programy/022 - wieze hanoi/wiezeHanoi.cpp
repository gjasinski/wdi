#include <iostream>
using namespace std;
void hanoi(int n, char x, char y, char z);
int main()
{
    hanoi(3,'A','B','C');
    return 0;
}

void hanoi(int n, char x, char y, char z)//hanoi (3,'A','B','C') //X->Z(Y)
{
/*
    Rekurencyjna funkcja hanoi która wypisuje jakie ruchy należy wykonać
    aby przenieść klocki.
*/
    if(n>0)
    {
        hanoi(n-1,x,z,y);
        cout<<x<<"->"<<z<<endl;
        hanoi(n-1,y,x,z);
    }
}
