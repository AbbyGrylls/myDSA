#include <iostream>
using namespace std;
struct emp
{
    string code;
    string name;
    int salary;
    int dept_no;
    double doj;
};
int main()
{   
    int n;
    emp e[n];//emp is the structure name more like a class and e[n] is the object name created from struct emp.
    cout<<"enter number of employees:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter employee ID:";
        cin>>e[i].code;
        cout<<"enter employee name:";
        cin>>e[i].name;
        cout<<"enter employee salary:";
        cin>>e[i].salary;
        cout<<"enter employee dept no:";
        cin>>e[i].dept_no;
        cout<<"enter employee date pf joining in DDMMYYYY format:";
        cin>>e[i].doj;
        cout<<"endl";
    }
    cout<<"Details of all employees whose salary is above 10,000"<<endl;
    for(int i=0;i<n;i++)
    {
        if(e[i].salary>=10000)
        {
            cout<<"Employee's name:"<<e[i].name<<endl;
            cout<<"Employee's ID:"<<e[i].code<<endl;
            cout<<"Employee's dept no.:"<<e[i].dept_no<<endl;
            cout<<"Employee's date of joining:"<<e[i].doj<<endl;
        }
        cout<<"endl";
    }
    return 0;
}