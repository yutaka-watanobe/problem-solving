#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


#define N 1000033
#define D 887
int n, A[N], T[N];

int hash( int x ){
  int h = x % N;
  if ( T[h] == -1 ){
    T[h] = x;
    return h;
  }

  while( T[h] != x ){
    h = (h+D)%N;
  }
  return h;
}

int main(){
  int x, a;
  while( cin >> n && n ){
    for ( int i = 0; i < N; i++ ) {
      T[i] = -1;
      A[i] = 0;
    }

    int maxv = 0;
    int maxi;
    for ( int i = 0; i < n;  i++ ) {
      scanf("%d", &x);
      a = hash(x);
      A[a]++;
      if ( maxv < A[a] ){
	maxv = A[a];
	maxi = a;
      }
    }

    if ( maxv > n/2 ) cout << maxi << endl;
    else cout << "NO COLOR" << endl;


  }
}
