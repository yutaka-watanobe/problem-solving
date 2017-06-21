// @JUDGE_ID:  17051CA  215  C++
// @begin_of_source_code
/* Shimulation - Spreadsheet */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>
#define EXPRESSION 0
#define VALUE 1

bool isDigit( string s ){
  for ( int i = 0; i < s.size(); i++ ){
    if ( !isdigit(s[i]) ) return false;
  }
  return true;
}

class Cell{
 public:
  int state, value;
  vector<string> C;
  vector<char> OP;

  Cell(){}
  Cell( string line ){

    if ( isDigit(line) || ( line[0] == '-' && isDigit( line.substr(1) ) ) ){
      state = VALUE;
      value = atoi( line.c_str() );
    }else{
      state = EXPRESSION;
      string str = "";
      for ( int i = 0; i < line.size(); i++ ){
	char ch = line[i];
	if ( ch == '+' || ch == '-' ){
	  C.push_back( str ); 
	  str = "";
	  OP.push_back( ch );
	}else if ( i == line.size() -1 ){
	  str += ch;
	  C.push_back( str );
	}else{
	  str += ch;
	}
      }
    }
  }

};

int row, col;
Cell S[20][10];

int read(){
  string line;

  cin >> row >> col;

  if ( row == 0 && col == 0 ) return 0;

  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < col; j++ ){
      cin >> line;
      S[i][j] = Cell( line );
    }
  }

  return 1;
}

int getRowIndex( string s ){
  return s[0] - 'A';
}

int getColIndex( string s ){
  return s[1] - '0';
}


void printSheet(){
  cout << " ";
  for ( int j = 0; j < col; j++ ) printf("%6d", j );
  cout << endl;
  for ( int i = 0; i < row; i++ ){
    cout << (char)(i + 'A');
    for ( int j = 0; j < col; j++ ){
      printf("%6d", S[i][j].value );
    }
    cout << endl;
  }
}

void printExpression(){
  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < col; j++ ){
      if ( S[i][j].state == EXPRESSION ){
	cout << (char)(i + 'A' ) << j << ": ";
	cout << S[i][j].C[0];
	for ( int k = 1; k < S[i][j].C.size(); k++ ){
	  cout << S[i][j].OP[k-1] << S[i][j].C[k];
	}
	cout << endl;
      }
    }
  }
}

bool calculate( int pi, int pj ){
  vector<int> V;
  vector<string> C = S[pi][pj].C;
  vector<char> OP = S[pi][pj].OP;

  for ( int i = 0; i < C.size(); i++ ){
    string s = C[i];
    if ( isDigit( s ) ){
      V.push_back ( atoi( s.c_str() ) ) ;
    }else {
      int r = getRowIndex ( s );
      int c = getColIndex ( s );
      if ( S[ r ][ c ].state == VALUE ){
	V.push_back( S[r][c].value);
      }else{
	return false;
      }
    }
  }

  /* able */
  int value = V[0];
  for ( int i = 1; i < V.size(); i++ ){
    if ( OP[i-1] == '+' ) value += V[i];
    else if ( OP[i-1] == '-' ) value -= V[i];
  }
  S[pi][pj].value = value;
  S[pi][pj].state = VALUE;

  return true;
}

void work(){

  bool change;

  while ( 1 ){
    change = false;
    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < col; j++ ){
	if ( S[i][j].state == EXPRESSION ){
	  if ( calculate( i, j ) ) change = true;
	}
      }
    }

    if ( !change ) break;
  }

  /* check */
  bool table = true;
  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < col; j++ ){
      if ( S[i][j].state == EXPRESSION ) table = false;
    }
  }

  if ( table ) printSheet();
  else printExpression();

}

main(){
  for ( int i = 0; read(); i++ ){
    work();
    cout << endl;
  }
}
// @end_of_source_code
