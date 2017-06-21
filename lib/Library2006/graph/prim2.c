
/* solved 2721 */
typedef pair<int, int> edge;
edge null(-1, -1);

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dr[3] = {-1, 0, 1};

class graph {
 public:
  vector<set<edge> > adj;
  vector<set<edge>::iterator> pos;

  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      adj[i].clear();
    }
  }
  
  int size(){ return adj.size(); }

  void insert(int i, int j, int e){
    adj[i].insert(make_pair(j, e ) );
  }
  
  edge next(int i){ 
    if(pos[i]==adj[i].end()) return null;
    return *pos[i]++; 
  }

  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ adj.clear(), pos.clear(); }

};

void prim(graph &g, int s,vector<int> &visited, int &dist, int &nbridge){

  vector<edge> pi(g.size() + 1, make_pair(-1, 0 ) );
  vector<int> d(g.size() + 1, INT_MAX);

  int u, v;

  d[s] = 0;
  
  g.reset();

  dist = 0;
  nbridge = 0;

  while(1){
    int min = INT_MAX;
    for (int i=0; i<g.size(); i++){
      if (visited[i]==0 && d[i]<min) {
	min = d[i];
	u = i;
      }
    }

    if( min == INT_MAX ) break;
    visited[u] = 1;

    edge e;
    int c;

    while(( e =g.next(u))!= null){
      v = e.first;
      c = e.second;
      if (visited[v]==0 && c < d[v]){
	d[v] = c;
	pi[v] = make_pair( u, c );
      }
    }
  }
  
  for( int i = 0; i < pi.size(); i++){
    if( pi[i].first != -1 ){
      if ( pi[i].second >= 1 ) nbridge++;
      dist += pi[i].second;
    }
  }

}
