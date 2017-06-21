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

void work(){
  int PP[301][31];
  int PT[301];
  
  PT[0] = 0;
  for ( int i = 0; i < n; i++ ) {
    PP[0][i] = 0;
    PT[0] += M[0][i];
  }
  
  int sum, cost;
  int tmp[31];
  
  cout << PT[0] << endl;
  for ( int t = 1; t <= T1; t++ ){
    int m = INT_MAX;
    for ( int j = t-1; j >= 0; j-- ){
      sum = 0;
      for ( int k = 0; k < n; k++ ){
	tmp = PP[j];
	cost =  PT[j] - M[ PP[j][k] ][k] + M[ PP[j][k] + t-j ][k];
	cout << "cost = " << cost << endl;
	if ( cost < m ){
	  m = cost;
	  PT[t] = cost;
	  tmp[k] += t-j;
	  PP[t] = tmp;
	}
      }
    }
    cout << PT[T1] << endl;
  }

  cout << PT[T1] << endl;
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
