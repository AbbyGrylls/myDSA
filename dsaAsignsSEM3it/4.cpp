#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*int charcount(const string &a,char &c){
    int count;
    for(int i=0;i<a.length();i++){
        if(c==a[i]){
            count++;
        }
    }
    return count;
}*/
int main(){
    string a;
    int count;
    char c;
    ifstream file;
    cout<<"enter the charector to find search: ";
    cin>>c;
    file.open("input.txt");
    
    cout<<"the given charecter is repeated "<<count<<" times.";
    return 0;
}