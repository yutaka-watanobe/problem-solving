#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct Point{int x, y;};

class Cube{
public:
  char C[3]; /* color */
  Cube(){
    C[0] = 'W'; C[1] = 'R'; C[2] = 'B';
  }

  void setEmpty(){
    for ( int i = 0; i < 3; i++ ) C[i] = 'E';
  }

  void rotate(int d){
    int tmp;
    if ( d % 2 == 0 ){
      tmp = C[0]; C[0] = C[2]; C[2] = tmp;
    } else {
      tmp = C[0]; C[0] = C[1]; C[1] = tmp;
    }
  }

  bool operator == ( const Cube &c ) const{
    return ( C[0] == c.C[0] && 
	     C[1] == c.C[1] );//&&
	     //	     C[2] == c.C[2] );
  }

  bool operator < ( const Cube &c ) const{
    for ( int i = 0; i < 2; i++ ){
      if ( C[i] == c.C[i] ) continue;
      return C[i] < c.C[i];
    }
  }
};

class Puzzle{
public:
  Cube cubes[3][3];
  Point empty;

  Puzzle(){
    for ( int y = 0; y < 3; y++ ){
      for ( int x = 0; x < 3; x++ ){
	cubes[y][x] = Cube();
      }
    }
  }

  void setEmpty( int y, int x ){
    empty.x = x; empty.y = y;
    cubes[y][x].setEmpty();
  }

  bool operator < ( const Puzzle &p ) const{
    for ( int y = 0; y < 3; y++ ){
      for ( int x = 0; x < 3; x++ ){
	if ( cubes[y][x] == p.cubes[y][x] ) continue;
	return cubes[y][x] < p.cubes[y][x];
      }
    }
    return false;
  }
};

char target[3][3];
int ix, iy;

bool isTarget( Puzzle p ){
  for ( int y = 0; y < 3; y++ ){
    for ( int x = 0; x < 3; x++ ){
      if ( target[y][x] != p.cubes[y][x].C[0] ) return false;
    }
  }
  return true;
}

int bfs(){
  queue<Puzzle> Q;
  map<Puzzle, int> D;

  Puzzle source = Puzzle();
  source.setEmpty(iy, ix);
  Q.push(source);
  D[source] = 0;

  Puzzle u, v;
  static const int dy[4] = {0, -1, 0, 1};
  static const int dx[4] = {1, 0, -1, 0};

  int x, y, tx, ty;

  while(!Q.empty() ){
    u = Q.front(); Q.pop();
    if ( D[u] > 30 ) return D[u];
    if ( isTarget(u) ) return D[u];
    y = u.empty.y;
    x = u.empty.x;

    for ( int d = 0; d < 4; d++ ){
      ty = y + dy[d];
      tx = x + dx[d];
      if ( ty < 0 || tx < 0 || 3 <= tx || 3 <= ty ) continue;
      v = u;

      v.cubes[ty][tx].rotate(d);
      v.cubes[y][x] = v.cubes[ty][tx];
      v.setEmpty(ty, tx);

      if ( D.find(v) == D.end() ){
	D[v] = D[u] + 1;
	Q.push(v);
      }
    }
  }

  return INT_MAX;
}

void compute(){
  int cost = bfs();
  if ( cost > 30 ) cout << -1 << endl;
  else cout << cost << endl;
}

bool input(){
  cin >> ix >> iy;
  if ( ix == 0 && iy == 0 ) return false;
  ix--; iy--;
  for ( int y = 0; y < 3; y++ ){
    for ( int x = 0; x < 3; x++ ){
      cin >> target[y][x];
    }
  }

  return true;
}

main(){
  while(input()) compute();
}
