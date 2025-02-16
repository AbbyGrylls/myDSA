
#include <stdio.h>
void swapa(int a,int b){
int c=a;
a=b;
b=c;
}
void swapb(int* a,int* b){
int c=*a;
*a=*b;
*b=c;
}
int main(){
int a,b;
printf("Ënter the two numbers");
scanf("%d %d",&a,&b);
printf("Before Swapping of PbV : %d %d\n",a,b);
swapa(a,b);
printf("After Swapping of PbV : %d %d\n",b,a);
printf("Before Swapping of PbR : %d %d\n",a,b);
swapb(&a,&b);
printf("After Swapping of PbR : %d %d\n",b,a);
}