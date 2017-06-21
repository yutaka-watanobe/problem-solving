// @JUDGE_ID:  17051CA  160  C++
// @begin_of_source_code
#include<stdio.h>
void getPrime( int * , int n);
void doPrime(int n);
void init( int * );
int prime[25];
int list[25];
int maxI;

main(){
  getPrime( prime, 100 );
  int n;
  while(1){
    scanf("%d", &n);
    if( n==0 ) return 0;
    init( list );
    maxI = 0;
    for(int i=n ; i>1 ; i--){
      doPrime( i );
    }
    printf("%3d! =", n);
    for(int k=0 ; k<=maxI ; k++){
      printf("%3d", list[k]);
      if( (k+1)%15 == 0 && k!=maxI) printf("\n      ");
    }
    printf("\n");
  }
}

void doPrime( int n ){
  int flag = 1;
  int i=0;
  while(flag){
    if( n%prime[i]==0 ){
      n = n/prime[i];
      list[i]++;
      if(maxI < i ) maxI = i;
    }else{
      i++;
    }
    if( n == 1 ) flag = 0;
  }
}

void getPrime( int *p, int n ){
  int limit,find;
  int cnt = 0;
  for(int i=2; i<=n; i++){
    limit=i-1;
    find=1;
    for(int j=2; j<=limit; j++){ 
      if (i%j==0){ 
	find=0;
	break;
      }
    }
    if(find==1){ 
      p[cnt++] = i;
    }
  }
}

void init( int *p ){
  for(int i=0; i<25 ; i++){
    p[i] = 0;
  }
}
// @end_of_source_code
