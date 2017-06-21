#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define MAX 1000
using namespace std;

int gcd(int a, int b){
  if ( b == 0 ) return a;
  return gcd(b, a%b);
}

int buffer[MAX];
int n, t;
bool T[MAX+1][MAX+1];

void rec(int pos, int v, int sum ){
  int r = t - pos - 1;
  if ( r*v + sum > n ) return; 

  if ( pos == t ){
    if ( sum == n ){
      for ( int i = 0; i < t; i++ ) {
	if ( i ) printf(" ");
	printf("%d", buffer[i]);
      }
      printf("\n");
    }
    return;
  }

  for ( int i = v; i <= n; i++ ){
    bool p = true;
    for ( int j = pos-1; j >= 0; j-- ) {
      if ( !T[buffer[j]][i] ) { p = false; break;}
      if ( buffer[j] == 1 ) break;
    }
    if ( !p ) continue;
    if (  i + sum > n ) continue;
    buffer[pos] = i;
    rec(pos+1, i, sum+i);
  }

}

void compute(){
   cin >> n >> t;
  
  for ( int i = 1;  i <= n; i++ ){
    buffer[0] = i;
    rec(1, i, i);
  }


}

int main(void){

  for ( int i = 1; i <= MAX; i++ ){
    for ( int j = 1; j <= MAX; j++ ){
      T[i][j] = (gcd(i, j) == 1);
    }
  }
  
    int tcase; cin >> tcase;
    for ( int i = 1; i <= tcase; i++ ) {
      printf("Case %d:\n", i);
      compute();
    }

    return 0;
}
