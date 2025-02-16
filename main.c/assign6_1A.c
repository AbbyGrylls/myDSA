#include<stdio.h>
long power(int a, int b);

int main()
{
  int num1, num2;

  printf("Enter base and power: ");
  scanf("%d %d",&num1, &num2);

  long result = power(num1, num2);
  printf("The result = %ld", result);

  return 0;
}

// User-defined function to calculate power
long power(int a, int b)
{
  long result = 1;
  for(int i=1; i<=b; i++)
  {
    result = result * a;
  }
  return result;
}