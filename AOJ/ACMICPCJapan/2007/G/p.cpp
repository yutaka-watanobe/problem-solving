#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<cassert>
using namespace std;
#define MAX 17

class Ghosts{
 public:
  int n, pos[3];

  Ghosts(){}
  Ghosts( int n ): n(n){}

  bool operator < ( const Ghosts &g ) const{
    for ( int i = 0; i < n; i++ ){
      if ( pos[i] == g.pos[i] ) continue;
      return pos[i] < g.pos[i];
    }
    return false;
  }
  
  bool operator == ( const Ghosts &g ) const{
    for ( int i = 0; i < n; i++ ){
      if ( pos[i] != g.pos[i] ) return false;
    }
    return true;
  }
};

int n, w, h;
Ghosts initial, goal;
char G[MAX][MAX];

bool check( Ghosts s, Ghosts t ){
  for ( int i = 0; i < n-1; i++ ){
    for ( int j = i+1; j < n; j++ ){
      if ( t.pos[i] == t.pos[j] ) return false;
      if ( t.pos[i] == s.pos[j] && t.pos[j] == s.pos[i] ) return false;
    }
  }
  return true;
}

void move(queue<Ghosts> &Q, map<Ghosts, int> &D, map<Ghosts, bool> &V, int g, Ghosts v, Ghosts source ){
  if ( g == n ){
    if ( check(source, v) ) {
      if ( !V[v] ){
	V[v] = true;
	D[v] = D[source] + 1;
	Q.push(v);
      }
    }
    return;
  }
  
  static const int di[5] = {0, 0, -1, 0, 1};
  static const int dj[5] = {0, 1, 0, -1, 0};

  int ni, nj;
  Ghosts nv;
  for ( int dir = 0; dir < 5; dir++ ){
    ni = v.pos[g]/w + di[dir];
    nj = v.pos[g]%w + dj[dir];
    if ( G[ni][nj] == ' ' ){
      nv = v;
      nv.pos[g] = ni*w + nj;
      move( Q, D, V, g+1, nv, source );
    }
  }
}

int bfs(){
  map<Ghosts, int> D;
  map<Ghosts, bool> V;
  queue<Ghosts> Q;

  Q.push(initial);
  D[initial] = 0;
  V[initial] = true;

  Ghosts u;
  while(!Q.empty()){
    u = Q.front(); Q.pop();
    if ( u == goal ) return D[u];
    move(Q, D, V, 0, u, u);
  }

  return INT_MAX;
}

void input(){
  string line;
  char ch;
  getline( cin, line );

  initial = Ghosts(n);
  goal = Ghosts(n);
  for ( int i = 0; i < h; i++ ){
    getline( cin, line );
    assert(line.size() == w );
    for ( int j = 0; j < line.size(); j++ ){
      ch = line[j];
      if ( 'a' <= ch && ch <= 'c' ){
	initial.pos[ch - 'a'] = i*w + j;
	G[i][j] = ' ';
      } else if ( 'A' <= ch && ch <= 'C' ){
	goal.pos[ch - 'A'] = i*w + j;
	G[i][j] = ' ';
      } else {
	G[i][j] = ch;
      }
    }
  }
}

main(){
  while( cin >> w >> h >> n, w || h || n ){
    input();
    cout << bfs() << endl;
  }
}
