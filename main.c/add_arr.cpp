#include<iostream>
using namespace std;
int main()
{
    int a[20],b[20];
    int x,y;
    cout<<"enter the size of array:"<<endl;
    cin>>x;
    cout<<"enter the array:";
    for(int i=0;i<x;++i)
    {
        cin>>a[i];
    }
    cout<<"enter the number to be added:"<<endl;
    cin>>y;
    for(int i=0;i<x;++i)
    {
        b[i]=a[i]+y;
    }
    cout<<"the new array is:";
    for(int i=0;i<x;++i)
    cout<<b[i]<<"\t";
    return 0;
}