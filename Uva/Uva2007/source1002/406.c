// @JUDGE_ID:  17051CA  406  C++
// @begin_of_source_code
#include<stdio.h>
#include<stdlib.h>

int getPrimeNumber(int *, int);

main(){
  int primeN[171];
  int isfirst = 1;
  int n, c, count;

  getPrimeNumber( primeN, 1010 );

  while( scanf("%d %d", &n, &c ) != EOF ){
    count = 0;
    while( primeN[count] <= n ){
      count++;
    }

    if( isfirst != 1) printf("\n"); 
    else isfirst = 0;
    printf("%d %d:", n, c);
    if( n == 1 && c == 1 ){
      printf(" 1\n");
      continue;
    }
    int center, start, num;
    if( count%2 == 0){
      num = 2*c;
      center = (count+1)/2;
      start = center - num/2;
      if( start < 0 ){
	start = 0; num = count;
      }
      for(int i=start ; i<start+num ; i++){
	printf(" %d", primeN[i]);
      }
      printf("\n");
    }else{
      num = 2*c-1;
      center = (count-1)/2;
      start = center - num/2;
      if( start < 0 ){
	start = 0; num = count;
      }
      for(int i=start ; i<start+num ; i++){
	printf(" %d", primeN[i]);
      }
      printf("\n");
    }
  }
  return 0;
}

int getPrimeNumber(int *p, int n){
  int c, i, j, judge;
  int count = 0;
  i = 3;
  c = 0;
  p[0] = 1;
  p[1] = 2;
  while (i <= n) {
    judge = 0;
    for (j = 0; p[j+1] <= sqrt(i); j++) {
      if (i % p[j+1] == 0) {
	judge = 1;
	break;
      }
    }
    if (judge == 0) {
      c++;
      p[c+1] = i;
      count++;
    }
    i++;
  }
  return count+2;
}
// @end_of_source_code
