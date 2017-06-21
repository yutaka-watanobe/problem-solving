#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

class Solver{
 public:
  vector<vector<char> > G;
  int sx, sy;
  string command;

  void move( int r ){
    int tx, ty;
    
    tx = sx + dx[r];
    ty = sy + dy[r];

    if (!( 0 <= tx && 0 <= ty && tx < 3 && ty < 3 )) assert( false );

    G[sx][sy] = G[tx][ty];
    G[tx][ty] = 'x';
    sx = tx;
    sy = ty;
  }


  void work(){

    cin >> command;
       for ( int i = 0; i < 3; i++ ){
      for (int j = 0; j < 3; j++ ){
	cout << G[i][j] << " ";
      }
      cout << endl;
    }
    cout << command << endl;

    for ( int i = 0; i < command.size(); i++ ){
      if ( command[i] == 'r' ) move( 0 );
      else if ( command[i] == 'u' ) move( 1 );
      else if ( command[i] == 'l' ) move( 2 );
      else if ( command[i] == 'd' ) move( 3 );
    }


    for ( int i = 0; i < 3; i++ ){
      for (int j = 0; j < 3; j++ ){
	cout << G[i][j] << " ";
      }
      cout << endl;
    }
  }

  void read(){
    G.clear();
    G.resize( 3 );
    
    for ( int i = 0; i < 3; i++ ) G[i].resize( 3 );

    for ( int i = 0; i < 3; i++ ){
      for ( int j = 0; j < 3; j++ ){
	char ch;
	cin >> ch;
	if ( ch == 'x' ) {
	  sx = i;
	  sy = j;
	}
	G[i][j] = ch;
      }
    }
  }
};

main(){
  Solver S;
  S.read();
  S.work();
}
