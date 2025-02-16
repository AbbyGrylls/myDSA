#include<iostream>
#include<array>
#include<vector>

using namespace std;
class animal{
    public:
    virtual void sound(){
    }
};
class cat: public animal{
    public:
    void sound(){
        cout<<"meow meow"<<endl;
    }
};
class dog: public animal{
    void sound(){
        cout<<"bow bow"<<endl;
    }
};
class cow: public animal{
    void sound(){
        cout<<"moo moo"<<endl;
    }
};
int main(){
    int n;
    int alf;
    cout<<"enter number of animals:";
    cin>>n;
    animal *numb[n];
    for(int i=0;i<n;i++){
        cin>>alf;
        if(alf==1){
            numb[i]=new cat;
        }
        else if(alf==2){
            numb[i]=new dog;
        }
        else if(alf==3){
            numb[i]=new cow;
        }
        else{
            cout<<"invalid animal"<<endl;
        }
    }
    for(int i=0;i<n;++i){
        numb[i]->sound();
    }
    return 0;
}