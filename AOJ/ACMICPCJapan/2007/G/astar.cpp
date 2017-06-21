#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<cassert>
#include<algorithm>
#include<climits>
using namespace std;
#define MAX 16

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

class State{
public:
  Ghosts ghosts;
  int cost, md;
  State(){}
  State( Ghosts g, int c, int d ): cost(c), md(d), ghosts(g){};

  bool operator < ( const State &s ) const {
    if ( (cost + md )== (s.cost + s.md) )
      return cost > s.cost;
    else return (cost + md) > (s.cost + s.md);
  }
};

int n, w, h;
Ghosts initial, goal;
char G[MAX][MAX];
int MDT[MAX][MAX][3];

bool check( Ghosts s, Ghosts t ){
  for ( int i = 0; i < n-1; i++ ){
    for ( int j = i+1; j < n; j++ ){
      if ( t.pos[i] == t.pos[j] ) return false;
      if ( t.pos[i] == s.pos[j] && t.pos[j] == s.pos[i] ) return false;
    }
  }
  return true;
}

int mdbfs(int k){
  queue<int> Q;
  int s = goal.pos[k];

  MDT[s/w][s%w][k] = 0;
  Q.push(s);
  int u, v;
  while(!Q.empty()){
    u = Q.front(); Q.pop();

    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};

    int ni, nj;
    for ( int r = 0; r < 4; r++ ){
      ni = u/w + di[r];
      nj = u%w + dj[r];
      if ( G[ni][nj] == ' ' && MDT[ni][nj][k] == INT_MAX ){
	MDT[ni][nj][k] = MDT[u/w][u%w][k] + 1;
	Q.push(ni*w + nj);
      }
    }
  }
}

int getMD(Ghosts v){
  int md = 0;
  for ( int i = 0; i < n; i++ ){
    md = max(md, MDT[v.pos[i]/w][v.pos[i]%w][i] );
  }
  return md;
}

void move(priority_queue<State> &Q, map<Ghosts, int> &D, map<Ghosts, bool> &V, int g, Ghosts v, Ghosts source ){
  if ( g == n ){
    if ( check(source, v) ) {
      if ( !V[v] ){
	V[v] = true;
	D[v] = D[source] + 1;
	Q.push( State(v, D[v], getMD(v)) );
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
  priority_queue<State> Q;

  Q.push(State(initial, 0, getMD(initial)));
  D[initial] = 0;
  V[initial] = true;

  State u;
  while(!Q.empty()){
    u = Q.top(); Q.pop();
    if ( u.ghosts == goal ) return D[u.ghosts];
    move(Q, D, V, 0, u.ghosts, u.ghosts);
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
    //    assert(line.size() == w );
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

void init(){
  for ( int i = 0; i < h; i++ ){
    for ( int j = 0; j < w; j++ ){
      for ( int k = 0; k < n; k++ ){
	MDT[i][j][k] = INT_MAX;
      }
    }
  }
  for ( int k = 0; k < n; k++ ){
    mdbfs(k);
  }

  /*
  for ( int k = 0; k < n; k++ ){
    for ( int i = 0; i < h; i++ ){
      for ( int j = 0; j < w; j++ ){
	if ( MDT[i][j][k] == INT_MAX ) cout << 'X';
	else cout << MDT[i][j][k];
      }
      cout << endl;
    }
    cout << endl;
    cout << endl;
  }
  */
}

main(){
  while( cin >> w >> h >> n, w || h || n ){
    input();
    init();
    cout << bfs() << endl;
  }
}
