#include<iostream>
#include<stdlib.h>

main(){
  int row = 100;
  int column = 100;
  cout << row << " " << column;

  cout << endl;

  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      if ( rand()%2 == 0 || rand()%3 == 0) cout << "1 ";
      else cout << "0 ";
    }
    cout << endl;
  }

  cout << 0 << " " << 0 << endl;
}
