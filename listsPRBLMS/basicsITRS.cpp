#include<iostream>
//#include<iterator>
#include<list>
using namespace std;
//merging and sorting
list<int> mas(const list<int>&lo,const list<int>&lt){
    list<int>lr;
    list<int>lop=lo;
    list<int>ltp=lt;
    lop.sort();ltp.sort();
    auto i=lop.begin();
    auto it=ltp.begin();
    for(;i!=lop.end();++i){
    for(;it!=ltp.end() && *it<=*i;++it)
    //for(auto i: lo, auto it: lt)
      {
        lr.push_back(*it);
      }
      lr.push_back(*i);
    }
    for(;it!=ltp.end();++it){
        lr.push_back(*it);
    }
    return lr;
}
int main(){
    list<int> lo={4,7,8};
    list<int> lt={2,3,9};
    list<int>final= mas(lo,lt);
    for(int n: final){
        cout<<n<<" ";
    }
    cout<<" "; 
    return 0;
}