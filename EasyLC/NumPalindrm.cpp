#include<iostream>
using namespace std;

bool isPalindrome(int givenNum){
    if(givenNum<0)
    return false;
    long long int num= givenNum, reversed= 0;
    while(num>0){
        int ld= (num%10);
        if ( reversed >(INT_MAX/10)) return false;
        reversed=ld+reversed*10;
        num /=10;
    }
    return reversed==givenNum;
}
int main(){
    int givenNum;
    cout<<"enter the number to check the palindrome";
    cin>>givenNum;
    if(isPalindrome(givenNum))
    cout<<"a palindrome"<<endl;
    else
    cout<<"not a palindrome"<<endl;
    return 0;
}