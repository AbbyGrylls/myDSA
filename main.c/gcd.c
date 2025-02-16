#include <stdio.h>
int gcd(int n1,int n2){
if (n2!=0) return gcd(n2,n1%n2);
else return n1;
}
int main(){
int a,b;
printf("Enter the first number :");
scanf("%d",&a);
printf("Enter the second number :");
scanf("%d",&b);
printf("The GCD is - %d",gcd(a,b));
}