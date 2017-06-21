// @JUDGE_ID:  17051CA  10536  C++
// @begin_of_source_code
/* Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 65536
#define EMPTY 0
#define LOSE 1
#define WIN 2

int S[MAX];
int dx[16] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

int getIndex(vector<int> &v){
  int p = 1;
  int sum = 0;
  for ( int i = 0; i < 16; i++ ){
    if ( v[i] ) sum += p;
    p *= 2;
  }
  return sum;
}

void work(){
  int sum = 0;
  char ch;
  for ( int i = 0; i < 16; i++ ){
    cin >> ch;
    if ( ch == 'X' ) sum += dx[i];
  }

  if ( S[sum] == WIN ) cout << "WINNING" << endl;
  else if ( S[sum] == LOSE ) cout << "LOSING" << endl;
  else cout << "? " << endl;
}

vector<int> G;
int value, nX;
map<int, vector<int> > M; /* value -> array */
vector<pair<int, int> > NA; /* number of '.' -> array */

void rec( int index ){
  if ( index == 16 ){
    NA.push_back( make_pair(16-nX, value) );
    M[value] = G;
    return;
  }

  G[index] = 1;
  value += dx[index];
  nX++;
  rec( index + 1 );
  nX--;
  G[index] = 0;
  value -= dx[index];

  rec( index + 1 );
  
}

void check( int v ){
  vector<int> A;
  A = M[v];

  /* put 1 length */
  for ( int i = 0; i < 16; i++ ){
    if ( A[i] == 0 ){
      if ( S[ v + dx[i] ] == LOSE ) { S[v] = WIN; return; }
    }
  }

  /* put 2 length and 3 length*/
  for ( int i = 0; i < 4; i++ ){
    if ( A[i] == 0 && A[i+4] == 0 ){
      if( S[ v + (dx[i]+dx[i+4]) ] == LOSE) {
	S[v] = WIN; return;
      }
      if ( A[i+8] == 0 ){
	if ( S[ v + (dx[i]+dx[i+4]+dx[i+8]) ] == LOSE ){
	  S[v] = WIN; return;
	}
      }
    }
  }
  for ( int i = 12; i < 16; i++ ){
    if ( A[i] == 0 && A[i-4] == 0 ){
      if( S[ v + (dx[i]+dx[i-4]) ] == LOSE) {
	S[v] = WIN; return;
      }
      if ( A[i-8] == 0 ){
	if ( S[ v + (dx[i]+dx[i-4]+dx[i-8]) ] == LOSE ){
	  S[v] = WIN; return;
	}
      }
    }
  }

  for ( int i = 0; i <= 12; i+=4 ){
    if ( A[i] == 0 && A[i+1] == 0 ){
      if( S[ v + (dx[i]+dx[i+1]) ] == LOSE) {
	S[v] = WIN; return;
      }
      if ( A[i+2] == 0 ){
	if ( S[ v + (dx[i]+dx[i+1]+dx[i+2]) ] == LOSE ){
	  S[v] = WIN; return;
	}
      }
    }
  }
  for ( int i = 3; i <= 15; i+=4 ){
    if ( A[i] == 0 && A[i-1] == 0 ){
      if( S[ v + (dx[i]+dx[i-1]) ] == LOSE) {
	S[v] = WIN; return;
      }
      if ( A[i-2] == 0 ){
	if ( S[ v + (dx[i]+dx[i-1]+dx[i-2]) ] == LOSE ){
	  S[v] = WIN; return;
	}
      }
    }
  }




  S[v] = LOSE;

}

void init(){
  fill ( S, S + MAX, EMPTY );
  
  S[65535] = WIN;
  /* 65535 - 1X */
  for ( int i = 0; i < 16; i++ ){
    S[65535 - dx[i]] = LOSE;
  }

  /* 65535 - 2X */
  for ( int i = 0; i < 15; i++ ){
    for ( int j = i+1; j < 16; j++ ){
      S[65535 - (dx[i]+dx[j]) ] = WIN;
    }
  }

  G.resize( 16, 0 );
  value = 0;
  nX = 0;
  rec( 0 );

  sort ( NA.begin(), NA.end() );

  for ( int i = 0; i < NA.size(); i++ ){
    /*cout << NA[i].first << " " << NA[i].second << endl; */
    if ( 2 < NA[i].first ){
      check( NA[i].second );
    }
  }
}

main(){
  init();
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    work();
  }
}
// @end_of_source_code
