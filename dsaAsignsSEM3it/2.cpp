#include<iostream>
using namespace std;
int main(){
    int a[10]={34,56,8,41,90,0,24,67,64,32};
    for(int i=0;i<5;i++){//if odd size,tot/2)-1--iterations
        int temp=a[0+i];
        a[0+i]=a[9-i];
        a[9-i]=temp;
    }
    for(int i=0;i<10;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}