// @JUDGE_ID:  17051CA  10047  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<slist>
#include<queue>
#include<set>
#define SPACE 0
#define BLOCK 1
#define MAX 30
#define N 0
#define E 1
#define S 2
#define W 3

int h, w;
unsigned int grid[MAX][MAX];
int start, goal;
bool visited[MAX*MAX*20];

class graph{
 public:
  int s;
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;
  graph(){}
  graph(int n){ resize(n); s = n;}
  void resize(int n){
    adj.resize(n), pos.resize(n);
    for(int i=0; i<n; i++){
      adj[i].clear();
    }
  }
  int size(){ return s; }
  void insert(int i, int j){
    adj[i].push_front(j);
  }
  int next(int i){
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++;
  }
  void reset(int i){ pos[i] = adj[i].begin();}
  void reset(){ for(int i=0; i<size(); i++) reset(i);}
};

graph g;

int read();
void work();
void createStateG(int, int, int, int);
int bfs(graph &g, int, vector<int> &v);

void work(){
  string line;
  char c;
  for(int i=0; i<h; i++){
    cin >> line;
    for(int j=0; j<w; j++){
      c = line[j];
      if(c=='S') {start = i*w+j; grid[i][j] = SPACE;}
      else if(c=='T') {goal = i*w+j; grid[i][j] = SPACE;}
      else if(c=='.') grid[i][j] = SPACE;
      else if(c=='#') grid[i][j] = BLOCK;
    }
  }

  for(int i=0; i<h*w*20; i++) visited[i] = false;

  g = graph(h*w*20);
  int source = start*20;
  vector<int> end;
  end.push_back( goal*20 + N);
  end.push_back( goal*20 + E);
  end.push_back( goal*20 + S);
  end.push_back( goal*20 + W);

  createStateG(start, 0, source, N); 
  
  int cost = bfs(g, source, end);
  if( cost == -1 ) cout << "destination not reachable" << endl;
  else cout << "minimum time = " << cost << " sec" << endl;
}

/**
 * @param position, color, direction
 */
void createStateG(int pos, int scolor, int source, int dir){
  int color, base, head;
  color = scolor%5;
  base = pos*20;
  head = base + color*4;
  if( visited[head+dir] ) return;
  visited[head+dir] = true;
  
  g.insert(source, head+dir);

  g.insert(head, head+1);  g.insert(head+1, head); 
  g.insert(head+1, head+2); g.insert(head+2, head+1);
  g.insert(head+2, head+3); g.insert(head+3, head+2);
  g.insert(head+3, head); g.insert(head, head+3);
  
  int i, j, x, y;
  for(int d=0; d<4; d++){
    x = y = 0;
    i = pos/w; 
    j = pos - i*w;
    if(d==N) x--;
    if(d==E) y++;
    if(d==S) x++;
    if(d==W) y--;
    i += x; j += y;
    if( i >=0 && j >=0 && i < h && j < w && grid[i][j]==SPACE ){
      createStateG(i*w+j, scolor+1, head+d, d);
    }
  }
}

int bfs(graph &g, int s, vector<int> &t){
  vector<int> pi, d;
  queue<int> q;
  int u, v;

  pi.resize(g.size());
  fill(pi.begin(), pi.end(), -1);
  d.resize(g.size());
  fill(d.begin(), d.end(), 0);

  q.push(s);
  d[s] = 0;
  g.reset();

  while(!q.empty()){
    u = q.front(), q.pop();
    if( u==t[0] || u==t[1] || u==t[2] || u==t[3]) return d[u];
    while((v=g.next(u))!=-1){
      if(!d[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	q.push(v);
      }
    }
  }
  return -1;
}

main(){
  for(int i=1; read(); i++){
    if( i!=1 ) cout << endl;
    cout << "Case #" << i << endl;
    work();
  }
}

int read(){
  cin >> h >> w;
  if( h==0 && w==0 ) return 0;
  return 1;
}
// @end_of_source_code
