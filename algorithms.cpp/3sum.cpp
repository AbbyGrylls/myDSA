#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
int oat;
int bs(const vector<int>& input, int lft, int rgt){
    if(lft>rgt) return -1;
    int mid=lft+(rgt-lft)/2;
    if(input[mid]==oat){
        return input[mid];
    }
    else if(input[mid]<oat){
        return bs(input,mid+1,rgt);
    }
    else{
        return bs(input,lft,mid-1);
    }
};
class sol{
    public:
    vector<int>res;
    sol(const vector<int>& input){
        for(auto i=input.begin();i!=input.end();++i){
            for(auto j=i+1;j!=input.end();++j){
                oat=-(*i+*j);
                int found=bs(input,0,input.size()-1);
                if(found!=-1){
                    res.push_back(*i);
                    res.push_back(*j);
                    res.push_back(found);
                }
            }
        }
    }
};
int main(){
    vector<int> input;
    ifstream infile;
    infile.open("input.txt");
    if (!infile.is_open()){
        cout<<"error opening file"<<endl;
        return 1;
    }
    int value;
    while(infile>>value){
        input.push_back(value);
    }
    sort(input.begin(),input.end());
    infile.close();
    sol obj(input);
    for(size_t i=0;i<obj.res.size();i+=3){
        cout<<obj.res[i]<<" "<<obj.res[i+1]<<" "<<obj.res[i+2]<<endl;
    }
    //here we directly used a cnstr so to call out the final result of cnstr, we use obj refernce cause
    //obj is assigned to class and class is co-assigned with cnstr,not a function to call the function. 
    return 0;
}