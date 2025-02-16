#include<iostream>
using namespace std;
int main()
{
    int x,y;
    int a[20];
    cout<<"enter the size of array:";
    cin>>x;
    cout<<"enter the array:";
    for(int i=0;i<x;++i)
    {
        cin>>a[i];
    }
    cout<<"enter the position to be deleted:";
    cin>>y;
    for(int i=y-1;i<x;++i)
    {
        a[i]=a[i+1];
    }
    cout<<"the new array is:";
    for(int i=0;i<x-1;++i)
    cout<<a[i]<<"\t";
    return 0;
}