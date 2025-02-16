#include <iostream> 
using namespace std; 
//EXAMPLE CODE OF INHERITANCE WITOUT ARGUMENTS IN MEMBER FUNCTIONS

/*with arguments is more like a parametrised constructor,
functions take inputs from int main and store them at a varible declared in function member,
and use those variable to assign with or without alterations to the private varible declared in class.*/

class one{
    char name[50];
    int rol;
    public:
    /*one(string x,int y){
        name=x;
        rol=y;
    };*/
    void stu(){
        cout<<"Enter student name:";
        cin>>name;
        cout<<"Enter student Roll number:";
        cin>>rol;
    };
    void display(){
        cout<<"Student data is:"<<rol<<")"<<name<<endl;
    };
};
class two:private one{
    public:
    void stuT(){
        stu();
    };
    void displayT(){
        display();
    };
};
int main(){
    //string x;
    //int y;

    one obj;
    two objT;
    obj.stu();
    objT.stuT();
    obj.display();
    objT.displayT();
    return 0;
}
