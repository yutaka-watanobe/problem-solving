#include<stdio.h>
#include<math.h>

int is_sqrt(int);

void main(void){
  int n;
  
  printf("Input the number : ");
  scanf("%d", &n);
  
  if (is_sqrt(n))
    printf("%d is square number. \n", n);
  else
    printf("%d is not square number. \n", n);
}

int is_sqrt(int n)
{
  if (sqrt(n) == floor(sqrt(n)))
    return 1;
  return 0;
}

