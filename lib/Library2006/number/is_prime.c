#include<stdio.h>
#include<iostream>

/**
 * 遅いがシンプル
 */
bool is_prime(int k){
  if(k<2) return false;
  else if(k==2) return true;
  if(k%2 == 0) return false;
  for(int i=3; i*i <= k; i+=2) if(k%i==0) return false;
  return true;
}


main(){
  for(int i=0; i<30; i++){
    cout << i << " ";
    if(is_prime(i)) cout << "prime";
    else cout << "not";
    cout << endl;
  }
}
