// @JUDGE_ID:  17051CA  523  C++
// @begin_of_source_code
/* Graph SSSP - Dijkstra */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

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
  
  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ m.clear(), adj.clear(), pos.clear(); }
};

vector<int> T;

/**
 * Dijkstra
 * @param 
 *   pi:   previous node
 *         -1 --> source and not visited node
 *   cost: distance from source
 *          0 --> source
 *         INT_MAX --> not visited node
 * Solved 10171,
 */ 
void dijkstra(graph &g, vector<int> &pi, vector<int> &cost, int s){
  cost.resize(g.size(), INT_MAX);
  pi.resize(g.size(), -1);
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
    int c;
    while((v=g.next(x))!=-1){
      c = cost[x] + g.m[x][v];
      if ( x != s ) c += T[x];
      if( !visited[v] && c < cost[v] ){ 
	cost[v] = c;
	pi[v] = x;
      }
    }

  }
}

graph g;
string line;
int n;

void transport(int s, int t ){
  cout << "From " << s+1 << " to " << t+1 << " :" << endl;

  vector<int> pi, d;
  dijkstra(g, pi, d, s);

  /* path */
  vector<int> p;
  int pre = t;
  while ( 1 ){
    if ( pre == -1 ) break;
    p.push_back( pre );
    pre = pi[pre];
  }
  reverse( p.begin(), p.end() );
  cout << "Path: ";
  for ( int i = 0; i < p.size(); i++ ){
    if ( i ) cout << "-->";
    cout << p[i]+1;
  }
  cout << endl;
  cout << "Total cost : " << d[t] << endl;
}

int read(){
  getline( cin, line );
  vector<string> com;
  split( com, line );
  n = com.size();
  g = graph( n );
  int e;
  T.clear();
  T.resize( n );
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      if ( i == 0 ){
	e = atoi( com[j].c_str() );
      }else{
	cin >> e;
      }
      if ( e != -1 && e != 0 ) g.insert( i, j, e );
    }
  }

  for ( int i = 0; i < n; i++ ){
    cin >> T[i];
  }

  getline( cin, line );

  for ( int i = 0; true; i++ ){
    getline( cin, line );
    if ( line == ""  || cin.eof() ) return 1;
    if ( i ) cout << endl;
    com.clear();
    split( com, line );
    transport( atoi(com[0].c_str())-1, atoi(com[1].c_str())-1 );
  }
}

main(){
  int t;
  getline( cin, line );
  t = atoi( line.c_str() );
  getline( cin, line );
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
  }
}
// @end_of_source_code
