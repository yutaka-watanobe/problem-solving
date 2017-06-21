// Tree climbing
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 5001


class graph {
 public:
  vector<vector<int> > adj;
  vector<vector<int>::iterator> pos;
  
  graph(){}
  graph( int n ){ resize(n); }

  void resize( int n ){
    adj.resize(n), pos.resize(n); 
    for( int i = 0; i < n; i++ ){
      adj[i].clear();
    }
  }
  
  int size(){ return adj.size(); }

  void insert( int i, int j ){
    adj[i].push_back(j);
  }

  int next( int i ){ 
    if( pos[i] == adj[i].end() ) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for( int i = 0; i < size(); i++) reset(i); }

  void erase( int i, int j){
    for( vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++){
      if( *it==j ){
	adj[i].erase(it);
	break;
      }
    }
  }
  void clear(){ adj.clear(), pos.clear(); }
};

class Node{
 public:
  int depth;
  int parent;
  Node(){
  }
};

graph g;
Node buffer[MAX];
int n;



bool visited[MAX];

int computeLength(int f1, int f2 ){
  int length = 0;

  while ( buffer[f1].depth != buffer[f2].depth ){
    length++;
    f1 = buffer[f1].parent;
  }

  while ( f1 != f2 ){
    length += 2;
    f1 = buffer[f1].parent;
    f2 = buffer[f2].parent;
  }
  return length;
}

int getPos( int s, int l ){
  for ( int i = 0; i < l; i++ ){
    s = buffer[s].parent;
  }
  return s;
}

void compute(){
  int f1, f2;
  cin >> f1 >> f2; f1--; f2--;
  int length, length2;
  if ( buffer[f1].depth > buffer[f2].depth ){
    length = computeLength(f1, f2);
  } else {
    length = computeLength(f2, f1);
  }

  length2 = length/2;
  
  int pos;

  if ( buffer[f1].depth > buffer[f2].depth ){
    pos = getPos( f1, length2 );
  } else {
    pos = getPos( f2, length2 );
  }

  if ( length % 2 == 0 ){
    cout << "The fleas meet at " << pos+1 << "." << endl;
  } else {
    int v1, v2;
    v1 = pos;
    v2 = buffer[pos].parent;
    cout << "The fleas jump forever between " << min(v1,v2)+1 << " and " << max(v1,v2)+1 << "." << endl;
  }

  
}

bool read(){
  cin >> n;
  if ( n == 0 ) return false;
  g = graph (n);
  int source ,target;
  for ( int i = 0; i < n-1; i++ ){
    cin >> source >> target; source--; target--;
    g.insert( source, target ); g.insert( target, source );
  }
  return true;
}


void bfs(){
  queue<int> q;
  for ( int i=0; i < n; i++ ) visited[i] = false;
  q.push(0);
  buffer[0].depth = 0;
  buffer[0].parent = -1;
  visited[0] = true;
  g.reset();
  int u, v;
  while ( !q.empty() ){
    u = q.front(); q.pop();
    while ( (v=g.next(u))!=-1) {
      if ( !visited[v] ){
	visited[v] = true;
	buffer[v].depth = buffer[u].depth + 1;
	buffer[v].parent = u;
	q.push(v);
      }
    }
  }
}

void construct(){
  bfs();
}

void work(){
  construct();
  int q; cin >> q;

  /*
  for ( int i = 0; i < n; i++ ){
    cout << i+1 << ": " << buffer[i].depth << ", " << buffer[i].order << endl;
    }*/

  for ( int i = 0; i < q; i++ ){
    compute();
  }
}

main(){
  while ( read() ){
    work();
  }
  
}



