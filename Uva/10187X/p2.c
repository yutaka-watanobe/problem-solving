// @JUDGE_ID:  17051CA  10187  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<map>
#include<string>
#include<vector>
#include<slist>
#include<queue>

class graph {
 public:
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;
  
  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      adj[i].clear();
    }
  }
  
  int size(){ return adj.size(); }

  void insert(int i, int j){
    adj[i].push_front(j);
  }
  
  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ adj.clear(), pos.clear(); }
};

class node{
 public:
  vector<int> arrival;
  node(){}

  void push_back(int t){
    arrival.push_back( t );
  }
};

class edges{
 public:
  vector<int> start_times;
  edges(){}
};

graph g;
int n;
map<string, int> name_index;
set<string> name_list;
map< pair<int, int>, edges > E;
vector<node> N;


bool isparsable(int source_time, int target_time ){
  if ( target_time - source_time > 12 ) return false;
  if ( source_time >=6 && source_time < 18 ) return false;
  if ( target_time % 24 > 6 && target_time % 24 <= 18 ) return false;
  return true;
  /* if ( (18 <= source_time && source_time <= 24  ||  1 <= source_time && source_time <= 6) && */
/*        (18 <= target_time && target_time <= 24  ||  1 <= target_time && target_time <= 6) ){ */
/*     if ( source_time <= 6 ) source_time += 24; */
/*     if ( target_time <= 6 ) target_time += 24; */
/*     if ( source_time <= target_time ){ */
/*       return true; */
/*     } */
/*   } */
/*   return false; */
}

void read(){
  g.clear();
  g = graph( 101 );
  N.clear();
  N.resize( 101, node() );
  E = map< pair<int, int>, edges>();

  name_index = map<string, int>();
  name_list.clear();

  int m;
  cin >> m;
  string source_name, target_name;
  int source_time, target_time, time;
  int source, target;

  vector<vector<bool> > used;
  used.resize( 101 );
  for ( int i = 0; i < 101; i++ ) used[i].resize( 101, false );
  
  n = 0;
  for ( int i = 0; i < m; i++ ){
    cin >> source_name >> target_name >> source_time >> time;

    target_time = (source_time + time) % 24;

    if ( find( name_list.begin(), name_list.end(), source_name ) == name_list.end() ){
      name_list.insert( source_name );
      name_index[ source_name ] = n;
      n++;
    }
    if ( find( name_list.begin(), name_list.end(), target_name ) == name_list.end() ){
      name_list.insert( target_name );
      name_index[ target_name ] = n;
      n++;
    }

    if ( !isparsable( source_time, target_time ) ) continue;


    source = name_index[ source_name ];
    target = name_index[ target_name ];
    

    if ( !used[source][target] ){
      g.insert( source, target );
      /* cout << "insert " << source << "-->" << target << endl; */
      used[source][target] = true;
    }

    N[target].push_back( target_time );
    E[ make_pair(source, target) ].start_times.push_back( source_time );

  }

}

bool overDay(int s, int t ){
  if ( s == 12 || t == 12 ) return true;
  if ( s < 12 ){
    if ( 12 < t ) return true;
    else return false;
  }else if ( s > 12 ){
    if ( t < s && 12 < t ) return true;
    else return false;
  }
}

int getCost( int u, int v ){
  if ( N[u].arrival.size() == 0 ) return 0;
  int cost = 1;
  pair<int, int> edge = make_pair( u, v );
  for ( int i = 0; i < N[u].arrival.size(); i++ ){
    for ( int j = 0; j < E[ edge ].start_times.size(); j++ ){
      if ( !overDay ( N[u].arrival[i], E[ edge ].start_times[j] ) ){
	return 0;
      }
    }
  }
  return cost;
}

int bfs(graph &g, int s, int e ){
  queue<int> q;
  int u, v;

  vector<int> pi, d, visited;

  pi.resize(g.size(), -1);
  d.resize(g.size(), INT_MAX);
  visited.resize( g.size(), false );

  q.push(s);
  d[s] = 0;
  visited[s] = true;

  g.reset();

  while(!q.empty()){
    u = q.front(), q.pop();
    if ( u == e ) return d[u];

    while( (v=g.next(u))!=-1 ){
      d[v] = min( d[v], d[u] + getCost( u, v ) );
      if(!visited[v]){
	pi[v] = u;
	q.push(v);
      }
      visited[v] = true;
    }
  }
  
  return -1;
}


void work(){
  string source_name, target_name;
  cin >> source_name >> target_name ;
  int s = name_index[ source_name ];
  int e = name_index[ target_name ];

  N[s].arrival.clear();

  int cost = bfs(g, s, e);
  if ( cost == - 1 ) cout << "There is no route Vladimir can take." << endl;
  else cout << "Vladimir needs " << cost << " litre(s) of blood." << endl;
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

