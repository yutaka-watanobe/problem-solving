// @JUDGE_ID:  17051CA  10346  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream.h>

typedef unsigned long long  llong;

int read();
void work();
void smoke();
llong n, k;
llong sum;

int read(){
  cin >> n;
  if( cin.eof() ) return 0;
  cin >> k;
  
  return 1;
}


void work(){
  if( n < 0 ) n = 0;

  if( k < 0 ) k = 0;


  if( n <= 0 ){
    cout << "0" << endl;
    return;
  }
  
  if( k <= 1 ){
    cout << n << endl;
    return ;
  }

  if ( n == k ){
    cout << n+1 << endl;
    return ;
  }

  if( n < k ) {
    cout << n << endl;
    return;
  }

  sum = 0;
  /*sum = n + n/k + n%k;*/
  llong num;
  while( n != 0 ){
    num = n/k;
    sum += num*k;
    n = n -  num*k ;
    n = n + num;
    if( n< k ) {
      sum += n;
      break;
    }
  }
  cout << sum << endl;
}

main(){
  for( int i=0; read(); i++){
    if( i!=0  ) cout << endl;
    work();
  }
}
// @end_of_source_code
