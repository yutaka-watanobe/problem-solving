// lower_bound + calculation
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX 100000
typedef long long llong;

int T[100000];
llong MT[100000];
int size;
int line, column;

void init(){
  size = 0;
  int width = 0;
  for ( llong p = 1; ; p+=2 ){
    T[size] = (int)p;
    MT[size] = p*p;
    size++;
    width++;
    if ( width*2 - 1 > MAX ) break;
  }
}

llong SZ, P;

void work(){
  line = SZ/2 + 1; column = SZ/2 + 1;

  int pos = distance( MT, lower_bound(MT, MT + size, P) );
  //cout << MT[pos] << endl;
  
  llong base = MT[pos];
  int width = T[pos];

  line += pos;
  column += pos;

  llong sbase;
  int dist;
  if ( base >= P && P > base - width + 1 ){
    sbase = base;
    dist = sbase - P;
    line -= dist;
  } else if ( base - width +1 >= P && P > base - 2*width + 2 ){
    sbase = base - width + 1;
    line = line - width +1;
    dist = sbase - P;
    column -= dist;
  } else if ( base - 2*width + 2 >= P && P > base - 3*width + 3 ){
    sbase = base -2*width + 2;
    line = line - width + 1;
    column = column - width + 1;
    dist = sbase - P;
    line += dist;
  } else if ( base - 3*width + 3 >= P ){
    sbase = base -3*width + 3;
    column = column - width + 1;
    dist = sbase - P;
    column += dist;
  } 



  printf("Line = %d, column = %d.\n", line, column);
}

bool read(){
  scanf("%ld %ld", &SZ, &P);
  if ( SZ == 0 && P == 0 ) return false;
  return true;
}

main(){
  init();

  while ( read() ){
    work();
  }
}
