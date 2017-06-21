#include<stdio.h>
#include<iostream>
#include<stdlib.h>

main(){
  int n = 10;
  for ( int i = 0; i < n; i++ ){
    cout << rand() % 100 << " " << rand() % 100 << endl;
  }
}
