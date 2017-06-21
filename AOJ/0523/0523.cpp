#include<iostream>
using namespace std;
#define MAX 100

int n, nt, nh;
bool T[MAX*2+1], H[MAX*2+1];

int search( int c, bool A[MAX*2+1], int &size ){
  for ( int i = 1; i <= 2*n; i++ ){
      if ( !A[i] ) continue;
      if ( i > c ) {
	  A[i] = false;
	  size--;
	  return i;
      }
  }
  return -1;
}

void simulate(){
  int center = 0;
  nt = nh = n;

  int k;

  while( nt && nh ){
      k = search( center, T, nt );
      if ( k == -1 ) center = -1;
      else center = k;
      if ( nt == 0 ) break;
      k = search( center, H, nh );
      if ( k == -1 ) center = -1;
      else center = k;
  }

  cout << nh << endl;
  cout << nt << endl;
}

int main(){
    int x;
    while(1){
	cin >> n;
	if ( n == 0 ) break;

	for ( int i = 1; i <= 2*n; i++ ) T[i] = H[i] = false;

	for ( int i = 0; i < n; i++ ) {
	    cin >> x;
	    T[x] = true;
	}

	int j = 0;
	for ( int i = 1; i <= 2*n; i++ ){
	    if ( !T[i] ) H[i] = true;
	}
	simulate();
    }

    return 0;
}
