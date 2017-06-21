/*************
 * Dijkstra + ADJList + Heap*
 ************/
#include<stdio.h>
#include<stl.h> 
#include<vector>


class edge{
 public:
  int destination;
  int weight;
  edge(){}
  edge(int d, int w): destination(d), weight(w){}
};
 
class graph {
 public:
  vector<vector<edge> > adj;
  vector<vector<edge>::iterator> pos;
  
  graph(){}
  graph( int n ){ resize(n); }

  void resize( int n ){
    adj.resize(n), pos.resize(n); 
    for ( int i = 0; i < n; i++ ){
      adj[i].clear();
    }
  }
  
  int size(){ return adj.size(); }

  void insert( int i, int j, int w ){
    adj[i].push_back( edge(j, w) );
  }
  
  edge next( int i ){ 
    if( pos[i] == adj[i].end() ) return edge( -1, -1 );
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for ( int i = 0; i < size(); i++ ) reset(i); }

  void clear(){ adj.clear(), pos.clear(); }
};

#define MAX 1000

class Heap{
 public:
  int *key;
  int index[MAX];
  int heapSize;

  Heap(int n, int v[]){
    key = v;
    heapSize = n;
    for (int i = 1; i <= heapSize; i++ ) index[i] = i-1;
  }

  void constructHeap(){
    for ( int i = heapSize/2; i >= 1; i-- ) downHeap(i);
  }

  void downHeap(int k){
    int j, v;
    v = index[k];
    while( k <= heapSize/2 ){
      j = k + k;
      if ( j < heapSize && key[ index[j] ] > key[ index[j+1] ] ) j++;
      if ( key[v] <= key[ index[j] ] ) break;
      index[k] = index[j];
      k = j;
    }
    index[k] = v;
  }

  int extractMin(){
    int v = index[1];
    index[1] = index[heapSize--]; 
    downHeap(1);
    return v;
  }

  bool empty(){
    return heapSize == 0;
  }


};


graph g;
int n;

/**
 * Dijkstra
 * @param 
 *   pi:   previous node
 *         -1 --> source and not visited node
 *   cost: distance from source
 *          0 --> source
 *         INT_MAX --> not visited node
 * Solved 10171,
 */ 
void dijkstra( graph &g, int pi[], int cost[], int s ){
  int visited[MAX];
  for ( int i = 0; i < g.size(); i++ ){
    pi[i] = -1;
    cost[i] = INT_MAX;
    visited[i] = 0;
  }
  
  cost[s] = 0;
  g.reset();

  Heap PQ = Heap(g.size(), cost);
  edge e;

  while ( !PQ.empty() ){
    int x = PQ.extractMin();
    visited[x] = 1;

    int v, c;
    while ( 1 ){
      e = g.next(x);
      v = e.destination;
      c = e.weight;
      if ( v == -1 ) break;
      if( !visited[v] && cost[x] + c < cost[v] ){ 
	cost[v] = cost[x] + c;
	pi[v] = x;
      }
    }
    
    PQ.constructHeap();

  }
}

void read(){
  int i, j, e;
  cin >> n;
  g = graph(n);
  while(1){
    cin >> i >> j >> e;
    if( cin.eof() ) break;
    g.insert(i, j, e); g.insert(j, i, e); 
  }
}

main(){
  read(); /* read graph */
  int pi[MAX];
  int cost[MAX];
  
  g.reset();
  dijkstra(g, pi, cost, 0);
  cout << "pi:    "; for(int i=0; i<n; i++) printf("%3d", pi[i]);
  cout << endl;
  cout << "cost : "; for(int i=0; i<n; i++) printf("%3d", cost[i]);
  cout << endl;
}
 

