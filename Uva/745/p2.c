// @JUDGE_ID:  17051CA  745  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>
typedef vector<string> Piece;
typedef vector<vector<char> > Frame;
/*
 * stringオブジェクトの後の空白、改行の削除
 * 要件: #include <string>
 */
void rtrim(string &s){
  int r;

  r = s.find_last_not_of(" \n\r");

  if(r==string::npos) s = "";
  else  s = s.substr(0, r+1);
}

vector<Piece> pieces;
vector<int> used;
Frame mainFrame;
Frame tmpFrame;
Frame rightFrame; /* answer */

int N, M;

void printFrame( Frame &frame ){
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      cout << frame[i][j];
    }
    cout << endl;
  }
}

void validate( Piece &piece ){
  int min_index = INT_MAX;
  int index;

  for ( int i = 0; i < piece.size(); i++ ){
    for ( int j = 0; j < piece[i].size(); j++ ){
      if ( piece[i][j] != ' ' ) {
	index = j;
	goto next;
      }
    }
  next:;
    if ( min_index > index ){
      min_index = index;
    }
  }

  for ( int i = 0; i < piece.size(); i++ ){
    for ( int k = 0; k < min_index; k++ ) piece[i].erase( piece[i].begin() + 0 );
  }

}

bool add( int p ){
  Piece piece = pieces[ p ];
  tmpFrame = mainFrame;

  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      int x, y;
      for ( int a = 0; a < piece.size(); a++ ){
	for ( int b = 0; b < piece[a].size(); b++ ){
	  x = i + a;
	  y = j + b;
	  if (  0 > x || 0 > y || x >= N || y >= N ) goto next;
	  if ( tmpFrame[x][y] != ' ' && piece[a][b] != ' ' ) goto next;
	  if ( piece[a][b] != ' ' ) tmpFrame[x][y] = piece[a][b];
	}
      }
      return true;
    next:;
      tmpFrame = mainFrame;
    }
  }
  return false;
}

bool rec( int index ){

  if ( index == M  ) return true;

  /* try */
  Frame originalFrame;
  originalFrame = mainFrame;

  for ( int p = 0; p < M; p++ ){
    if ( used[ p ] ) continue;
    mainFrame = originalFrame;
    
    if ( add( p ) ){
      used[ p ] = true;
      mainFrame = tmpFrame;
      if ( rec( index + 1 ) ) return true;
      mainFrame = originalFrame;
      used[ p ] = false;
    }
  }

  return false;
}

Frame rotate( Frame frame ){
  Frame tmp = frame;
  Frame rotated = frame;
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      rotated[i][j] = tmp[N - j - 1][i];
    }
  }
  return rotated;
}

void dicideRightFrame(){
  int max_value;
  
  Frame candidate[4];
  candidate[0] = mainFrame;
  candidate[1] = rotate( candidate[0] );
  candidate[2] = rotate( candidate[1] );
  candidate[3] = rotate( candidate[2] );
  bool diselection[4];
  fill( diselection, diselection + 4 , false );

  int sum[4];
  fill ( sum, sum + 4 , 0 );
  int ncandidate = 4;

  rightFrame = mainFrame;

  for ( int cursor = 0; cursor < N; cursor++ ){

    max_value = -1;
    for ( int c = 0; c < 4; c++ ){
      if ( diselection[c] ) continue;

      sum[c] = 0;
      for ( int i = 0; i < N; i++ ) sum[c] += (int)(candidate[c][i][cursor] - '0');
      if ( max_value < sum[c] ){
	max_value = sum[c];
      }

    }
    for ( int c = 0; c < 4; c++ ){
      if ( diselection[c] ) continue;
      if ( sum[c] < max_value ){
	ncandidate--;
	diselection[c] = true;
      }
    }
    if ( ncandidate == 1 ){
      for ( int c = 0; c < 4; c++ ){
	if ( sum[c] == max_value ) {
	  rightFrame = candidate[c];
	  return ;
	}
      }
    }

  }
}

void work(){
  mainFrame.clear();
  mainFrame.resize( N );
  for ( int i = 0; i < N; i++ ) mainFrame[i].resize( N, ' ' );
  tmpFrame.clear();
  tmpFrame.resize( N );
  for ( int i = 0; i < N; i++ ) tmpFrame[i].resize( N, ' ' );
  rightFrame.clear();
  rightFrame.resize( N );
  for ( int i = 0; i < N; i++ ) rightFrame[i].resize( N, ' ' );
  
  used.clear();
  used.resize( M, 0 );

  rec( 0 );
  
  dicideRightFrame();
  printFrame( rightFrame );
}

char getNumber( string &line ){
  for ( int i = 0; i < line.size(); i++ ){
    if ( isdigit( line[i] ) ) return line[i];
  }
}

bool containNumber( string &line ){
  for ( int i = 0; i < line.size(); i++ ){
    if ( isdigit( line[i] ) ) return true;
  }
  return false;
}

bool read(){
  string line;

  cin >> N;
  if ( N == 0 ) return false;

  cin >> M;

  getline( cin, line ); /* empty line */

  pieces.clear();
  pieces.resize( M );

  vector<string> input;

  while ( 1 ){
    getline( cin, line );
    if ( line == "#" ) break;
    rtrim( line );
    if ( containNumber( line ) ) input.push_back( line );
  }

  int cursor = -1;
  char pre = ' ';

  for ( int i = 0; i < input.size(); i++ ){
    char number = getNumber ( input[i] );
    if ( pre != number ){
      cursor++;
    }
    pieces[ cursor ].push_back( input[i] );
    pre = number;
  }

  for ( int i = 0; i < M; i++ ){
    validate( pieces[ i ] );
  }

  return true;
}

main(){
  for ( int i = 0; read(); i++ ){
    if ( i ) cout << endl;
    work();
  }
}

// @end_of_source_code


