#include<stdio.h>
void beq(int );
void beq(int a)
{
    if(a==0)
    {
        printf(" binary equivalent is 0");
    }
    else{
        int i=0,arr[32];
        while(a>0)
        {
            arr[i]=a%2;
            a=a/2;
            i++;
        }
        printf(" binary equivalent is 1\n");
        for (int j=i-1;j>=0;j--)
        {
            printf("%d\t",arr[j]);
        }
        }
    }

int main()
{
    int num;
    printf(" enter the number");
    scanf("%d",&num);
    beq(num);
    return 0;
}
}