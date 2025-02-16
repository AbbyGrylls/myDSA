#include <iostream>
using namespace std;
int swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    return temp;
}
int main()
{
    int a,b;
    cout<<"enter the vales of A and B: ";
    cin>>a>>b;
    cout<<" the swap of given A and B are: "<<b<<("\t")<<swap(a,b);
    return 0;
}