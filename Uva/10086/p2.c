// @JUDGE_ID:  17051CA  10086  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

int T1, T2, n;
int M[25][35];
int S[30];

/* for search */
int G[30]; /* goal path */
int P[30];
int cost, cnt;
int minimum_cost;

void createTable( int index ) {
  int m;
  int N[21], B[21];
  N[0] = B[0] = 0;

  cin >> m;
  S[index] = m;

  for ( int i = 1; i <= m; i++ ){
    cin >> N[i];
  }
  for ( int i = 1; i <= m; i++ ){
    cin >> B[i];
  }

  for ( int i = 0; i <= m; i++ ){
    M[i][index] = N[i] + B[m-i];
  }

}

void init(){
  for ( int i = 0; i < 25; i++ ){
    fill ( M[i], M[i] + 35, INT_MAX );
  }
}

int read(){
  cin >> T1 >> T2;
  if ( T1 == 0 && T2 == 0 ) return 0;
  cin >> n;
  init();
  for ( int j = 0; j < n; j++ ){
    createTable(j);
  }
  return 1;
}

void rec(int index){
  if ( index == n ){
    if ( cnt == T1 && cost < minimum_cost ){
      minimum_cost = cost;
      G = P;
    }
    return;
  }

  for ( int i = 0; i <= S[index]; i++ ){
    if( cnt + i > T1 ) break;
    
    P[index] = i;
    cnt += i;
    cost += M[i][index];
    rec( index + 1 );
    cnt -= i;
    cost -= M[i][index];

  }
}

void work(){
  minimum_cost = INT_MAX;
  cnt = 0;
  cost = 0;
  rec( 0 );

  cout << minimum_cost << endl;
  for ( int i = 0; i < n; i++ ){
    if ( i ) cout << " ";
    cout << G[i];
  }
  cout << endl;
  cout << endl;
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
