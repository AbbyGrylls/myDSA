#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream mf;
    string line;
    mf.open("output.txt");
    while(mf){
        getline(cin,line);
        if (line=="-1"){
           break;
        }
        cout<<line<<endl;
    }
    mf.close();
    ifstream cs;
    cs.open("output.txt");
    while(getline(cs,line)){//getline(cs,line) is a function to copy contents from the file to the EOF
    //attached to object cs which opened the file in prev. line and transfer to line as a string
        cout<<line<<endl;
    }
    cs.close();
    return 0;
}
