//eager to lazy to weighted approach
#include<iostream>
#include<array>
using namespace std;

class cls{
    int *r,*p,n;//r=rank;p=parent;
    public:
    cls(int n){
        r=new int[n];
        p=new int[n];
        this->n=n;//this is a oprator use as a pointer to point the incoming n used in above above equations;
        makeset();
    }
    void makeset(){
        for(int i=0;i<n;i++){
            p[i]=i;
        }
    }
    int find(int x){
        if(p[x]!=x){
            p[x]=find(p[x]);
        }
        return p[x];
    }
    void uni(int x,int y){
        int xset=find(x);
        int yset=find(y);
        if(xset==yset){
            return;
        }
        if(r[xset]<r[yset]){
            p[xset]=yset;        
        }
        else if(r[xset]>r[yset]){
            p[yset]=xset;
        }
        else{
            p[yset]=xset;
            r[xset]=r[xset]+1;
        }
    }
};
int main(){
    cls obj(10);
    obj.uni(0,2);
    obj.uni(4,2);
    obj.uni(3,1);
    obj.uni(5,7);
    obj.uni(5,9);
    obj.uni(0,7);
    if(obj.find(5)==obj.find(4))
    cout<<"great\n";
    else 
    cout<<"no";
    if (obj.find(1) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    return 0;
}