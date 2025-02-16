#include<iostream>
using namespace std;
class complex{
    float rl, img;
    public:
    complex(float r=0,float i=0){
        rl = r;
        img = i;
    }
    complex operator+(complex const& obj){//complex const& and const complex& both are same!!
        complex res;//creating a new object inside class 
        res.rl=rl+obj.rl;
        res.img=img+obj.img;
        return res;
    }
    void dis(){
        cout << rl << "+ i(" << img << ")"<<'\n';
    }
/*Complex& indicates that we are passing objects by reference and obj1 is a reference to Complex objects. 
This is an efficient approach because it avoids unnecessary copying, especially for large objects. 
const indicates that referenced objects are constant, meaning we cannot modify obj1 and obj2 within the function.
Inside the function, we created another Complex object, res to store the result of addition.*/
};
int main(){
    /*float r;
    float i;
    cout<<"enter real part:";
    cin>>r;
    cout<<"enter img part:";
    cin>>i;*/
    complex obj1(10,5),obj2(5,-10);
    complex obj3=obj1+obj2;
    obj3.dis();
    return 0;
}