#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 1000000

int getNumber(){
  int n = 0;
  char ch;
  while(1){
    ch = getchar();
    if ( ch == ' ' || ch == '\n' ) break;
    n *= 10; n += ch-'0';
  }
  return n;
}

int n, A[MAX];
int main(){
  while( 1 ){
    n = getNumber();
    //scanf("%d", &n);
    if ( n == 0 ) break;

    for ( int i = 0; i < n;  i++ ) A[i] = getNumber();

    sort(A, A + n);

    int maxc = 0;
    int maxv = A[0];
    int pre = A[0];
    int cnt = 1;

    for ( int i = 1; i < n; i++ ){
      if ( pre == A[i] ){
	cnt++;
      } else {
	if ( maxc < cnt ){
	  maxc = cnt;
	  maxv = pre;
	}
	cnt = 1;
      }
      pre = A[i];
    }
    if ( maxc < cnt ){
      maxc = cnt;
      maxv = pre;
    }

    if ( maxc > n/2 ) cout << maxv << endl;
    else cout << "NO COLOR" << endl;


  }
}
