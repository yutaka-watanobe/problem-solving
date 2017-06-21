/*********
 * Graph *
 *********/
#include<stdio.h>
#include<stl.h> 
#include<vector>

/** 
 * class: graph 
 * It must be non-weighted graph !!.
 */
class graph {
 public:
  vector<vector<int> > adj;
  vector<vector<int>::iterator> pos;
  
  /** constructor */
  graph(){}
  graph( int n ){ resize(n); }

  /**  @param the number of node */ 
  void resize( int n ){
    adj.resize(n), pos.resize(n); 
    for( int i = 0; i < n; i++ ){
      adj[i].clear();
    }
  }
  
  /** @return the number of node */
  int size(){ return adj.size(); }

  /** insert  */
  void insert( int i, int j ){
    adj[i].push_back(j);
  }
  
  /** refere to adjacency list of node i, and move one. */
  int next( int i ){ 
    if( pos[i] == adj[i].end() ) return -1;
    return *pos[i]++; 
  }
  
  /** reset */
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for( int i = 0; i < size(); i++) reset(i); }

  /* less used methods */
  void erase( int i, int j){
    for( vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++){
      if( *it==j ){
	adj[i].erase(it);
	break;
      }
    }
  }

  /** clear all nodes */
  void clear(){ adj.clear(), pos.clear(); }
};



