// @JUDGE_ID:  17051CA  140  C++
// @begin_of_source_code
/* Graph + Permutation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<map>
#include<vector>
#include<slist>
/**
 * class: graph
 * usage: #include <slist>
 */
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

  void insert(int i, int j){
    m[i][j] = 1;
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
};

graph g;

string line;
set<int> S;
vector<int> V;

int read(){
  cin >> line;
  if(line=="#") return 0;

  g = graph(26);
  V.clear();
  S.clear();

  bool source = true;
  char s;
  
  for ( int i = 0; i < line.size(); i++ ){
    if( source ){
      if ( line[i] == ':' ){
	source = false;
      }else{
	s = line[i];
	S.insert( line[i] - 'A' );
      }
    }else {
      if ( line[i] == ';' ){
	source = true;
      }else{
	S.insert( line[i] - 'A' );
	g.insert( s - 'A', line[i] - 'A' );
	g.insert( line[i] - 'A', s - 'A' );
      }
    }
  }

  return 1;
}

void work(){
  
  V.resize( S.size() );
  copy ( S.begin(), S.end(), V.begin() );

  int minV = INT_MAX;
  vector<int> G;

  do{
    if ( !(V[0] <= V[V.size()-1]) ) continue;

    int maxV = 0;
    int d;
    for ( int i = 0; i < V.size() - 1; i++ ){
      for ( int j = i + 1; j < V.size(); j++ ){
	if ( g.m[ V[i] ][ V[j] ] ){ 
	  d = j - i;
	  maxV = max( maxV, d );
	}
      }
    }

    if( maxV < minV ){
      minV = maxV;
      G = V;
    }

  }while( next_permutation( V.begin(), V.end() ) );

  for ( int i = 0; i < G.size(); i++ ){
    cout << (char)(G[i] + 'A') << " ";
  }
  cout << "-> " << minV << endl;

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
