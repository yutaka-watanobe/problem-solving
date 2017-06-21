// @JUDGE_ID:  17051CA  441  C++
// @begin_of_source_code
/* Conbination --> Recusion */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int n;
int V[15];
int U[15];
int T[15];

int read(){
  cin >> n;
  if ( n == 0 ) return 0;

  for ( int i = 0; i < n; i++ ){
    cin >> V[i];
  }

  return 1;
}

void rec( int index, int cnt ){

  if ( cnt == 6 ){
    bool f = true;
    for ( int i = 0; i < n; i++ ){
      if ( T[i] ){
	if ( !f ) { cout << " ";}
	cout << V[i];
	f = false;
      }
    }
    cout << endl;
    return ;
  }

  if ( cnt + n - index < 6 ) return ;

  T[ index ] = 1;

  rec( index+1, cnt+1 );

  T[ index ] = 0;

  rec( index+1, cnt );

}


void work(){
  rec( 0, 0 );
}

main(){
  for ( int i = 0; read(); i++ ){
    if ( i ) cout << endl;
    work();
  }
}
// @end_of_source_code
