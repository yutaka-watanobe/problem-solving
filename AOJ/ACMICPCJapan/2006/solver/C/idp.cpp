// 5.5sec
#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

static const int dy[4] = {0, -1, 0, 1};
static const int dx[4] = {1, 0, -1, 0};

struct Point{int x, y;};

class Cube{
public:
  char C[3]; /* color */
  Cube(){ C[0] = 'W'; C[1] = 'R'; C[2] = 'B';}

  void setEmpty(){ C[0] = 'E';}

  void rotate(int d){
    if ( d % 2 == 0 ) swap(C[0], C[2]);
    else swap(C[0], C[1]);
  }
};

char target[3][3];
int tx, ty;

class Puzzle{
public:
  Cube cubes[3][3];
  bool equal[3][3];
  Point empty;
  Point preX;
  int MD, MD2;

  Puzzle(){
    for ( int y = 0; y < 3; y++ ){
      for ( int x = 0; x < 3; x++ ) cubes[y][x] = Cube();
    }
  }

  void setEmpty( int y, int x ){
    empty.x = x; empty.y = y;
    cubes[y][x].setEmpty();
  }

  void setMD(){
    MD = 0;
    MD2 = 0;
    preX.x = preX.y = -1;
    for ( int y = 0; y < 3; y++ ){
      for ( int x = 0; x < 3; x++ ){
	if ( cubes[y][x].C[0] != target[y][x] ){
	  equal[y][x] = false; MD++;
	} else {
	  equal[y][x] = true;
	}
      }
    }
  }

  void preDate( int y, int x ){
    if ( target[y][x] != cubes[y][x].C[0] ) MD--;
  }

  int getDist( int x1, int y1, int x2, int y2 ){
    //    return max(x1, x2)-min(x1,x2)+max(y1,y2)-min(y1,y2);
    return abs(x1-x2+y1-y2);
  }

  int getMD(){
    return MD-1;
    return max(MD-1, MD2-1);
  }

  void upDate( int y, int x ){
    if ( target[y][x] != cubes[y][x].C[0] )       MD++;
    return;

    if ( target[y][x] != cubes[y][x].C[0] ) {
      MD++;
      
      int tmp = getDist(y, x, empty.y, empty.x) + getDist(y, x, ty, tx);
      if ( MD2 < tmp ){
	MD2 = tmp;
	preX.y = y;
	preX.x = x;
      }
    } else {
      if ( preX.y == y && preX.x == x ) MD2 = 0;
    }
    /*
      if ( equal[y][x] && target[y][x] != cubes[y][x].C[0] ) {
      equal[y][x] = false; MD++;
    } else if ( !equal[y][x] && target[y][x] == cubes[y][x].C[0] ) {
      equal[y][x] = true;  MD--;
    }
    */
    return;
    if ( equal[y][x] ) return;
    int ny, nx;
    MD2 = 0;
    for ( int d = 0; d < 4; d++ ){
      ny = y + dy[d];
      nx = x + dx[d]; 
      if ( ny < 0 || nx < 0 || 3 <= nx || 3 <= ny ) continue;
      if ( equal[ny][nx] ) MD2++;
    }

  }
};


int ix, iy;
int limit;
Puzzle u;

bool isTarget( Puzzle p ){
  for ( int y = 0; y < 3; y++ ){
    for ( int x = 0; x < 3; x++ ){
      if ( target[y][x] != p.cubes[y][x].C[0] ) return false;
    }
  }
  return true;
}

int getDist( int x1, int y1, int x2, int y2 ){
  return max(x1, x2)-min(x1,x2)+max(y1,y2)-min(y1,y2);
}
int getMD( Puzzle p ){
  /*
  int dist = 0;
  for ( int y = 0; y < 3; y++ ){
    for ( int x = 0; x < 3; x++ ){
      if ( target[y][x] != p.cubes[y][x].C[0] ) dist++;
    }
    }*/
  return getDist( u.empty.y, u.empty.x, ty, tx);

  int mdist = 0;
  for ( int y = 0; y < 3; y++ ){
    for ( int x = 0; x < 3; x++ ){
      if ( target[y][x] != p.cubes[y][x].C[0] ) {
	mdist = max( mdist, getDist(x, y, p.empty.x, p.empty.y)+ getDist(x, y, tx, ty) );
      }
    }
  }
  return mdist;
  //  return max(dist-1, mdist+1);
}


