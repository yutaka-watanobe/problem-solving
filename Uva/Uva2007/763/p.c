#include<iostream>
#define MAX 101
main(){
  
  int n = 102;
  unsigned long long F[ MAX ];

  F[1] = 1;
  F[2] = 1;

  for ( int  i = 3; i < n; i++ ){
    F[i] = F[i-2] + F[i-1];
    cout << i << " " << F[i] << endl;
  }
  

}
