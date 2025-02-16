#include<iostream>
#include<vector>
#include<map>
using namespace std;
template<typename t>class note{
    vector<map<t,t>>emp;
    public:
    void addvar(const map<t,t>& val){
        emp.push_back(val);
    }
    void dis(int Id){ 
    int l=emp.size();
        try
        {
            if(Id<0 || Id>=l){ //to avoid comparision problem-create a varible to assign with size but complexity?(just 4-6bits spaceand no  mere effect)
                throw//actually working without the new varible solution(Id>=emp.size() or Id>=l)
                out_of_range("Invalid Employee Id");
            }
            cout<<"the data of the employee is:"<<endl;
            for(const auto& dat:emp[Id]){
                cout<<dat.first<<":"<<dat.second<<endl;
            }
        }
        catch(const out_of_range& e){
            cout<<e.what()<<endl;
        }
    }
};
int main(){
    vector<string> dept{"Id","SALARY"};
    int n;
    cout<<"enter number of employees:";
    cin>>n;
    note<string>e;
    for(int i=0;i<n;i++){
        string name;
        map<string,string>val;
        cout<<"enter data of "<<i+1<<" employee "<<endl;
        while(true){//for name validation
            cout<<"enter employee NAME:";
            cin>>name;
            if(name.length()<5){
                cout<<"Name should be atleast 5 charecters"<<endl;
            }
            else{
                break;
            }
        }
        val["NAME"]=name;
        for(const auto& dep : dept){
            string varia;
            cout<<dep<<":";
            cin>>varia;
            val[dep]=varia;
        }
        e.addvar(val);
    }
    int Id;
    cout<<"enter employee Id to display the data:";
    cin>>Id;
    e.dis(Id-1);
    return 0;
}
//DMA can be used but it requires to a constructor with new function and making emp vector as a pointer. but the without
//DMA we can actually make DMA happen because vector will be automatically destroyed when e.dis() dis-called. going out of the scope of dis function.
//vec<map<stg,t>>* emp(pointer vector for dma)
//note():emp(new vec<map<stg,t>>()) {} (constrctor to DAM to vector pointer using new function)
//~note(){ delete emp; } (destructor deletes DallyAdM of emp vector ptr)