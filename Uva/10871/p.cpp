#include<stdio.h>
#include<cmath>
#include<algorithm>

#define MAX 10002
#define PMAX 10000000

using namespace std;

bool prime[PMAX+1];

void eratos( int n){

  fill(prime, prime+PMAX, false);
  /* 奇数を素数候補とする */
  for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
  prime[2] = true;
  
  /* 合成数でない奇数だけを残す */
  for ( int i = 3, limit = (int)sqrt(n); i <= limit; i += 2 ) {
    if ( !prime[i] ) continue;
    
    for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = false;
  }
}

int T[MAX+1];
int M[MAX+1];
int n;

pair<int, int> compute(){
  
  for ( int i = 1; i <= n; i++ ){
    M[i] = T[i];
  }
  M[0] = 0;

  for ( int i = 2; i <= n; i++ ){
    for ( int j = i; j <= n; j++ ){
      M[j] = M[j-1] + T[j] - T[j-i];
      if ( prime[ M[j] ] ) return make_pair(j, i);
    }
  }

  return make_pair(-1, -1);
}

void work(){
  pair<int, int> ans;

  ans = compute();

  int i = ans.first;
  int w = ans.second;
  if ( i == -1 && w == -1 ){
    printf("This sequence is anti-primed.\n");
    return;
  }

  printf("Shortest primed subsequence is length %d:", w );

  for ( int a = i - w + 1; a <= i; a++ ) printf(" %d", T[a]);
  printf("\n");

}

void read(){
  scanf("%d", &n);
  for ( int i = 1; i <= n; i++ ){
    scanf("%d", &T[i]);
  }
}

main(){
  eratos(PMAX);

  int tcase; scanf("%d", &tcase);
  for ( int i = 0; i <tcase; i++ ){
    read();
    work();
  }
}
