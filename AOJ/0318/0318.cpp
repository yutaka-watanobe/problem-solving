#include<iostream>
using namespace std;

main(){
  int N;
  int A[101], B[101], C[101];
  
  cin >> N;
  
  for ( int i = 1; i <= N; i++ ) A[i] = B[i] = C[i] = false;
	
  int k, p;
  cin >> k;
  for ( int i = 0; i < k; i++ ) { cin >> p; A[p] = true; }
  cin >> k;
  for ( int i = 0; i < k; i++ ) { cin >> p; B[p] = true; }
  cin >> k;
  for ( int i = 0; i < k; i++ ) { cin >> p; C[p] = true; }

  int ans = 0;
  for ( int i = 1; i <= N; i++ ){
    if (!A[i] && C[i] || B[i] && C[i]) ans++;
  }
  
  cout << ans << endl;
}
