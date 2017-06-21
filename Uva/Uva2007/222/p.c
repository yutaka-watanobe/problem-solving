// @JUDGE_ID:  17051CA  222  C++
// @begin_of_source_code
/* Graph - shortest path */
/* Dag SP にするべきである */
#include<stdio.h>
#include<iostream>
#include<string>
#include<slist>
#include<vector>

class graph {
 public:
  vector<vector<double> > m;
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

  void insert(int i, int j, double e){
    m[i][j] = e;
    adj[i].push_front(j);
  }

  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ m.clear(), adj.clear(), pos.clear(); }
};

void dijkstra(graph &g, vector<int> &pi, vector<double> &cost, int s);

double dis;

int read(){
  cin >> dis;
  if(dis<0) return 0;
  return 1;
}

graph g;

void work(){
  double capacity, per_gallon, first_cost;
  int k;

  cin >> capacity >> per_gallon >> first_cost >> k;

  vector<pair<double, double> > v;

  pair<double, double> p;
  p.first = 0; p.second = 0;
  v.push_back(p);
  for(int i=0; i<k; i++){
    cin >> p.first >> p.second;
    v.push_back(p);
  }
  p.first = dis; p.second = 0;
  v.push_back(p);

  g = graph(k+2);

  pair<double, double> source, target, next;
  double d, residue;
  double cost, price;

  for( int i = 0; i <= k; i++ ){
    for( int j = i+1; j <= k+1; j++ ){ 
      source = v[i];
      target = v[j];

      d = target.first - source.first;

      if ( d > capacity*per_gallon ) continue;
      if ( j == k+1 ){
	g.insert(i, j, 0 );
	continue;
      }

      residue = capacity - d/per_gallon;

      bool filling  = false;
      if ( residue <= capacity/2 ){
	filling = true;
      }else if ( residue > capacity/2 ){
	next = v[j+1];
	if ( residue*per_gallon < next.first - target.first ) filling = true;
      }

      if ( filling ){
	price = target.second/100;
	cost = ( d/per_gallon)*price;
	if ( j != k+1 ) cost += 2;
	g.insert(i, j, cost);
      }

    }
  }

  vector<int> pi;
  vector<double> costV;

  dijkstra(g, pi, costV, 0);

  double ans = (costV[k+1] + first_cost);
  cout << "minimum cost = $";
  printf("%.2f\n", ans);
}

/**
 * Dijkstra
 * @param 
 *   pi:   previous node
 *         -1 --> source and not visited node
 *   cost: distance from source
 *          0 --> source
 *         INT_MAX --> not visited node
 */ 
void dijkstra(graph &g, vector<int> &pi, vector<double> &cost, int s){
  cost.resize(g.size(), INT_MAX);
  pi.resize(g.size(), -1);
  vector<int> visited(g.size(), 0);
  
  cost[s] = 0;
  g.reset();
  while(1){
    double min = INT_MAX;
    int x;
    for(int i=0; i<g.size(); i++){
      if(visited[i]==0 && min > cost[i] ){
	min = cost[i];
	x = i;
      }
    }

    if( min == INT_MAX ) break;

    visited[x] = 1;

    int v;
    while((v=g.next(x))!=-1){
      if( cost[x] + g.m[x][v] < cost[v] ){
	cost[v] = cost[x] + g.m[x][v];
	pi[v] = x;
      }
    }

  }
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Data Set #" << i << endl;
    work();
  }
}
// @end_of_source_code
