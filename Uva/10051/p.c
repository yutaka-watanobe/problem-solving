// @JUDGE_ID:  17051CA  10051  C++
// @begin_of_source_code
/* Dynamic Programming ( application of LIS ) */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 501

int n;
int T[6][MAX];
int ttob[6] = {1, 0, 3, 2, 5, 4}; /* mapping top to bottom */
string face[6] = {"front", "back", "left", "right", "top", "bottom"};

int read(){
  cin >> n;
  if ( n == 0 ) return 0;
  int k;
  for ( int i= n-1; i >=0; i-- ){
    for ( int j = 0; j < 6; j++ ){
      cin >> k;
      T[j][i] = k;
    }
  }
  return 1;
}

void work(){
  /* lis */
  int L[6][MAX];
  pair<int, int>  P[6][MAX];
  for ( int i = 0; i < 6; i++ ){
    fill ( L[i], L[i] + n, 0 );
    fill ( P[i], P[i] + n, make_pair(-1, -1) );
  }
  
  for ( int i = 0; i < n; i++ ){
    for ( int l = 0; l < 6; l++ ){
      int m = 0;
      for ( int j = 0; j < i; j++ ){
	for ( int k = 0; k < 6; k++ ){
	  if ( T[ k ][j] == T[ttob[l]][i] && m < L[k][j] ){
	    m = L[k][j];
	    P[l][i] = make_pair(k, j);
	  }
	}
      }
      L[l][i] = m + 1;
    }
  }
  
  int max_element;
  pair<int, int> max_index;
  max_element = -1;

  for ( int i = 0; i < 6; i++ ){
    for ( int j = 0; j < n; j++ ){
      if ( L[i][j] > max_element ){
	max_element = L[i][j];
	max_index = make_pair(i, j); 
      }
    }
  }

  cout << max_element << endl;
  
  int i, j, ni, nj;
  i = max_index.first;
  j = max_index.second;

  while(1){
    if ( i == -1 && j == -1 ) break;
    cout << n - j << " " << face[ i ] << endl;
    ni = P[i][j].first;
    nj = P[i][j].second;
    i = ni; j = nj;
  }
}

main(){
  for ( int i = 1; read(); i++ ){
    if ( i-1 ) cout << endl;
    cout << "Case #" << i << endl;
    work();
  }
}
// @end_of_source_code
