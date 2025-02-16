#include<iostream>
using namespace std;
int main()
{
    char a[100];
    int i=0,w=0,v=0,x=0,y=0,z=0;
    cout<<"enter the word:";
    cin>>a;
    while(a[i]!=0)
    {
        if(a[i]=='a' || a[i]=='A')
        {
            w++;
        }
        if(a[i]=='e'|| a[i]=='E')
        {
            v++;
        }
        if(a[i]=='i' || a[i]=='I')
        {
            x++;
        }
        if(a[i]=='o' || a[i]=='O')
        {
            y++;
        }
        if(a[i]=='u' || a[i]=='U')
        {
            z++;
        }
        ++i;
    }
    cout<<"repeated times of A E I O U are: "<<w<<"\t"<<v<<"\t"<<x<<"\t"<<y<<"\t"<<z<<"\t";
    return 0;
}