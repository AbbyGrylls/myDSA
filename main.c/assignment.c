#include<stdio.h>
int main()
{
   int x,n,f=1,i=1,j=1;
   float sum=1,p=1;
   printf("enter the values of x and n");
   scanf("%d %d",&x,&n);
   for (i=1;i<=n;i++)
   {
    for(j=1;j<i;j++)
    {
        p=p*x;
        f=f*j;
    }
    sum=sum+p/f;
   }
   printf("the result is %f",sum);
   return 0;
}