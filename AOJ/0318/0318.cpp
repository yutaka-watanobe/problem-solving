#include<iostream>
using namespace std;

int main(){
  int N, A[101], B[101], C[101];
  
  cin >> N;
  
  for ( int i = 1; i <= N; i++ ) A[i] = B[i] = C[i] = false;
	
  int X, Y, Z, a, b, c;
  cin >> X;
  for ( int i = 0; i < X; i++ ) { cin >> a; A[a] = true; }
  cin >> Y;
  for ( int i = 0; i < Y; i++ ) { cin >> b; B[b] = true; }
  cin >> Z;
  for ( int i = 0; i < Z; i++ ) { cin >> c; C[c] = true; }

  int ans = 0;
  for ( int i = 1; i <= N; i++ ){
    if (!A[i] && C[i] || B[i] && C[i]) ans++;
  }
  
  cout << ans << endl;
  return 0;
}
