// @JUDGE_ID:  17051CA  10368  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<stdlib.h>

int read();
void work();

int n, k;

int read(){
  cin >> n >> k;
  if( n==0 && k==0 ) return 0;
  return 1;
}

void work(){
  int x1, x2, n1, n2;
  int player = 0;

  n1 = max(n, k);
  n2 = min(n, k);

  while(1){
    player++;
    x1 = n1;
    x2 = n2;
    
    if( x1/x2 > 1 ) goto next;

    x1 = x1%x2;

    n1 = max(x1, x2);
    n2 = min(x1, x2);
    
    if( n1 == 0 || n2 == 0 ) {
      goto next;
    }

  }

 next:;
  if( player%2 == 0 ) cout << "Ollie wins" << endl;
  else cout << "Stan wins" << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
