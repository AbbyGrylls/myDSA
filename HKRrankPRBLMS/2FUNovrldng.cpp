#include<iostream>
#include<array>
#include<vector>
//INHERITANCE achieved with FUNCTION OVERLOADING
using namespace std;
class person{
    public:
    string name;
    int age;
    virtual void get_data(){
        cin>>name>>age;
    }
    virtual void put_data(){
        cout<<name<<" "<<age<<endl;
    }
};
class prof: public person{
    static int cur_id;
    int pblcs;
    public:
    prof(){
        cur_id++;
    }
    void get_data(){
        cin>>name>>age>>pblcs;
    }
    void put_data(){
        cout<<"NAME OF THE PROFESSOR:"<<name<<endl;
        cout<<"AGE:"<<age<<endl;
        cout<<"publications published:"<<pblcs<<endl;
    }
};
int prof::cur_id;
class student: public person{
    static int cur_id;
    int marks[6];
    public:
    student(){
        cur_id++;
    }
    void get_data(){
        cin>>name>>age;
        for(int i=0;i<6;++i){
            cin>>marks[+
            i];
        }
    }
    void put_data(){
        int sum=0;
        for(int i=0;i<6;++i){
            sum +=marks[i];
        }
        cout<<"NAME OF THE STUDENT:"<<name<<endl;
        cout<<"AGE:"<<age<<" SUM:"<<sum<<" "<<cur_id<<endl;
    }
};
int student::cur_id;
int main(){
    int n;
    int val;
    cin>>n;
    person *per[n];
    for(int i=0;i<n;i++){
        cin>>val;     
        if(val==1){
            per[i]=new prof;
        }
        else{
            per[i]=new student;
        }
        per[i]->get_data();
    }
    //for(int i=0;i<n;i++){
       ((student*) per[2])->put_data();
    //} 
    return 0;
}
