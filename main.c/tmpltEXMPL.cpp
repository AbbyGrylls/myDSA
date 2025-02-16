#include<iostream>
using namespace std;
template<typename T>class array{ //template "T" of any datatype is created using typename keyword
//a class named-"array" is created 
    private:
    T* ptr;//a pointer ptr is assigned to datatype T to store the address returned by new operator
    int size;//size is no of elements always an integer so pre determined
    public:
    array(T arr[], int s)//constructor same name as class, another thing as we dont know the datatype of array
    //so we called template T to call datatype from the user
    {
        ptr = new T[s];//new operator-dynamic memory allocation for "s" variable used at compile run
        size = s;//the created ptr is an arrray of size "s" with datatype "T"(allocate a block of memory)
        for(int i=0;i<size;i++)
        {
            ptr[i]=arr[i];
        }
    }
    void print(){
        for(int i=0;i<size;i++)
        cout << " " << *(ptr + i)<<endl;
    }
};
int main()
{
    int arr[5]={1,2,3,4,5};
    array<int>a(arr,5);//oject a is created to class array
    a.print();
    return 0;
}
//there could be multiple class mentioned in same array
//we could pass multiple datatypes in the same object,ex: 27th line modify: array<int,int>a 28th line: array<char,char>b
//Function overloading is used when multiple functions do quite similar (not identical) operations, 
//templates are used when multiple functions do identical operations 
//learn templates and static variables
//we used class template here, actually there is function template is used to avoid writing multiple codes for same function for diff datatypes
//so basically template of typename T as a datatype is default means T could be any type and when object created with a specified type
//that datatype will pass with the parameter into the class or struct used
//we can also pass non-type parameters like max value on an arr[max]. to do so we have to mention of its datatype in template type declaration
//ex: template<class or typename T, int max>
//instead of function overloading we can create multiple objects with diff datatypes and pass those values into the class.
//another important thing is  template classes and function deducton since c++17 is used to identiy datatype by compiler itself,syntax:
/*template <typename t>
t multiply (t num1,t num2) { return num1*num2; }*/
//and we can call it simply like this: multiple (25,3) 
/*template<typename t>
class student{
    private:
       t total_marks;
    public:
       student(t x) : total_marks(x) {}
}*/
//we can call it simply;student obj(24)
