#include<iostream>
using namespace std;
#define MAX 101

main(){
  int T[MAX];

  for ( int i = 0; i < MAX; i++ ) T[i] = 0;
  int x;
  while(  cin >>x ) T[x]++;

  int maxv = 0;
  for ( int i = 0; i < MAX; i++ ){
    if ( maxv < T[i] ){
      maxv = T[i];
    }
  }

  for ( int i = 0; i < MAX; i++ ){
    if ( maxv == T[i] ) cout <<  i << endl;
  }
}
