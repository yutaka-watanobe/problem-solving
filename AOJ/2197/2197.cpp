#include<iostream>
using namespace std;
#define MAX 1000

main(){
  int n;
  int T[MAX+1];
  while( cin >> n && n ){
    T[0] = 0;
    for ( int i = 1; i <= n; i++ ) T[i] = T[i-1] + i;
    int sum = 0;
    for ( int i = 0; i <=n-2; i++ ){
      for ( int j = i+2; j <= n; j++ ){
	if ( T[j]-T[i] == n ) {
	  sum++;
	}
      }
    }
    cout << sum << endl;
  }
}
