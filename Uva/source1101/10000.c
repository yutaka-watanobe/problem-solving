// @JUDGE_ID:  17051CA  10000  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
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

graph g;
int n;

void bfs(graph &g, vector<int> &pi, vector<int> &d, int s);
int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

void work(){
  g = graph(n+1);
  int start, i, j;
  cin >> start;
  while(1){
    cin >> i >> j;
    if(i==0 && j==0) break;
    g.insert(i, j);
  }
  vector<int> pi, d;
  bfs(g, pi, d, start);

  int max = *max_element(d.begin(), d.end()) ;

  int index;
  for(index=0; index<d.size(); index++){
    if(d[index]==max){

      break;
    }
  }
  cout << "The longest path from " << start << " has length " << max-1 << ", finishing at " << index << "." << endl;
}

main(){
  for(int i=1; read(); i++){
    cout << "Case " << i << ": ";
    work();
    cout << endl;
  }
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
      d[v] = d[u]+1;
      pi[v] = u;
      q.push(v);
    }
  }
}


// @end_of_source_code
