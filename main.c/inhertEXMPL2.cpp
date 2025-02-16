#include<iostream>
using namespace std;
//INHERITANCE exmaple with ARGUMENTS in member functions/methods

class one{
    string name;
    int rol;
    public:
    void input(string n,int r){
        name=n;
        rol=r;
    }
    void display(){
        cout<<"the student data is:"<<rol<<")"<<name;
    }
};
class two: private one{
    public:
    void inputT(string n,int r){
        input(n,r);
    }
    void dis(){
        display();
    }
};
int main(){
    string n;
    int r;
    cout<<"enter student name;";
    cin>>n;
    cout<<"enter student roll number;";
    cin>>r;
    //one obj1;
    two obj2;
    obj2.inputT(n,r);
    obj2.dis();
    return 0;
}