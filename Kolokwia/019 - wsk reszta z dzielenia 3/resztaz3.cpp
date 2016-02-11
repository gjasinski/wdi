#include <iostream>
using namespace std;
struct node{
    int n;
    node *next;
};
void wypisz(node *f)
{
    while(f!=NULL)
    {
        cout<<f->n<<" ";
        f=f->next;
    }
    cout<<endl;
}
node *add(node *f, int w)
{
    node *tmp;
    tmp=new node;
    tmp->n=w;
    tmp->next=f;
    return tmp;
}
void rozdziel(node *&f1, node *&f2);
int main()
{
    node *f1,*f2;
    f1=f2=NULL;
    f1=add(f1,5);
    f1=add(f1,1);
    f1=add(f1,52);
    f1=add(f1,30);
    f1=add(f1,533);
    wypisz(f1);
    rozdziel(f1,f2);
    wypisz(f1);
    wypisz(f2);
}

void rozdziel(node *&f1, node *&f2)
{
    node *f,*tmp, *l1, *l2;
    int m;
    f=f1;
    f1=f2=l1=l2=NULL;
    while(f!=NULL)
    {
        tmp=f;
        f=f->next;
        m=tmp->n%3;
        if(m==0) delete tmp;
        else
        {
            tmp->next=NULL;
            if(m==1)
            {
                if(f1==NULL) f1=l1=tmp;
                else
                {
                    l1->next=tmp;
                    l1=tmp;
                }
            }
            else
            {
                if(f2==NULL)f2=l2=tmp;
                else
                {
                    l2->next=tmp;
                    l2=tmp;
                }
            }

        }
    }

}
