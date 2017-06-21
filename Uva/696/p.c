// @JUDGE_ID:  17051CA  696  C++
// @begin_of_source_code
/* Simple Calculation */
#include<stdio.h>
#include<iostream>

int row, column;

bool read(){
  cin >> row >> column;
  if ( row == 0 && column == 0 ) return false;
  return true;
}

int getNumber(){

  if ( row == 0 || column == 0 ) return 0;

  int Q, R, r;

  if ( row == 1 ) return column;
  else if ( column == 1 ) return row;
  else if ( row == 2 ){
    Q = ( column / 4 ) * ( 2 * row );
    R = 0;
    r = column % 4;
    if ( r == 1 ) R = row;
    else if ( r == 2 || r == 3 ) R = row * 2;
    return Q + R;
  } else if ( column == 2 ){
    Q = ( row / 4 ) * ( 2 * column );
    R = 0;
    r = row % 4;
    if ( r == 1 ) R = column;
    else if ( r == 2 || r == 3 ) R = column * 2;
    return Q + R;
  }

  int area = row * column;
  int number;

  if ( area % 2 == 0 ) number = area / 2;
  else number = area / 2 + 1;

  return number;
}

void work(){
  cout << getNumber() << " knights may be placed on a " << row << " row ";
  cout << column << " column board." << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
