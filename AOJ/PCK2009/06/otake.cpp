#include<iostream>
#include<map>
#include<cstdlib>
#include<algorithm>
#include<string>
using namespace std;

int h, w;
char data[30][30];
char next[30][30];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

map<char, int> ctoi;
string itoc = "ENWS";

void copy(){
  for ( int i = 0; i < h; i++ ){
    for ( int j = 0; j < w; j++ ){
      data[i][j] = next[i][j];
    }
  }
}

main(){
  ctoi['E'] = 0;
  ctoi['N'] = 1;
  ctoi['W'] = 2;
  ctoi['S'] = 3;

  int tc = 1;
  while( cin >> w >> h && (h || w) ){
    int p= 0;
    for ( int i = 0; i < h; i++ ){
      for ( int j = 0; j < w; j++ ){
	cin >> next[i][j];
	if ( next[i][j] == 'E' ||
	     next[i][j] == 'N' ||
	     next[i][j] == 'W' ||
	     next[i][j] == 'S') ++p;
      }
    }

    if ( tc == 27 ){
      for ( int i = 0; i < h; i++ ){
	for ( int j = 0; j < w; j++ ){
	  cout << next[i][j];
	}
	cout << endl;
      }
    }
    tc++;

    copy();
    int t;
    for ( t = 0; t<=180; ++t ){
      if ( p == 0 ) break;

      for ( int i = 0; i < h; i++ ){
	for ( int j = 0; j < w; j++ ){
	  if ( data[i][j]== '#' ||
	       data[i][j] == '.'||
	       data[i][j] == 'X' ) continue;
	  for( int k = 0; k <4; k++ ){
	    int d = (ctoi[data[i][j]] + 3 + k)%4;
	    int ty = i + dy[d];
	    int tx = j + dx[d];
	    if ( ty < 0 || ty >= h ) continue;
	    if ( tx < 0 || tx >= w ) continue;
	    if ( data[ty][tx] == '.' || data[ty][tx] == 'X' ){
	      data[i][j] = itoc[d];
	      break;
	    }
	  }
	}
      }
      for ( int i = 0; i < h; i++ ){
	for ( int  j = 0; j < w; j++ ){
	  if ( data[i][j] == '.' || data[i][j] == 'X' ){
	    for ( int k = 0; k < 4; k++ ){
	      int ty = i + dy[k];
	      int tx = j + dx[k];
	      if ( ty < 0 || ty >= h ) continue;
	      if ( tx < 0 || tx >= w ) continue;
	      if ( data[ty][tx] == '#' ||
		   data[ty][tx] == '.' ||
		   data[ty][tx] == 'X' ) continue;
	      if ( abs(ctoi[data[ty][tx]] - k )  == 2 ){
		if ( data[i][j] == 'X' ) --p;
		else next[i][j] = data[ty][tx];
		next[ty][tx] = '.';
		break;
	      }
	    }
	  }
	}
      }
      copy();
    }
    if ( t > 180 ) cout << "NA" << endl;
    else cout << t << endl;
  }
  return 0;
}
