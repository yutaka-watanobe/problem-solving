// factorize
// too slow !!!
#include<stdio.h>
#define MAX 1000000

int factorize(int x ){

  int sum = 0;
  if(x<2) return 0;

  for(; !(x&1); x>>=1) sum++;
  for(; x%3==0; x/=3) sum++;

  for(int p=5, b=1; x/p>=p; b=-b, p+=3+b){
    for(; x%p==0; x/=p) sum++;
  }
  
  if(x>1) sum++;

  return sum;
}

int sfactorize( int x ){
  int sum = 0;
  int d, q;
  
  while ( x >= 4 && x % 2 == 0 ){
    x /= 2;
    sum++;
  }

  d = 3; q = x / d;

  while ( q >= d ){
    if ( x % d == 0 ){
      if ( d > 1 ) sum++;
      x = q;
    } else {
      d += 2;
    }

    q = x / d;
  }

  if ( x > 1 ) sum++;

  return sum;
}

int T[MAX + 1];

void init(){
  T[2] = 1;

  for ( int i = 3; i <= MAX; i++ ){
    T[i] = T[i-1] + factorize(i);
  }
}


main(){
  init();
  int n;
  while ( scanf("%d", &n) != EOF) printf("%d\n", T[n]);
}
