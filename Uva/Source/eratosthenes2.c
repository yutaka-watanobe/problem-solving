#include<stdio.h>
#include<math.h>

#define	max 10000

void getPrimeNumber(long p[], long);
int getNumberOfPrime(long);

void main(void){
  long	i, n, p[max];
  
  printf("Input the end number.  ");
  scanf("%ld", &n);
  
  getPrimeNumber(p, n);
  
  for (i = 0; p[i] != 0; i++) {
    printf("%ld  ", p[i]);
  }
  printf("\n number of Prime number = %d\n", getNumberOfPrime(n));
  return 0;
}

void getPrimeNumber(long p[], long n){
  long	c, i, j, judge;
  for (i = 0; i < max; i++) p[i] = 0;
  
  i = 3;
  c = 0;
  p[0] = 2;
  
  while (i <= n) {
    judge = 0;
    for (j = 0; p[j] <= sqrt(i); j++) {
      if (i % p[j] == 0) {
	judge = 1;
      }
    }
    if (judge == 0) {
      c++;
      p[c] = i;
    }
    i++;
  }
}

int getNumberOfPrime(long n)
{
  long *p;
  p = (long *)malloc(n*sizeof(long));
  long	c, i, j, judge;
  long count = 0;
  for (i = 0; i < max; i++) p[i] = 0;
  
  i = 3;
  c = 0;
  p[0] = 2;
  
  while (i <= n) {
    judge = 0;
    for (j = 0; p[j] <= sqrt(i); j++) {
      if (i % p[j] == 0) {
	judge = 1;
      }
    }
    if (judge == 0) {
      c++;
      p[c] = i; count++;
    }
    i++;
  }
  return count;
}
