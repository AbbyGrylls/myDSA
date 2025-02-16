#include<iostream>
using namespace std;
float sum_a(struct cmplx e[100],int n);
float sum_b(struct cmplx e[100],int n);
float sub_a(struct cmplx e[100],int n);
float sub_b(struct cmplx e[100],int n);
struct cmplx
{
    float a;
    float b;
};
int main ()
{
    int n,k;
    cout<<"enter the number of complex numbers:"<<endl;
    cin>>n;
    struct cmplx e[n];
    for(int i=0;i<n;++i)
    {
        cout<<"enter the value of real part:";
        cin>>e[i].a;
        cout<<"enter the value of imaginary part:";
        cin>>e[i].b;
    }
    cout<<"enter the type of arthematic operation:"<<endl<<"1)ADDITION"<<endl<<"2)SUBRACTION"<<endl;
    cin>>k;
    if(k==1)
    {
        cout<<"the addition result is:"<<sum_a(e,n)<<"+i("<<sum_b(e,n)<<")";
    }
    if(k==2)
    {
        cout<<"the subraction result is:"<<sub_a(e,n)<<"+i("<<sub_b(e,n)<<")";
    }
}
float sum_a(struct cmplx e[100],int n)
{
    int sum=0;
    for(int i=0;i<n;++i)
    {
        sum=sum+e[i].a;
    }
    return sum;
}
float sum_b(struct cmplx e[100],int n)
{
    int sum=0;
    for(int i=0;i<n;++i)
    {
        sum=sum+e[i].b;
    }
    return sum;
}
float sub_a(struct cmplx e[100],int n)
{
    int sum=0;
    for(int i=1;i<n;++i)
    {
        sum=sum-e[i].a;
    }
    int x=sum+e[0].a;
    return x;
}
float sub_b(struct cmplx e[100],int n)
{
    int sum=0;
    for(int i=1;i<n;++i)
    {
        sum=sum-e[i].b;
    }
    int x=sum+e[0].b;
    return x;
}