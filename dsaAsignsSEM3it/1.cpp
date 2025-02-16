#include<iostream>
using namespace std;
int main(){
    int a[10]={34,56,8,41,90,0,24,67,64,32};
    int l;
    int m;
    int s;
    l=m=s=0;
    for(int i=0;i<10;i++){
        if(a[i]>l){
            s=m;
            m=l;
            l=a[i];
        }
        else if(a[i]>m && a[i]!=l){
            s=m;
            m=a[i];
        }
        else if(a[i]>s&&a[i]!=m){
            s=a[i];
        }
    }
    cout<<l<<endl<<m<<endl<<s;
    return 0;
}