#include<iostream>
#include<fstream>
#include<cstring>
#define MAX_STUDENTS 10
using namespace std;
struct student{
    char* name;
    int roll;
    char* teleph;
    char* adrs;
    student():name(nullptr),roll(),teleph(nullptr),adrs(nullptr){};
    ~student(){
        delete[] name;
        delete[] teleph;
        delete[] adrs;
    }
};
struct sreg
{
    int count;
    struct student* s;
    sreg():count(0),s(new student(MAX_STUDENTS)){}
    ~sreg(){
        for(int i=0;i<count;i++){
            delete[] s[i].name;
            delete[] s[i].teleph;
            delete[] s[i].adrs;
        }
        delete[] s;
    }
};
int get(sreg &sr, const student &s){
    if(sr.count>=MAX_STUDENTS) return 0;
    for(int i=0;i<sr.count;i++){
        if(sr.s[i].roll==s.roll){
            return 0;
        }
    }
    sr.s[sr.count].name=new char[strlen(s.name),s.name];

}