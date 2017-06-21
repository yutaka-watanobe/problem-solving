// @JUDGE_ID:  17051CA  2287  C++
// @begin_of_source_code
/* Simple Calculation ( Judgement ) */
#include<stdio.h>
#include<iostream>
#include<string>
int n;
string input, current, tmp;

int read(){
  cin >> input;
  if ( cin.eof() ) return 0;
  n = input.size();
  tmp.resize( n );
  return 1;
}

bool check( string &line ){
  for ( int s = 0; s < n; s++ ){
    int i, j;
    for ( i = s, j = 0; j < n; i++, j++ ){
      if ( line[ i%n ] != input[ j ] ) goto next;
    }
    return true;
  next:;
  }
  return false;
}

bool add_check(){

  int carry = 0;
  int op1, op2, v, value;

  for ( int i = n-1; i >= 0; i-- ){
    op1 = current[ i ] - '0';
    op2 = input[ i ] - '0';
    v = op1 + op2;
    value = v + carry;
    tmp[ i ] = ( value % 10 ) + '0';
    carry = value / 10;
  }

  current = tmp;
  if ( carry ) return false;
  return check( current );
}

void work(){
  bool cyclic = true;

  current = input;

  for ( int i = 1; i < n; i++ ){
    if ( !add_check() ){
      cyclic = false;
      break;
    }
  }

  cout << input << " is ";
  if ( cyclic ){
    cout << "cyclic" << endl;
  } else {
    cout << "not cyclic" << endl;
  }
}

main(){
  while ( read() ) {
    work();
  }
}
// @end_of_source_code
