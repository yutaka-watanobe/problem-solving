// @JUDGE_ID:  17051CA  10103  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<stl.h>

#define MAX 10
#define SPACE ' '

class Point{
 public:
  int x, y, z;
  Point(){}
  Point( int x, int y, int z ): x(x), y(y), z(z){}

  bool operator < ( const Point &p ) const {
    if ( x == p.x ){
      if ( y == p.y ){
	return z < p.z;
      } else return y < p.y;
    } else return x < p.x;
  }
};

class Block{
 public:
  char b[ MAX ][ MAX ][ MAX ];
  Block(){}
};

class KarpovichBlocks{
 public:
  int N;
  Block initial;
  map<vector<Point>, bool> used;

  void work(){
    Block nextBlock;

    if ( pick( initial, 'R', nextBlock ) ){
      if ( separate( nextBlock, 'G', 'B' ) ) cout << "RGB" << endl;
      else cout << "R" << endl;
      return;
    }

    if ( pick( initial, 'G', nextBlock ) ){
      if ( separate( nextBlock, 'R', 'B' ) ) cout << "RGB" << endl;
      else cout << "G" << endl;
      return;
    }

    if ( pick( initial, 'B', nextBlock ) ){
      if ( separate( nextBlock, 'R', 'G' ) ) cout << "RGB" << endl;
      else cout << "B" << endl;
      return;
    }
    
    cout << "NO" << endl;
  }


  bool separate( Block block, char ch1, char ch2 ){
    vector<Point> b1, b2;
    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < N; j++ ){
	for ( int k = 0; k < N; k++ ){
	  if ( block.b[i][j][k] == ch1 ) b1.push_back( Point(i, j, k ) );
	  else if ( block.b[i][j][k] == ch2 ) b2.push_back( Point(i, j, k ) );
	}
      }
    }

    char mch;
    vector<Point> mb;

    if ( b1.size() > b2.size() ){
      mch = ch2;
      mb = b2;
    } else {
      mch = ch1;
      mb = b1;
    }

    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < N; j++ ){
	for ( int k = 0; k < N; k++ ){
	  if ( block.b[i][j][k] == mch ) block.b[i][j][k] = SPACE;
	}
      }
    }

    used = map<vector<Point>, bool>();
    if ( recursive( block, mch, mb ) ) return true;
    else return false;
  }

  bool recursive( Block &block, char &ch, vector<Point> state ){

    static int dx[6] = {0, 0, 1, -1, 0, 0};
    static int dy[6] = {0, 0, 0, 0, -1, 1};
    static int dz[6] = {-1, 1, 0, 0, 0, 0};

    if ( state.size() == 0 ) return true;

    vector<Point> next;
    Point point;

    int x, y, z;
    for ( int r = 0; r < 6; r++ ){
      next.clear();
      for ( int i = 0; i < state.size(); i++ ){
	point = state[i];
	x = point.x + dx[r];
	y = point.y + dy[r];
	z = point.z + dz[r];
	if( x >= 0 && y >= 0 && z >= 0 && x < N && y < N && z < N ){
	  if ( !( block.b[x][y][z] == SPACE || block.b[x][y][z] == ch ) ) goto next;
	  next.push_back( Point( x, y, z ) );
	}
      }

      if ( !used[ next ] ){
	used[ next ] = true;
	if ( recursive( block, ch, next ) ) return true;
      }

    next:;
    }

    return false;
  }

  
  bool pick( Block block, char color, Block &next ){
    bool blocked;

    vector<Point> b;
    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < N; j++ ){
	for ( int k = 0; k < N; k++ ){
	  if ( block.b[i][j][k] == color ){
	    b.push_back( Point(i, j, k ) );
	    block.b[i][j][k] = SPACE;
	  }
	}
      }
    }

    used = map<vector<Point>, bool>();
    if ( !recursive( block, color, b ) ) return false;
    
    next = block;
    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < N; j++ ){
	for ( int k = 0; k < N; k++ ) {
	  if ( next.b[i][j][k] == color ) next.b[i][j][k] = SPACE;
	}
      }
    }

    return true;
  }

  bool read(){
    if ( !( cin >> N  ) ) return false;
    string line;

    initial = Block();
    char ch;
    int r, g, b;
    r = g = b = 0;
    for ( int k = 0; k < N; k++ ){
      for ( int i = 0; i < N; i++ ){
	cin >> line;
	for ( int j = 0; j < N; j++ ){
	  ch = line[j];
	  if ( ch == 'R' ) r++;
	  if ( ch == 'G' ) g++;
	  if ( ch == 'B' ) b++;
	  initial.b[i][j][k] = ch;
	}
      }
    }
    assert( N*N*N == r + g + b );
    assert( r != 0 && g != 0 && b != 0 );
    
    Block block = initial;

    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < N; j++ ){
	for ( int k = 0; k < N; k++ ){
	  if ( block.b[i][j][k] == 'R' ) dfs( block, 'R', r, i, j, k );
	  if ( block.b[i][j][k] == 'G' ) dfs( block, 'G', g, i, j, k  );
	  if ( block.b[i][j][k] == 'B' ) dfs( block, 'B', b, i, j, k  );
	}
      }
    }

    assert( r == 0 && g == 0 && b == 0 );
    return true;
  }

  void dfs( Block &block, char ch, int &cnt, int x, int y, int z ){
    static int dx[6] = {0, 0, 1, -1, 0, 0};
    static int dy[6] = {0, 0, 0, 0, -1, 1};
    static int dz[6] = {-1, 1, 0, 0, 0, 0};

    cnt--;
    block.b[x][y][z] = SPACE;
    int nx, ny, nz;

    for ( int r = 0; r < 6; r++ ){
      nx = x + dx[r];
      ny = y + dy[r];
      nz = z + dz[r];
      if ( nx >= 0 && ny >= 0 && nz >= 0 && nx < N && ny < N && nz < N ){
	if ( block.b[nx][ny][nz] == ch ) dfs( block, ch, cnt, nx, ny, nz );
      }
    }
  }

};

main(){
  KarpovichBlocks KB;

  while( KB.read() ){
    KB.work();
  }
}



// @end_of_source_code


