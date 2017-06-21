#include<iostream>

using namespace std;

int A[20];

main(){
  int tcase;
  cin >> tcase;
  int n;
  for ( int i = 0; i < tcase; i++ ){
    cin >> n;
    for ( int j = 0; j < n; j++ ) cin >> A[j];
    sort(A, A+n);
    cout << "Case " << i+1 << ": ";
    cout << A[n/2] << endl;
  }
}
