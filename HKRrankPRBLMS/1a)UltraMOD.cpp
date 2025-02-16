#include<iostream>
#include<vector>
#include<map>
using namespace std;
template<typename t>class note{
    vector<map<string,t>> ssv;
    public:
    void as(const map<string,t>& scores){//why not a constructor? ANS: to avoid creating multiple vectors from main,
    // create a map of marks and subj in main and export values here and then we directly transfers[map->vector].
        ssv.push_back(scores);
    }
    void dis(int rollno){
        cout<<"Marks of Student of Roll NO:"<<rollno<<":"<<endl;
        for (const auto& subscor:ssv[rollno]){
            cout<<subscor.first<<":"<<subscor.second<<endl;
        }
    }
};
int main(){
    vector<string>subjects{"MATHS","PHYSICS","CHEMISTRY","COMPUTING","ENGLISH"};
    int n;
    cout<<"enter number of students:";
    cin>>n;
    note<float> stdns;
    for(int i=0;i<n;++i){
        map<string,float>scores;
        cout<<"enter marks of student "<<i+1<<":"<<endl;
        for(const auto& subject : subjects){
            float score;
            cout<<subject<<":";
            cin>>score;
            scores[subject]= score;
        }
        stdns.as(scores);
    }
    int rollno;
    cout<<"enter the student roll number:";
    cin>>rollno;
    stdns.dis(rollno-1);
    return 0;
}