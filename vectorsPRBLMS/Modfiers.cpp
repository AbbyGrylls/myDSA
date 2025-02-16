//assign,push_back,pop_back,insert,erase,swap,clear,emplace,emplace_back,data,get_allocator;
#include<iostream>
#include<vector>
using namespace std;
template<typename t>class one{
    vector<t>v;
    int c=0;
    one(const vector<t>& vec):v(vec){}
    virtual void func(){
        
    }

}