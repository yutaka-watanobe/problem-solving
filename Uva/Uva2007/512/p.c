// @JUDGE_ID:  17051CA  512  C++
// @begin_of_source_code
/* Simulation - Spread Sheet */
/* そのままシミュレーションしたが、もっと良い解法があると思う */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>

int row, column;
int current_row, current_column;

vector<vector<int> > originalSheet;
vector<vector<int> > currentSheet;

void print(){
  for ( int i = 0; i < current_row; i++ ){
    for ( int j = 0; j < current_column; j++ ){
      printf("%3d", currentSheet[i][j] );
    }
    cout << endl;
  }
  cout << endl;
}

void doOperate( string &command ){
  vector<int> operand;
  int r1, c1, r2, c2;
  if ( command == "EX" ) {
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;
  } else {
    int k;
    cin >> k;
    operand.resize( k );
    for ( int i = 0; i < k; i++ ){
      cin >> operand[i];
      operand[i]--;
    }
    sort( operand.begin(), operand.end() );
  }

  int shift = 0;

  if ( command == "DR" ){
    for ( int op = 0; op < operand.size(); op++ ){
      currentSheet.erase( currentSheet.begin() + (operand[op] + shift ) );
      shift--;
      current_row--;
    }
  } else if ( command == "DC" ){
    for ( int op = 0; op < operand.size(); op++ ){
      for ( int i = 0; i < current_row; i++ ){
	currentSheet[i].erase( currentSheet[i].begin() + operand[op] + shift );
      }
      shift--;
      current_column--;
    }
  } else if ( command == "IC" ){
    for ( int op = 0; op < operand.size(); op++ ){
      for ( int i = 0; i < current_row; i++ ){
	currentSheet[i].insert( currentSheet[i].begin() + operand[op] + shift, -1 );
      }
      shift++;
      current_column++;
    }
  } else if ( command == "IR" ){
    for ( int op = 0; op < operand.size(); op++ ){
      currentSheet.insert( currentSheet.begin() + ( operand[op] + shift ), vector<int>(current_column, -1 ) );
      shift++;
      current_row++;
    }
  } else if ( command == "EX" ){
    int tmp = currentSheet[ r1 ][ c1 ];
    currentSheet[ r1 ][ c1 ] = currentSheet[ r2 ][ c2 ];
    currentSheet[ r2 ][ c2 ] = tmp;
  }
}

void search( int &target ){
  for ( int i = 0; i < current_row; i++ ){
    for ( int j = 0; j < current_column; j++ ){
      if ( currentSheet[i][j] == target ){
	cout << "moved to (" << i+1 << "," << j+1 << ")" << endl;
	return ;
      }
    }
  }
  cout << "GONE" << endl;
}


void work(){
  int noperation;
  cin >> noperation;

  string command;

  for ( int i = 0; i < noperation; i++ ){
    cin >> command;
    doOperate( command );
  }

  int nquery;
  cin >> nquery;

  int r, c;
  for ( int q = 0; q < nquery; q++ ){
    cin >> r >> c;
    cout << "Cell data in (" << r << "," << c << ") ";
    search( originalSheet[ r - 1 ][ c - 1 ] );
  }

}

bool read(){
  cin >> row >> column;
  if ( row == 0 && column == 0 ) return false;
  
  originalSheet.clear();
  currentSheet.clear();

  currentSheet.resize( row );
  for ( int i = 0; i < row; i++ ){
    currentSheet[i].resize( column );
  }
  int id = 0;

  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      currentSheet[i][j] = id++;
    }
  }

  current_row = row;
  current_column = column;
  originalSheet = currentSheet;
  return true;
}

main(){
  for ( int i = 1; read(); i++ ){
    if ( i > 1 ) cout << endl;
    cout << "Spreadsheet #" << i << endl;
    work();
  }
}

// @end_of_source_code


