#include<iostream>
#include<cstdio>
using namespace std;

main(){
  int n;
  int M[15][15];
  while( cin >> n && n ) {
    for ( int i = 0; i < n; i++ )
      for ( int j = 0; j < n; j++ ) M[i][j] = 0;
    int cnt = 0;
    int pi = n/2+1, pj = n/2;
    M[pi][pj] = ++cnt;
    pi++; pj++;
    while(cnt < n*n){
      if ( pj >= n ){
	pj = 0;
      } else if ( pj < 0 ){
	pj = n-1;
      } else if ( pi >= n ){
	pi = 0;
      } else if ( M[pi][pj] ){
	pi++; pj--;
      } else {
	M[pi++][pj++] = ++cnt;
      }
    }
    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	printf("%4d", M[i][j]);
      }
      cout << endl;
    }
  }
}
