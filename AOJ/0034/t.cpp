#include<iostream>
#include<stdio.h>
#include<cmath>
#define SIZE 11
#define EPS 0.000000001

using namespace std;

double station[SIZE], v1, v2;

void work(){
  double pos = 1.0 * v1 * station[SIZE-1] / (v1 + v2);

  //  printf("pos = %lf\n", pos);
  //  for ( int i = 0; i < SIZE; i++ ) printf("%.1lf ", station[i]);
  //  printf("\n");
  int cursor = 0;
  for ( cursor = 0; ; cursor++ ){
    if ( station[cursor] > pos ||
	 fabs( station[cursor] - pos ) < EPS ) break;
  }

  printf("%d\n", cursor);
}

bool read(){
  int len; char ch;
  if ( !(cin >> len) ) return false;
  station[0] = 0;
  station[1] = len;
  for ( int i = 2; i <= 10; i++ ){
    cin >> ch >> len;
    station[i] = station[i-1] + len;
  }
  cin >> ch >> v1 >> ch >> v2;
  return true;
}

main(){
  
  while( read() ) work();
}
