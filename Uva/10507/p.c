// @JUDGE_ID:  17051CA  10507  C++
// @begin_of_source_code
/* Graph Simulation */
/* Fuck input ! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<slist>
#include<stl.h>
#define SLEEP 0
#define WAKE 1

/** 
 * class: graph 
 * It must be non-weighted graph !!.
 */
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

int N, M;
graph g;
string line;
vector<int> S;

int read(){
  cin >> N >> M;

  if (cin.eof() ) return 0;
  string wake;

  g = graph( 26 );
  S.clear();
  S.resize( 26, SLEEP );

  cin >> wake;
  
  S[wake[0] - 'A'] = WAKE;
  S[wake[1] - 'A'] = WAKE;
  S[wake[2] - 'A'] = WAKE;

  for ( int i = 0; i < M; i++ ){
    cin >> line;
    g.insert( line[0] - 'A', line[1] - 'A');
    g.insert( line[1] - 'A', line[0] - 'A');
  }
  return 1;
}

void work(){
  
  bool change;
  int year = 0;
  int u, v;
  int wake_cnt = 3;

  vector<int> W;

  if ( N <= 3 ) goto end;

  while( 1 ){
    year++;
    change = false;

    W.clear();
    for ( int i = 0; i < 26; i++ ){
   
      if ( S[i] == SLEEP ){
	int cnt = 0;
	g.reset();
	while( (v=g.next(i)) != -1 ){
	  if( S[v] == WAKE ) cnt++;
	}
	if ( cnt >= 3 ){
	  W.push_back(i);
	  change = true;
	}
      }
    }

    for (int i = 0; i < W.size(); i++ ){
      S[W[i]] = WAKE;
    }
    
    wake_cnt += W.size();

    if( wake_cnt == N ) break;
    
    if( !change && wake_cnt != N ){
      cout << "THIS BRAIN NEVER WAKES UP" << endl;
      return;
    }
    
  }
  
 end:;
  cout << "WAKE UP IN, " << year << ", YEARS" << endl;
}

main(){
  while( read() ){
    work();
  }
}
// @end_of_source_code
