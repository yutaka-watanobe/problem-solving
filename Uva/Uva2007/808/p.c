// @JUDGE_ID:  17051CA  808  C++
// @begin_of_source_code
/* Grid ( Bee ) shortest distance */
/* cordinate transration */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<cmath>
#define MAX 10001

int a, b;
int X[ MAX ];
int Y[ MAX ];

bool read(){
  cin >> a >> b;
  if ( a == 0 && b == 0 ) return false;
  return true;
}

void init(){
  
  int len = 1;
  
  X[1] = Y[1] = 0;
  X[2] = 0;
  Y[2] = -1;


  int pos = 3;
  while ( 1 ){
    
    /* upper left */
    for ( int i = 0; i < len; i++ ){
      if ( pos >= MAX ) goto next;
      X[pos] = X[pos-1] - 1;
      Y[pos] = Y[pos-1];
      pos++;
    }

    /* up */
    for ( int i = 0; i < len; i++ ){
      if ( pos >= MAX ) goto next;
      X[pos] = X[pos-1];
      Y[pos] = Y[pos-1] + 1;
      pos++;
    }

    /* upper right */
    for ( int i = 0; i < len; i++ ){
      if ( pos >= MAX ) goto next;
      X[pos] = X[pos-1] + 1;
      Y[pos] = Y[pos-1] + 1;
      pos++;
    }

    /* lower right */
    for ( int i = 0; i < len; i++ ){
      if ( pos >= MAX ) goto next;
      X[pos] = X[pos-1] + 1;
      Y[pos] = Y[pos-1];
      pos++;
    }

    /* low */
    for ( int i = 0; i < len + 1; i++ ){
      if ( pos >= MAX ) goto next;
      X[pos] = X[pos-1];
      Y[pos] = Y[pos-1] - 1;
      pos++;
    }

    /* lower left*/
    for ( int i = 0; i < len; i++ ){
      if ( pos >= MAX ) goto next;
      X[pos] = X[pos-1] - 1;
      Y[pos] = Y[pos-1] - 1;
      pos++;
    }
    len++;
  }

  next:;
}

void work(){
  int cost;

  int deffX = ( X[a] - X[b] );
  int deffY = ( Y[a] - Y[b] );

  if ( ( 0 <= deffX  && deffY <= 0 ) || ( 0 <= deffY && deffX <= 0 ) ){
    cost = abs( deffX ) + abs( deffY );
  } else {
    cost = max( abs( deffX ), abs ( deffY ) );
  }

  cout << "The distance between cells " << a << " and " << b;
  cout << " is " << cost << "." << endl;
}

main(){
  init();
  while ( read() ){
    work();
  }
}
// @end_of_source_code
