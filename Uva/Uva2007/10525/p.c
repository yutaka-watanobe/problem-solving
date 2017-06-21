// @JUDGE_ID:  17051CA  10525  C++
// @begin_of_source_code
/* Graph Shortest Path */
/* Use dijkstra's algorithm type2 that can create several shortest path */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>

class graph {
 public:
  vector<vector<int> > m;
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;
  
  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    m.resize(n), adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      m[i].resize(n);
      fill(m[i].begin(), m[i].end(), 0);
      adj[i].clear();
    }
  }
  
  int size(){ return m.size(); }

  void insert(int i, int j, int e){
    m[i][j] = e;
    adj[i].push_front(j);
  }
  
  vector<int> & operator[](int i){ return m[i]; }

  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }

  void reset(int i){ pos[i] = adj[i].begin(); }

  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void erase(int i, int j){
    m[i][j] = 0;
    for(slist<int>::iterator it=adj[i].begin(); it!=adj[i].end(); it++){
      if(*it==j){
	adj[i].erase(it);
	break;
      }
    }
  }

  void clear(){ m.clear(), adj.clear(), pos.clear(); }

  graph & operator=(const graph &g){
    m = g.m;
    adj = g.adj;
    pos.resize(m.size());
    for(int i=0; i<m.size(); i++)
      pos[i] = adj[i].begin();
  }
};


/**
 * Dijkstra
 * @param 
 *   pi:   previous node vector
 *         sise of pi[i] == 0  --> source and not visited node!!
 *   cost: distance from source
 *          0 --> source
 *         INT_MAX --> not visited node
 */ 
void dijkstra(graph &g, vector<vector<int> > &pi, vector<int> &cost, int s){
  cost.resize(g.size(), INT_MAX);
  pi.resize(g.size());
  vector<int> visited(g.size(), 0);
  
  cost[s] = 0;
  g.reset();
  while(1){
    int min = INT_MAX;
    int x;
    for(int i=0; i<g.size(); i++){
      if(visited[i]==0 && min > cost[i] ){
	min = cost[i];
	x = i;
      }
    }

    if( min == INT_MAX ) break;

    visited[x] = 1;

    int v;
    int dist;
    while((v=g.next(x))!=-1){
      if( !visited[v] ){
	dist = cost[x] + g.m[x][v];
	if( dist == cost[v] ){
	  pi[v].push_back(x);
	}else if( dist < cost[v] ){ 
	  cost[v] = dist;
	  pi[v].clear();
	  pi[v].push_back(x);
	}
      }
    }

  }
}
int n;
graph g;
graph t;
int shortest_distance;

/**
 * Print Path. not ordered!
 */
void printPath(vector<vector<int> > &pi, int p, int len){
  /*    cout << p+1 << " "; */
  
  if ( pi[p].size() == 0 ){
    /* cout << len << endl; */
    shortest_distance = min( len, shortest_distance );
  }

  for( int j = 0; j < pi[p].size(); j++ ){
    printPath(pi, pi[p][j], len + g.m[p][pi[p][j]]);
  }

}

int read(){
  int k;
  cin >> n >> k;
  
  g = graph( n );
  t = graph( n );

  int dist, time;

  int a, b;
  for ( int i = 0; i < k; i++ ){
    cin >> a >> b >> time >> dist;
    a--; b--;
    g.insert(a, b, dist); g.insert(b, a, dist);
    t.insert(a, b, time); t.insert(b, a, time);
  }
}

void query(int s, int d ){
  vector<vector<int> > pi;
  vector<int> cost;

  dijkstra(t, pi, cost, s);


  if( cost[d] == INT_MAX ) {
    cout << "No Path." << endl;
    return;
  }

  shortest_distance = INT_MAX;
  printPath( pi, d , 0);  
  cout << "Distance and time to reach destination is ";
  cout << shortest_distance << " & " << cost[d] << "." << endl;
}

void work(){
  int q, a, b;
  cin >> q;
  for ( int i = 0; i < q; i++ ){
    cin >> a >> b;
    a--; b--;
    query( a, b );
  }
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
