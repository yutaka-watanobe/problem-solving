// @JUDGE_ID:  17051CA  10187  C++
// @begin_of_source_code
#include<stdio.h>
#include<stl.h> 
#include<vector>
#include<slist>
#include<string>

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

  void clear(){ m.clear(), adj.clear(), pos.clear(); }

  graph & operator=(const graph &g){
    m = g.m;
    adj = g.adj;
    pos.resize(m.size());
    for(int i=0; i<m.size(); i++)
      pos[i] = adj[i].begin();
  }
};


graph g;

void dijkstra(graph &g, vector<int> &pi, vector<int> &d, int s);

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
    while((v=g.next(x))!=-1){
      if( !visited[v] && cost[x] + g.m[x][v] < cost[v] ){ 
	cost[v] = cost[x] + g.m[x][v];
	pi[v] = x;
      }
    }

  }
}

map<int, string> name_table;
vector<int> time_table;
string source_name, target_name;
int m;

void read(){
  cin >> m;
  g = graph ( 2 * m );
  name_table = map<int, string>();
  time_table.clear();
  time_table.resize( 2 * m );

  int index = 0;
  int source_time, target_time, time;


  for ( int i = 0; i < m; i++ ){
    cin >> source_name >> target_name >> source_time >> time;
    target_time = ( source_time + time ) % 24;

    if ( (18 <= source_time && source_time <= 24  ||  1 <= source_time && source_time <= 6) &&
	 (18 <= target_time && target_time <= 24  ||  1 <= target_time && target_time <= 6) ){
      if ( source_time <= 6 ) source_time += 24;
      if ( target_time <= 6 ) target_time += 24;
      if ( source_time <= target_time ){
	g.insert( index, index+1, 0 );
	/* cout << index << "-->" << index+1 << endl; */
      }
    }
    time_table[index] = source_time;
    time_table[index+1] = target_time;
    name_table[ index ] = source_name;
    name_table[ index + 1 ] = target_name;

    index += 2;
  }

  /* create connection */
  for ( int s = 0; s < 2*m; s++ ){
    for ( int t = 0; t < 2*m; t++ ){
      if ( s == t ) continue;
      if ( name_table[s] == name_table[t] ){
	int e = 0;
	if ( time_table[s] < time_table[t] && time_table[s] <= 12 ){
	  e = 1;
	}
	if ( time_table[s] > time_table[t] && time_table[t] >= 12 ){
	  e = 1;
	}
	g.insert( s, t, e );
	/* cout << s << "-->" << t << " with " << e << endl; */
      }
    }
  }

  cin >> source_name >> target_name;

}

void work(){
  int cost = INT_MAX;
  for ( int s = 0; s < 2*m; s++ ){
    if ( name_table[s] == source_name ){
      vector<int> pi, d;

      dijkstra( g, pi, d, s );

      for ( int t = 0; t < 2*m; t++ ){
	if ( name_table[t] == target_name ){
	  if ( cost > d[t] ) cost = d[t];
	}
      }
    }
  }

  if ( cost == INT_MAX ){
    cout << "There is no route Viadimir can take." << endl;
  }else{
    cout << "Vladimir needs " << cost << " litre(s) of blood." << endl;
  }
}

main(){
  int t;
  cin >> t;
  for ( int i = 1; i <= t; i++ ){
    cout << "Test Case " << i << "." << endl;
    read();
    work();
  }
}

// @end_of_source_code
