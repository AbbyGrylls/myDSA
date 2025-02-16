#include<iostream>
#include<deque>
using namespace std;
template<typename t>class note{
    deque<t> f;
public:
    note(const deque<t>& fk):f(fk){}
    int comp(){
        int c=0;
        t krismarks=f.front();
        auto i=f.begin();
        for(;i!=f.end();++i){
            if(*i>krismarks){
                c++;
            }
        }
        return c;
    }
};
int main(){
    int n;
    deque<float> fk;
    cout<<"enter number of students:";
    cin>>n;
    cout<<"enter marks of kris:";
    for(int i=0;i<n;i++){
        int sum=0,mark;
        for(int j=0;j<5;j++){
            cin>>mark;
            sum += mark;
        }
        fk.push_back(sum);
        cout<<"enter next student marks:"<<endl;
    }
    note<float> obj(fk);
    cout<<"no of students who got above kris is:"<<obj.comp();
    return 0;
}