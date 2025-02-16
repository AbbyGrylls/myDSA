#include <iostream>
#include <vector>
using namespace std;
class MyClass {
    int* ptr;
public:
    MyClass(const vector<int>& vec) 
    {
        ptr= new int[vec.size()];
        size_t index=0;//an index varible//(remove this line)
        for(auto i=vec.begin();i<vec.end();++i,++index)//dereference the iterator to copy the value//(remove ++index)
        ptr[index]=*i;//ptr[*i]=vec[*i]//works fine but 1st element is arbitarly taking
    }
    //destructor to deallocate dynamic memory
    ~MyClass(){
        delete[] ptr;
    }
    void print()
    {
        for (int i = 0; i < 5; i++){
            cout << ptr[i]<< " ";
        }
    }
};
 
int main()
{
    vector<int> vec;
    for (int i = 1; i <= 5; i++)
        vec.push_back(i);
    MyClass obj(vec);
    obj.print();
    return 0;
}//breaking down the constructor:(DAM: dynamically allocated memory)
/*line 10: index of type size_t(unsigned integer type)is declared & is used to access elements of the DA array by the index
line 11: index play like an irerator,as i increments everytime index will too,both are related here
line 12:dereference iterator *i,gives the current element of vector. this element assign to current position in DA array
pointed to ptr pointer at the index position. this line copies vector to the allocated array*/

//cbegin and cend()-constant index numbers:cant be modified further.
//rbegin and rend()-therotical index no. before begin and end positions.
//crbegin and crend()-therotical constant index numbers.