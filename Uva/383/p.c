#include<stdio.h>
#include<vector>
#include<slist>
#include<queue>
#include<iostream>
n~
/** 
 * class: graph 
 * It must be non-weighted graph !!.
 */
class graph {
 public:
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;
  
  /** constructor */
  graph(){}
  graph(int n){ resize(n); }

  /**  @param the number of node */ 
  void resize(int n){
    adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      adj[i].clear();
    }
  }
  
  /** @return the number of node */
  int size(){ return adj.size(); }

  /** insert  */
  void insert(int i, int j){
    adj[i].push_front(j);
  }
  
  /** refere to adjacency list of node i, and move one. */
  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  /** reset */
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  /* less used methods */
  void erase(int i, int j){
    for(slist<int>::iterator it=adj[i].begin(); it!=adj[i].end(); it++){
      if(*it==j){
	adj[i].erase(it);
	break;
      }
    }
  }

  /** clear all nodes */
  void clear(){ adj.clear(), pos.clear(); }
};

graph g;
int n;
void bfs(graph &g, vector<int> &pi, vector<int> &d, int s);

void read(){
  int i, j;
  cin >> n;
  g = graph(n);
  while(1){
    cin >> i >> j;
    if( cin.eof() ) break;
    g.insert(i, j); g.insert(j, i); 
  }
}

main(){
  read(); /* read graph */
  vector<int> pi, d;
  g.reset();
  bfs(g, pi, d, 0);
  cout << "pi: "; for(int i=0; i<n; i++) cout << pi[i] << " ";
  cout << endl;
  cout << "d : "; for(int i=0; i<n; i++) cout << d[i] << " ";
  cout << endl;
}

/*
 * BFS (Breadth First Search)
 * @param
 * pi: it represet the node that is searched before it.
 *     -1 ---> the node that is not visited.
 * d : it represet level of the node.
 *       0 ---> the node that is not visited.
 *     it is form 1 not zero! (i.e. source is 1).
 * s : source
 * requirement: #include <queue>
 */
void bfs(graph &g, vector<int> &pi, vector<int> &d, int s){
  queue<int> q;
  int u, v;

  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);

  q.push(s);
  d[s] = 1;
  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();
    while((v=g.next(u))!=-1){
      if(!d[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	q.push(v);
      }
    }
  }
}
