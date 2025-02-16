#include<iostream>
using namespace std;
class emply{
    private:
    int a[10];
    string ID;
    string name;
    double salary;
    /*int dept;
    int d_doj;
    int m;
    int y;*/
    public:
    emply(int n)
    {
        for(int i=0;i<n;i++)
        {
        cout<<"enter employee ID:";
        cin>>ID;
        cout<<"enter employee name:";
        cin>>name;
        cout<<"enter employee salary:";
        cin>>salary;
        }
        //cout<<"enter employee dept no:";
        //cin>>dept;
        //cout<<"enter employee day of joining in DD format:";
        //cin>>d_doj;
        //cout<<"enter employee month of joining in MM format:";
        //cin>>m;
        //cout<<"enter employee year of joining in YYYY format:";
        //cin>>y;
    };
    void display(){
        if(salary>=10000){
            cout<<"EMPLOYEE NAME is:"<<name<<endl;
        }
    };
};
int main()
{
    int n;
    cout<<"enter number of emplpoyees:";
    cin>>n;
    emply obj(n);
    obj.display();
    return 0;
}
//creating multiple objects results in creating multiple copies of class