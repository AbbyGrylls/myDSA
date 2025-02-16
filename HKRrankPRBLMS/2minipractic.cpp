#include<iostream>
#include<array>
using namespace std;
class shape{
    public:
    virtual void draw(){
    }
};
class circle: public shape{
    public:
    static int id;
    circle(){
        id++;
    }
    void draw(){
        cout<<"no."<<id<<" drawing circle"<<endl;
    }
};
int circle::id;
class rectngl: public shape{
    public:
    static int id;
    rectngl(){
        id++;
    }
    void draw(){
        cout<<"no."<<id<<" draing rectangle"<<endl;
    }
};
int rectngl::id;
int main(){
    int noof;
    cout<<"enter number of shapes: ";
    cin>>noof;
    shape *sp[noof];
    for(int i=0;i<noof;++i){
        int val;
        cout<<"enter numb to shape,1-circle 2-rectangle:"<<endl;
        cin>>val;
        if(val==1){
            sp[i]=new circle;
        }
        else{
            sp[i]=new rectngl;
        }
        sp[i]->draw();
    }   
    return 0;
}