int getMD2( Puzzle p ){
  int dist = 0;
  for ( int y = 0; y < 3; y++ ){
    for ( int x = 0; x < 3; x++ ){
      if ( target[y][x] != p.cubes[y][x].C[0] ) {
	dist++;
	/*
	int ny, nx;
	bool hasE = false;
	if ( p.empty.y == y && p.empty.x == x ) continue;
	if ( y % 2 == 0 && x % 2 != 0 ) continue;
	for ( int d = 0; d < 4; d++ ){
	  ny = y + dy[d];
	  nx = x + dx[d];
	  if ( p.empty.y == ny && p.empty.x == nx ) hasE = true;
	}
	if ( !hasE ) dist++;
	*/
      }
    }
  }

  int ny, nx;
  for ( int d = 0; d < 4; d++ ){
    ny = p.empty.y + dy[d];
    nx = p.empty.x + dx[d];
    if ( ny < 0 || nx < 0 || 3 <= nx || 3 <= ny ) continue;
    if ( target[ny][nx] != p.cubes[ny][nx].C[0] ) dist++;
  }


  return dist-1;
}

int getDist( int pre, int d ){
  if ( pre == 3 && d == 0 ) return 1;
  if ( pre == 0 && d == 3 ) return -1;
  return d - pre;
}

bool dfs( int depth, int pre, int seq ){

  //  if ( depth + max(u.MD-1, getMD(u)) > limit ) return false;
  // if ( depth + getMD(u)-1 > limit ) return false;

  //  if ( depth + u.MD-1 + u.MD2> limit ) return false;
  //  if ( depth + u.MD-1 > limit ) return false;
    if ( depth + u.getMD() > limit ) return false;
    //if ( depth + getMD2(u)-1 > limit ) return false;
  if ( u.MD == 0 ) return true;
  //  if ( seq > 12 ) return false;
  //  if ( isTarget(u) ) return true;

  int x, y, nx, ny;

  y = u.empty.y;
  x = u.empty.x;

  Puzzle tmp = u;

  for ( int d = 0; d < 4; d++ ){
    if ( pre != -1 && d == (pre+2)%4 ) continue;
    ny = y + dy[d];
    nx = x + dx[d];
    if ( ny < 0 || nx < 0 || 3 <= nx || 3 <= ny ) continue;
    
    u = tmp;

    u.preDate(ny, nx);
    u.preDate(y, x);

    u.cubes[ny][nx].rotate(d);
    u.cubes[y][x] = u.cubes[ny][nx];
    u.setEmpty(ny, nx);
    u.upDate(ny, nx);
    u.upDate(y, x);

    //    int nseq = seq;
    //    if ( getDist( pre, d ) == 1 ) nseq++;
    //    else nseq = 0;
    
    if ( dfs( depth+1, d, seq) ) return true;
    //    u.cubes[y][x].rotate((d+2)%4);
    //    u.cubes[ty][tx] = u.cubes[y][x];
    //    u.setEmpty(y, x);

  }

  return false;
}

void compute(){
  for ( limit = 0; limit <= 30; limit+=3 ){
    u = Puzzle();
    u.setEmpty(iy, ix);
    u.setMD();

    if ( dfs(  0, -1, 0 ) ) {
      if ( limit == 0 ) {cout << 0 << endl; return;}
      limit-=2;
      u = Puzzle();
      u.setEmpty(iy, ix);
      u.setMD();
      if ( dfs(0, -1, 0 ) ) {
	cout << limit << endl;
      } else {
	limit++;
	u = Puzzle();
	u.setEmpty(iy, ix);
	u.setMD();
	if ( dfs(0, -1, 0) ) cout << limit << endl;
	else cout << limit+1 << endl;
      }
      return;
    }
  }
  cout << -1 << endl;
}

void compute2(){
  u = Puzzle();
  u.setEmpty(iy, ix);
  u.setMD();
  for ( limit = 0; limit <= 30; limit+=2 ){
    u = Puzzle();
    u.setEmpty(iy, ix);
    u.setMD();

    if ( dfs(  0, -1, 0 ) ) {
      if ( limit == 0 ) {cout << 0 << endl; return;}
      limit--;
      u = Puzzle();
      u.setEmpty(iy, ix);
      u.setMD();
      if ( dfs(0, -1, 0 ) ) cout << limit << endl;
      else cout << limit+1 << endl;
      return;
    }
  }
  cout << -1 << endl;
}

bool input(){
  cin >> ix >> iy;
  if ( ix == 0 && iy == 0 ) return false;
  ix--; iy--;
  for ( int y = 0; y < 3; y++ ){
    for ( int x = 0; x < 3; x++ ){
      cin >> target[y][x];
      if ( target[y][x] == 'E' ){
	tx = x; ty = y;
      }
    }
  }

  return true;
}

main(){
  while(input()) compute();
}
