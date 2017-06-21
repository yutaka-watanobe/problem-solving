#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 52

void update( int &sum, int &l, int &r, int v){
  if ( abs(l - v) > abs(r - v) ){
    sum += abs(l - v); l = v;
  } else {
    sum += abs(r - v); r = v;
  }
}

int compute(){
  int A[MAX];
  int n; cin >> n;
  for ( int i = 0; i < n; i++ ) cin >> A[i];
  sort( A, A + n );
  int pl, pr, l, r, sum;
  pl = 0; pr = n-1;
  sum = 0;

  l = A[pl++];
  r = A[pr--];

  sum = r - l;

  for ( int i = 0; i < n-2; i++ ){
    if ( i%2 == 0 ){
      update( sum, l, r, A[pl++] );
    } else {
      update( sum, l, r, A[pr--] );
    }
  }
  
  return sum;
}

main(){
  int tcase; cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    cout << "Case " << i << ": " << compute() << endl;
  }
}
