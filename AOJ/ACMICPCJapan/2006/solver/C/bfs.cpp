// 3m41sec
#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct Point{int x, y;};

class Puzzle{
public:
  int value;
  Point empty;

  Puzzle(){
    value = 0;
    for ( int p = 0; p < 9; p++ ) value += (1<<(p*3));
  }

  void setEmpty( int y, int x ){
    empty.x = x; empty.y = y;
    value -= (value & (7<<((y*3+x)*3)));
  }

  int convert(int cube, int d){
    if ( cube % 2 != 0 ){
      if ( d % 2 == 0 ){ cube--; } else { cube++; }
    } else {
      if ( d % 2 == 0 ){ cube++; } else { cube--; }
    }
    if ( cube == 0 ) cube = 6;
    if ( cube == 7 ) cube = 1;
    return cube;
  }

  void move(int source, int target, int d){
    int cube = (value & (7<<(source*3)));
    setEmpty(source/3, source%3);
    cube = convert(cube>>(source*3), d);
    int tcube = (value & (7<<(target*3)));
    value -= tcube;
    value += (cube<<(target*3));
  }

  bool check( char ch, int p ){
    int cube = (value & (7<<(p*3)));
    cube = (cube>>(p*3));
    if ( ch == 'W' ) return (cube == 1 || cube == 4);
    else if ( ch == 'R' ) return (cube == 2 || cube == 5);
    else if ( ch == 'B' ) return (cube == 3 || cube == 6);
    else if ( ch == 'E' ) return (cube == 0);
  }
};

char target[3][3];
int ix, iy;

bool isTarget( Puzzle p ){
  for ( int y = 0; y < 3; y++ ){
    for ( int x = 0; x < 3; x++ ){
      if ( !p.check(target[y][x], y*3+x) ) return false;
    }
  }
  return true;
}

int bfs(){
  queue<Puzzle> Q;
  map<int, int> D;

  Puzzle source = Puzzle();
  source.setEmpty(iy, ix);

  Q.push(source);
  D[source.value] = 0;

  Puzzle u, v;
  static const int dy[4] = {0, -1, 0, 1};
  static const int dx[4] = {1, 0, -1, 0};

  int x, y, tx, ty;

  while(!Q.empty() ){
    u = Q.front(); Q.pop();
    if ( D[u.value] > 30 ) return D[u.value];
    if ( isTarget(u) ) return D[u.value];
    y = u.empty.y;
    x = u.empty.x;

    for ( int d = 0; d < 4; d++ ){
      ty = y + dy[d];
      tx = x + dx[d];
      if ( ty < 0 || tx < 0 || 3 <= tx || 3 <= ty ) continue;
      v = u;

      v.move(ty*3+tx, y*3+x, d);

      if ( D.find(v.value) == D.end() ){
	D[v.value] = D[u.value] + 1;
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
