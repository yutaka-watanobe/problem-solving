#include<iostream>
#include<cmath>
using namespace std;
#define MAX 10
#define EPS 0.000000001

main(){
  double len, v1, v2, A[MAX+1], l;
  char ch;
  while( cin >> l ){
    for ( int i = 0; i <= MAX; i++ ) A[i] = 0;
    A[0] = 0;
    A[1] = l;
    for ( int i = 2; i <= MAX; i++ ) {
      cin >> ch >> l;
      A[i] = A[i-1] + l;
    }
    cin >> ch >> v1 >> ch >> v2;
    double p = 1.0*A[MAX]*v1/(v1+v2);
    int cur = 0;
    for ( ; ;cur++ ){
      if (  p < A[cur] || fabs(p - A[cur]) < EPS) {
	cout << cur << endl;
	break;
      }
    }
  }
}
