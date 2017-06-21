// @JUDGE_ID:  17051CA  10187  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<map>
#include<string>
#include<vector>
#include<queue>

class edge{
 public:
  int start, end;
  int source, target;
  edge(){}
  edge(int start, int end, int source, int target): start(start), end(end), source(source), target(target){}
};

class Station{
 public:
  vector<int> arrival;
  vector<edge> train;
  Station(){}
};

int n;
map<string, int> name_index;
set<string> name_list;

vector<Station> S;

bool isparsable(int source_time, int target_time ){
  if ( target_time - source_time > 12 ) return false;
  if ( source_time >=6 && source_time < 18 ) return false;
  if ( target_time % 24 > 6 && target_time % 24 <= 18 ) return false;
  return true;
}

void read(){

  S.clear();
  S.resize( 101 );

  name_index = map<string, int>();
  name_list.clear();

  int m;
  cin >> m;
  string source_name, target_name;
  int source_time, target_time, time;
  int source, target;

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

    if ( time > 12 ) continue;
    if ( !isparsable( source_time, target_time ) ) continue;

    source = name_index[ source_name ];
    target = name_index[ target_name ];
    
    S[target].arrival.push_back( target_time );
    S[source].train.push_back( edge(source_time, target_time, source, target ) );

  }

}

bool overDay(int s, int t ){
  if ( s == 12 || t == 12 ) return true;
  if ( s < 12 ){
    if ( 12 < t || t < 12) return true;
    else return false;
  }else if ( s > 12 ){
    if ( t < s && 12 < t ) return true;
    else return false;
  }
}

int getCost( int u, edge e ){
  if ( S[u].arrival.size() == 0 ) return 0;
  int cost = 1;
  
  for ( int i = 0; i < S[u].arrival.size(); i++ ){
    if ( !overDay ( S[u].arrival[i], e.start ) ) {
      return 0;
    }
  }
  return cost;
}

int bfs(int s, int e ){
  queue<int> q;
  int u, v;

  vector<int> pi, d, visited;

  pi.resize(S.size(), -1);
  d.resize(S.size(), INT_MAX);
  visited.resize( S.size(), false );

  q.push(s);
  d[s] = 0;
  visited[s] = true;

  while(!q.empty()){
    u = q.front(), q.pop();
    if ( u == e ) return d[u];

    for ( int i = 0; i < S[u].train.size(); i++ ){
      edge e = S[u].train[i];
      int v = e.target;
      d[v] = min( d[v], d[u] + getCost( u, e ) );
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

  S[s].arrival.clear();

  int cost = bfs(s, e);
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

