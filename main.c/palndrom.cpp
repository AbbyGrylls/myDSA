#include<iostream>
using namespace std;
int main ()
{
    char a[100];
    int i=0,k=0,p=0;
    cout<<"enter ur word:";
    cin>>a;
   while(a[i]!=0)
    {
        ++k;
        ++i;
    }
    for(i=0;i<k;++i)
    /*
    {
        if(a[i]==a[k-i-1])
        {
            cout<<"its a palindrome";
            break;
        }    
        else
        {
            cout<<"its not a palindrome";
            break;
        }
    }*/
    while(a[i]!=0)
    {
        if(a[i]!=a[k-i-1])
        {
            p++;
            break;
        }
        ++i;
    }
        if(p!=0)
        {
            cout<<"its not a palindrome";
        }
        else
        {
            cout<<"its a palindrome";
        }
    return 0;
}