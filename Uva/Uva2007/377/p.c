// @JUDGE_ID:  17051CA  377  C++
// @begin_of_source_code
/* Simulation - Calculation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int n;
int num1[8], num2[8];

int convert( char c ){
  if ( c == 'V' ) return 0;
  else if ( c == 'U' ) return 1;
  else if ( c == 'C' ) return 2;
  else if ( c == 'D' ) return 3;
}

void shiftRight(){
  for ( int i = 0; i < 7; i++ ){
    num2[i] = num2[i+1];
  }
  num2[8] = 0;
}

void shiftLeft(){
  for ( int i = 7; i >= 1; i-- ){
    num2[i] = num2[i-1];
  }
  num2[0] = 0;
}

void add(){
  int value;
  int carry = 0;
  int sum[8];
  fill ( sum, sum+8, 0 );

  for ( int i = 0; i < 8; i++ ){
    value = num1[i] + num2[i] + carry;
    if ( value >= 4 ) { value -= 4; carry = 1; }
    else carry = 0;
    sum[i] = value;
  }

  num2 = sum;
}

void work(){
  char op;
  
  fill ( num1, num1+8, 0 );
  fill ( num2, num2+8, 0 );
  char c;
  for ( int i = 4; i >= 0; i-- ){
    cin >> c;
    num1[i] = convert( c );
  }
  for ( int i = 4; i >= 0; i-- ){
    cin >> c;
    num2[i] = convert( c );
  }

  for ( int i = 0; i < 3; i++ ){
    cin >> op;
    if ( op == 'A' ){
      add();
    }else if ( op == 'R' ) {
      shiftRight();
    }else if ( op == 'L' ){
      shiftLeft();
    }
  }

  bool same = true;
  for ( int i = 0; i < 8; i++ ){
    cin >> c;
    if ( convert(c) != num2[7-i] ) same = false;
  }
  
  if ( same ) cout << "YES" << endl;
  else cout << "NO" << endl;
  
}

main(){
  int t;
  cin >> t;
  cout << "COWCULATIONS OUTPUT" << endl;
  for ( int i = 0; i < t; i++ ){
    work();
  }
  cout << "END OF OUTPUT" << endl;
}
// @end_of_source_code
