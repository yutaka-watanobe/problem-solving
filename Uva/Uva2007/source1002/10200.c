// @JUDGE_ID:  17051CA  10200  C++
// @begin_of_source_code
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stl.h>

typedef unsigned long ulong;
int isPrime( long *ans , int *n);
bool isprime(unsigned long long x);

long *p;
long n;
main(){
  int a, b;
  long long ans;
  int count;
  int c;
  while( scanf("%d %d", &a, &b) != EOF ){
    count = 0;
    c = b-a+1;
    for(int n=a ; n<=b ; n++ ){
      ans = n*n + n + 41;
      /*
      if( isPrime(&ans, &n) == 1) {
	count++;
      }
      */
      if( isprime(ans) == 1) {
	count++;
      }
    }
    printf("%.2f\n", (count/(c*1.0))*100 );
  }
  return 0;
}
int base[6] = {0, 2, 3, 5, 7, 11};
ulong limit[4] = {2047, 1373653, 25326001, 2147483647};
bool isprime(unsigned long long x){
  unsigned long long d, d1, prod, a2j;
  int s;

 if(x==2) return 1;
 if(x%2==0) return 0;
 
 for(d=x-1, s=0; d>0 && d%2==0; d/=2, s++);
 d1 = d;

 for(int i=1; i<=5; i++){
   a2j = base[i]; prod = 1; d = d1;
   while(d > 0){
     if(d%2==1) prod = (prod*a2j)%x;
     d /= 2;
     a2j = (a2j*a2j)%x;
   }

   if(prod==1 || prod==x-1) goto lim_check;

   for(unsigned long long j=1; j<=s-1; j++){
     prod = (prod*prod)%x;
     if(prod==1) return 0;
     if(prod==x-1) goto lim_check;
   }
   return 0;
 lim_check:
   if(x < limit[i]) return 1;
 }
}
int isPrime(long *ans, int *n){
  long limit = *ans-1;
  int find = 1;
  for(int j=41; j<=limit; j++){ 
    if(*ans%j==0){
      find = 0;
      break;
    }
    if( *n+10<j  ){
      find = 1;
      break;
    }
    j++;
  }
  if(find==1){
    return 1;
  } else {
    return 0;
  }
}

// @end_of_source_code
