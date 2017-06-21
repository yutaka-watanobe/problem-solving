// @JUDGE_ID:  17051CA  10199  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>

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

void _low(graph &g, vector<int> &pi, vector<int> &d, 
	  vector<int> &low, int &time, int u);
void art_points(graph &g, vector<int> &v);

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

void work(){
  map<string, int> n_i;
  map<int, string> i_n;
  string line, s1, s2;
  int r, id, ii, jj;
  g = graph(n);
  id = 0;
  for(int i=0; i<n; i++){
    cin >> line;
    n_i[line] = id;
    i_n[id] = line;
    id++;
  }
  cin >> r;
  for(int i=0; i<r; i++){
    cin >> s1 >> s2;
    ii = n_i[s1]; jj = n_i[s2];
    g.insert(ii, jj); g.insert(jj, ii);
  }

  vector<int> v;
  vector<string> goal;

  art_points(g, v);
  int sub = 0;
  for(int i=0; i<v.size(); i++){
    if(v[i]!=-1) goal.push_back(i_n[v[i]]);
    else sub++;
  }
  sort(goal.begin(), goal.end());
  cout << v.size()-sub << " camera(s) found" << endl;
  for(int i=0; i<goal.size(); i++){
    cout << goal[i] << endl;
  }
}

main(){
  for(int i=1; read(); i++){
    if(i!=1) cout << endl;
    cout << "City map #" << i << ": ";
    work();
  }
}

/*
 * 下の関数 art_points, bridge, bcc に使われる、lowを計算する再帰関数。
 */
void _low(graph &g, vector<int> &pi, vector<int> &d, 
	  vector<int> &low, int &time, int u){
  int v;

  d[u] = low[u] = ++time;  
  while((v=g.next(u))!=-1){
    if(!d[v]){
      pi[v] = u;
      _low(g, pi, d, low, time, v);
      low[u] = min(low[u], low[v]);
    }
    else if(pi[u]!=v) low[u] = min(low[u], d[v]);
  }
}

/*
 * Articulation points
 * @param v: list of articulation points.
 *
 */
void art_points(graph &g, vector<int> &v){
  vector<int> low(g.size()), d(g.size()), pi(g.size(), -1);
  vector<int> b(g.size());

  int n = 0, time = 0;

  v.clear();

  g.reset();
  for(int i=0; i<g.size(); i++){
    if(!d[i]){
      time = 0;

      _low(g, pi, d, low, time, i);
      
      n = 0;

      for(int k=0; k<g.size(); k++){
	if(b[k]==2) continue;

	int j = pi[k];

	if(j==i) n++;
	else if(j!=-1 && d[j]<=low[k] && !b[j]){
	  v.push_back(j);
	  b[j] = 1;
	}
      }
      if(n>1) v.push_back(i);

      for(int k=0; k<g.size(); k++){
	if(d[k]) b[k] = 2;
      }
    }
  }    
}

// @end_of_source_code
