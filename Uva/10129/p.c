// @JUDGE_ID:  17051CA  10129  C++
// @begin_of_source_code
/* Graph */
/* Eular Cicle または Eular Path があればしりとり可能 */
/* Direct Graph において */
/* 次数がすべて偶数ならEular Cicle */
/* -1 と +1 の次数がそれぞれ１つづつあるなら Eular Path が存在 */
/* DisjointSet でコネクションをチェック */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>

class DisjointSet{
 public:
  vector<int> rank, p;
  
  DisjointSet(){}
  DisjointSet(int size){
    rank.resize(size, 0);
    p.resize(size, 0);
  }

  void makeSet(int x){
    p[x] = x;
    rank[x] = 0;
  }

  void merge(int x, int y){
    link(findSet(x), findSet(y));
  }

  void link(int x, int y){
    if(rank[x] > rank[y]){
      p[y] = x;
    }else{   
      p[x] = y;
      if(rank[x] == rank[y]){
	rank[y] = rank[y] + 1;
      }
    }
  }

  int findSet(int x){
    if(x != p[x]){
      p[x] = findSet(p[x]);
    }
    return p[x];
  }
};

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

graph g;
int W[26];
int U[26];
int E;
int edge_cnt;
map< pair<int, int>, bool > visited;
int start;
DisjointSet dset;

int read(){
  int n;
  string str;
  g = graph( 26 );
  dset = DisjointSet( 26 );

  for(int i=0; i<26; i++){
    dset.makeSet(i);
  }

  fill( W, W + 26, 0 );
  fill( U, U + 26, 0 );

  cin >> n;
  start = 26;

  char s, e;
  int source, target;
  for ( int i = 0; i < n; i++ ){
    cin >> str;
    s = str[0];
    e = str[ str.size()-1 ];
    source = s - 'a';
    target = e - 'a';
    g.insert( source, target );
    dset.merge( source, target );
    W[ source ]--;
    W[ target ]++;
    U[ source ]++;
    U[ target ]++;
  }

}

void work(){
  int one_neg, one_pos, zero;
  one_neg = one_pos = zero = 0;
  bool path = false;
  for ( int i = 0; i < 26; i++ ){
    if ( W[i] == 1 ) one_pos++;
    if ( W[i] == -1 ) one_neg++;
    if ( W[i] != 0 ) zero++;
  }

  if ( one_pos == 1 && one_neg == 1 ) path = true;
  if ( zero == 0 ) path = true;
  
  for ( int i = 0; i < 26 -1; i++ ){
    for ( int j = i+1; j < 26; j++ ){
      if ( (U[i] && U[j] ) && (dset.findSet(i) != dset.findSet(j)) ){
	path = false;
      }
    }
  }
  
  if( path ){
    cout << "Ordering is possible." << endl;
  }else{
    cout << "The door cannot be opened." << endl;
  }

}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
