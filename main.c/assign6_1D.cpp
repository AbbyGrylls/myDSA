#include<iostream>
using namespace std;
int sum(int a[100],int n)
{
    int i=0,r=0;
    while(i<n)
    {
        r=r+a[i];
        ++i;
    }
    return r;
}
int main()
{
    int n,s;
    int a[100];
    cout<<"enter the size of array:";
    cin>>s;
    cout<<"enter the array"<<endl;
    for(int i=0;i<s;++i)
    {
        cin>>a[i];
    }
    cout<<"enter, how many elements to be calculated as sum:";
    cin>>n;
    cout<<"sum of elements upto given n is:"<<sum(a,n);
    return 0;
}