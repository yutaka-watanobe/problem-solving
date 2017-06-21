// @JUDGE_ID:  17051CA  10679  C++
// @begin_of_source_code
#include<stdio.h>
#include<stl.h>
#include<map>
#include<string>
#define MAXT 100001
#define MAXP 1002

char T[MAXT], P[MAXP];
int N[MAXP];
int n, m;
map<string, int> M;

void init(){
  int i, j;
  N[0] = -1;
  for ( i = 0, j = -1; i < m; i++, j++, N[i] = j ){
    while ( ( j >= 0 ) && (P[i] != P[j] ) ) {
      j = N[j];
    }
  }
}

bool kmp(){
  int i, j, cnt;
  i = j = cnt = 0;
  init();

  while ( i < n && j < m ){
    while ( j >= 0 && ++cnt && (T[i] != P[j] ) ) {
      j = N[j];
    }
    i++; j++;
  }

  if ( j == m ) return true;
  else return false;
}

void work(){
  int q;
  scanf("%d", &q );
  for ( int i = 0; i < q; i++ ){
    scanf("%s", P );
    m = strlen( P );

    if ( M[P] == 1 ) printf("y\n");
    else if ( M[P] == 2 ) printf("n\n");


    if ( kmp() ){
      M[P] = 1;
      printf("y\n");
    }else{
      M[P] = 2;
      printf("n\n");
    }
  }
}

void read(){
  scanf("%s", T );
  n = strlen( T );
}

main(){
  int tcase;
  scanf("%d", &tcase);
  for (int i = 0; i< tcase; i++){
    M = map<string, int>();
    read();
    work();
  }
}

// @end_of_source_code
