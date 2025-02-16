#include<iostream>
using namespace std;
int main()
{   
    int z;
    cout<<"choose your requirement: 1)Multiplication table, 2)Biggest number"<<endl;
    cin>>z;
    if(z==1)
    {
        int a;
        cout<<"enter the multiplication table number"<<endl;
        cin>>a;
        for(int i=0;i<11;++i)
        {
            cout<<a<<"x"<<i<<"="<<a*i<<endl;
        }
    }
    else if(z==2)
    {
        int a;
        float arr[100];
        cout<<"enter number of numbers"<<endl;
        cin>>a;
        for(int i=0;i<a;++i)
        {
            cout<<"enter number"<<i+1<<" : ";
            cin>>arr[i];
        }
        for(int i=1;i<a;++i)
        {
            if(arr[0]<arr[i])
            arr[0]=arr[i];
        }
        cout<<"the biggest number is:"<<arr[0];
        return 0;
    }
}