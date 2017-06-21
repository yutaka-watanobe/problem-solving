// binary search
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX 100000
using namespace std;
typedef unsigned long long ullong;

ullong target;
ullong T[ MAX ];

void init(){
  ullong adder = 1;
  T[1] = 1;
  for ( int i = 2; i <= MAX; i++ ){
    T[i] = T[i-1] + adder;
    adder++;
  }
}

void compute(){
  ullong *pos = ( upper_bound(T, T + MAX, target) - 1 );
  ullong left_most = *pos;
  ullong y = distance(T, pos);
  ullong x = 1;

  ullong dy = target - left_most;
  x = target - left_most + 1;

  y -= dy;

  cout << y << "/" << x << endl;

}

main(){
  init();

  while ( cin >> target ){
    compute();
  }
}
