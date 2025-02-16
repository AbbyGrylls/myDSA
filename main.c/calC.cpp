#include<iostream>
using namespace std;
int main()
{
    float x,y,i;
    cout<<"welcome to the arthmatic calculator"<<endl;
    cin.get();
    cout<<"choose the kind of arthematic operation"<<endl;
    cout<<"1 = ADDITION,2 = SUBRACTION,3 = MULTIPLICATION,4 = DIVISION"<<endl;
    cin>>i;
    cout<<"enter the value of x and y"<<endl;
    cin>>x>>y;
    if(i==1)
    {
        cout<<"the addition result is:"<<x+y;
    }
    else if(i==2)
    {
        cout<<"the subraction result is:"<<x-y;
    }
    else if(i==3)
    {
        cout<<"the multiplication result is:"<<x*y;
    }
    else if(i==4)
    {
        cout<<"the division result is:"<<x/y;
    }
    else
    {
        cout<<"invalid operation selected";
    }
    return 1;
}