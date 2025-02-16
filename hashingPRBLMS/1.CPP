#include<bits/stdc++.h>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
bool isAlphanumeric(char c){
    return isalpha(c) || isdigit(c);
}
void rabinkarp(string t,string p){
    int st=t.length();
    int sp=p.length();
    int x=256;
    int prm=INT_MAX;
    int phash=0;
    int thash=0;
    int y=1;
    for(int i=0;i<sp-1;++i)
    y=(y*x)%prm;
    for(int i=0;i<sp;++i){
        phash=(x*phash+p[i])%prm;
        thash=(x*thash+t[i])%prm;
    }
    for(int i=0;i<=st-sp;i++){
        if (phash==thash){
            cout<<"pattern found at index: "<<i<<endl;
            /*for printing the whole sub-string where pattern is found*/
            int wstrt= max(0,i-1);
            int wstp= min(st-1,i+sp);
            while(wstrt>=0 && isAlphanumeric(t[wstrt]))
            wstrt--;
            while(wstp<st && isAlphanumeric(t[wstp]))
            wstp++;
            cout<<"matching word is: "<<t.substr(wstrt+1,wstp-wstrt-1)<<endl;
        }
        if(i<st-sp){
            thash=(x*(thash-t[i]*y)+t[i+sp])%prm;
            if(thash<0)
            thash=(thash+prm);
        }
    }
}
int main() {
    string t;
    string p;
    ifstream infile;
    infile.open("input.txt");
    if (infile.is_open()) {
        // Read the entire content of the file into 't'
        stringstream buffer;
        buffer << infile.rdbuf();
        t = buffer.str();

        infile.close();
    } else {
        cout << "Error opening file";
        return 1;
    }

    cout << "Enter pattern to search: ";
    cin >> p;
    rabinkarp(t, p);
    return 0;
}
