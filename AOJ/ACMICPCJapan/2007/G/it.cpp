#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<cassert>
using namespace std;
#define MAX 17
#define LIM 317
class Ghosts{
 public:
  int n, pos[3];

  Ghosts(){}
  Ghosts( int n ): n(n){}

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
int MDT[MAX][MAX][3];
int depth;

int getMD(Ghosts v){
  int md = 0;
  for ( int i = 0; i < n; i++ ){
    md = max(md, MDT[v.pos[i]/w][v.pos[i]%w][i] );
  }
  return md;
}

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



bool dfs(Ghosts u, Ghosts pre,int d);

bool move( int g, Ghosts v, Ghosts source, int d, Ghosts pre ){
  if ( g == n ){
    if ( check(source, v) && !(v == pre) ) {
      if ( dfs(v, source, d+1) ) return true;
    }
    return false;
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
      move( g+1, nv, source, d, pre );
    }
  }
}

bool dfs(Ghosts u, Ghosts pre, int d){
  if ( u == goal ) return true;
  if ( d + getMD(u) > depth ) return false;
  
  if ( move(0, u, u, d, pre) ) return true;
  return false;
}


int itd(){

  for ( depth = getMD(initial); ;depth++ ){
    Ghosts pre = Ghosts(n);
    for ( int i = 0; i < n; i++ ) pre.pos[i] = -1;
    if ( dfs(initial, pre, 0) ) return depth;
  }

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
}

main(){
  while( cin >> w >> h >> n, w || h || n ){
    input();
    init();
    cout << itd() << endl;
  }
}
