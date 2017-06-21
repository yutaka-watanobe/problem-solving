// @JUDGE_ID:  17051CA  10441  C++
// @begin_of_source_code
/* Eular Path + Eular Cycle + DFS + lexicograpnically order ! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h> 

class edge{
 public:
  int target;
  string word;
  edge(){}
  edge( int target, string word ): target(target), word(word){}

  bool operator < ( const edge &e ) const{
    return word < e.word;
  }
};

class graph {
 public:
  vector<set<edge> > adj;
  vector<set<edge>::iterator > pos;

  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    adj.resize(n); pos.resize(n);
    for(int i=0; i<n; i++){
      adj[i].clear();
      pos[i] = adj[i].begin();
    }
  }
  
  int size(){ return adj.size(); }

  void insert(int i, int j, string word ){
    adj[i].insert( edge( j, word) );
  }

  edge next(int i){ 
    if(pos[i]==adj[i].end()) return edge( -1, "");
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }
};

graph g;
int n;
int D[ 26 ]; /* degree */
int start, end;
vector<string> P;

void dfs( int u ){

  edge e;
  int target;
  string word;

  while ( 1 ){ 
    e = g.next( u );
    target = e.target;
    word = e.word;
    if ( target == -1 ) break;

    /* cout << u << " -> " << target << " " << word << endl; */
    dfs( target );

    P.push_back( word );
  }
}


void parse(){
  
  P.clear();
  g.reset();
  dfs ( start );

  if ( P.size() == n ){
    for ( int i = n - 1; i >= 0; i-- ){
      if ( i < n - 1 ) cout << ".";
      cout << P[i];
    }
    cout << endl;
  } else {
    cout << "***" << endl;
  }
}

void work(){

  /* check euler path or euler cicle ? */
  bool euler_path = false;
  bool euler_cycle = false;

  int npositive = 0;
  int nnegative = 0;
  int not_zero = 0;

  for ( int i = 0; i < 26; i++ ){
    if ( D[i] == 1 ){
      npositive++;
      end = i;
    } else if ( D[i] == -1 ){
      nnegative++;
      start = i;
    }
    if ( D[i] != 0 ) {
      not_zero++;
    } 
  }

  if ( npositive == 1 && nnegative == 1 ) euler_path = true;
  if ( not_zero == 0 ) euler_cycle = true;

  /* determin start point of euler cycle */
  if ( euler_cycle ){
    for ( int i = 0; i < 26; i++ ){
      if ( g.adj[i].size() ) {
	start = i;
	goto next;
      }
    }
  }

 next:;

  if ( euler_cycle || euler_path ) {
    parse();
  } else {
    cout << "***" << endl;
  }

}

void init(){
  g = graph( 26 );
  for ( int i = 0; i < 26; i++ ) D[i] = 0;
}

void read(){
  init();
  string word;
  cin >> n;
  int source, target;
  for ( int i = 0; i < n; i++ ){
    cin >> word;
    source = word[0] - 'a';
    target = word[ word.size() - 1 ] - 'a';
    g.insert( source, target, word );
    D[ source ]--;
    D[ target ]++;
  }
}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
