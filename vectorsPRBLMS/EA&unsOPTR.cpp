//EA-element access:reference oprtr[],at,front,back,data.
//Unsigned operators:size,max_size,capacity,resize,empty,shrink_to_fit,reserve
#include<iostream>
#include<vector>
using namespace std;
class one{
    vector<string>v;
    public:
    one(const vector<string>& vec):v(vec){}
    virtual void dis(){//virtual func is to support polymorphism(ables to func overrdden in derived classes)
    //and it'll be determined at runtime,allows use of ptrs and referneces to base clas obj to call over riden func in derived class
        cout<<"the third name in the list is:"<<v.at(2)<<endl;
        cout<<"number of names in the list is:"<<v.size()<<endl;
        cout<<"extra space in the list is:"<<v.capacity()<<endl;
        cout<<"is the list empty:"<<v.empty()<<endl;
        v.resize(4);//its nesesary to use virtual when using refernce to obj(&).
        cout<<"nummber of elements after resize:"<<v.size()<<endl;
    }
};
class two: public one{
    public:
    two(const vector<string>& vecT):one(vecT){}//two has its own constructor,calls base class constructor using memebr 
//initializer list: one(vecT). it passes vecT vectr to base clas cnstrtr initilizing inherited v to these values
//one(vecT): class one contains vector v; it will be inherited as we are mentioning class one in the initlizer list

//as we are inheriting public one; it calls public members i.e dis() of  class one. here in the above constructor we 
//asigned values of vecT to inherited v. in dis(), wherever v used, it calls assigned valles of vecT to v.
};
class three: public one{
    public:
    three(const vector<string>& vecTh):one(vecTh){}
};//theres no over riden of dis()func so it calls base class version. if over ridden exists,calls the derived class version
int main(){
    vector<string>vec{"anasum","absie","suum","abhishek","notokay"};
    vector<string>vecT{"akshay","afzal","batchu","ashish","sreekar"};
    vector<string>vecTh{"sekhar","veekshith","shalem","ravi","jikki"};
    one obj(vec);
    two obj1(vecT);
    three obj2(vecTh);
    obj.dis();
    obj1.dis();
    obj2.dis();
    return 0;
}
//finally we used wrote only one dis() function and inherited in every class, constructor assigns values in diff classes
//q1: vectors can't be multiple datatypes in a single container, to do so we requires another library.,<variant>
//q2: vectors can't identify its datatype based on user input,we can use template classes BUT
//we've to write multiple code for various datatypes in main() but 'nother question why not template clas/func deduction use?
//no! not possible still, the answer of q2 is the process of this template deduction. achivble through only classes. 
//if int main() is only used then template be used but still user input dtatype prblm still exists.
//q3: what is an initialiser list used in line 22 and 31 and explain how it used?