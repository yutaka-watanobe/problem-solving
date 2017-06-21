#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
#define MAX 16
#define INFTY 1024
static const int di[5] = {0, -1, 0, 1, 0};
static const int dj[5] = {1, 0, -1, 0, 0};

class Ghosts{
 public:
  int n, pos[3];

  Ghosts(){}
  Ghosts( int n ): n(n){
    for ( int i = 0; i < 3; i++ ) pos[i] = 0;
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
  int cost, md, costMD;
  State(){}
  State( Ghosts g, int c, int d ): ghosts(g), cost(c), md(d) {costMD = cost + md;}

  bool operator < ( const State &s ) const {
    if ( costMD == s.costMD ) return cost > s.cost;
    else return costMD > s.costMD;
  }
};

int n, w, h;
Ghosts initial, goal;
char G[MAX][MAX];
unsigned short T[MAX*MAX][MAX*MAX][MAX*MAX];
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

int bfs(int k){
  queue<int> Q;
  int s = goal.pos[k];

  MDT[s/w][s%w][k] = 0;
  Q.push(s);
  int u, v;
  while(!Q.empty()){
    u = Q.front(); Q.pop();
    int ni, nj;
    for ( int r = 0; r < 4; r++ ){
      ni = u/w + di[r];
      nj = u%w + dj[r];
      if ( G[ni][nj] == ' ' && MDT[ni][nj][k] == INFTY ){
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

void move(priority_queue<State> &Q, int g, Ghosts v, Ghosts u ){
  if ( g == n ){
    if ( check(u, v) ) {
      if ( T[v.pos[0]][v.pos[1]][v.pos[2]] == INFTY){
	T[v.pos[0]][v.pos[1]][v.pos[2]] = T[u.pos[0]][u.pos[1]][u.pos[2]] + 1;
	Q.push( State(v, T[v.pos[0]][v.pos[1]][v.pos[2]], getMD(v)) );
      }
    }
    return;
  }

  int ni, nj;
  Ghosts nv;
  for ( int dir = 0; dir < 5; dir++ ){
    ni = v.pos[g]/w + di[dir];
    nj = v.pos[g]%w + dj[dir];
    if ( G[ni][nj] == ' ' ){
      nv = v;
      nv.pos[g] = ni*w + nj;
      move( Q, g+1, nv, u );
    }
  }
}

int astar(){
  priority_queue<State> Q;
  for ( int i = 0; i < h*w; i++ )
    for ( int j = 0; j < h*w; j++ )
      for ( int k = 0; k < h*w; k++ ) T[i][j][k] = INFTY;

  Q.push(State(initial, 0, getMD(initial)));
  T[initial.pos[0]][initial.pos[1]][initial.pos[2]] = 0;

  while(!Q.empty()){
    State st = Q.top(); Q.pop();
    Ghosts u = st.ghosts;
    if ( u == goal ) return T[u.pos[0]][u.pos[1]][u.pos[2]];
    move(Q, 0, u, u);
  }

  return INFTY;
}

void input(){
  string line;
  char ch;
  getline( cin, line );

  initial = Ghosts(n);
  goal = Ghosts(n);

  for ( int i = 0; i < h; i++ ){
    getline( cin, line );
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
      for ( int k = 0; k < n; k++ ) MDT[i][j][k] = INFTY;
    }
  }
  for ( int k = 0; k < n; k++ ) bfs(k);
}

main(){
  while( cin >> w >> h >> n, w || h || n ){
    input();
    init();
    cout << astar() << endl;
  }
}
