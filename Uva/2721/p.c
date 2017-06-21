// @JUDGE_ID:  17051CA  2721  C++
// @begin_of_source_code
/* Grid --> Graph MST */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#define MAX 102

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
graph g;
char G[ MAX + 2 ][ MAX +2 ]; /* grid city + banpei*/
int CN[ MAX+ 2 ][ MAX + 2 ]; /* city number table */

int row, column;

void constructBridgeGraph(){
  int pre;
  int length;

  for ( int i = 1; i < row + 2; i++ ){
    pre = -1;
    length = 0;
    for ( int j = 1; j <= column; j++ ){
      if ( G[i][j] == '#' ){
	if ( !( pre == -1 || CN[i][j] == pre) ){
	  g.insert( pre, CN[i][j], length );
	  g.insert( CN[i][j], pre, length );
	} 
	pre = CN[i][j];
	length = 0;
      } else if ( G[i-1][j] == '#' ){
	if ( !( pre == -1 || CN[i-1][j] == pre) ){
	  g.insert( pre, CN[i-1][j], length );
	  g.insert( CN[i-1][j], pre, length );
	} 
	pre = CN[i-1][j];
	length = 0;
      } else {
	length++;
      }
    }
  }

  for ( int j = 1; j < column + 2; j++ ){
    pre = -1;
    length = 0;
    for ( int i = 1; i <= row; i++ ){
      if ( G[i][j] == '#' ){
	if ( !( pre == -1 || CN[i][j] == pre) ){
	  g.insert( pre, CN[i][j], length );
	  g.insert( CN[i][j], pre, length );
	} 
	pre = CN[i][j];
	length = 0;
      } else if ( G[i][j-1] == '#' ){
	if ( !( pre == -1 || CN[i][j-1] == pre) ){
	  g.insert( pre, CN[i][j-1], length );
	  g.insert( CN[i][j-1], pre, length );
	} 
	pre = CN[i][j-1];
	length = 0;
      } else {
	length++;
      }
    }
  }
}

void dfs( int i, int j, int cityNumber ){
  CN[i][j] = cityNumber;
  int nx, ny;
  for ( int r = 0; r < 8; r++ ){
    nx = i + dx[r];
    ny = j + dy[r];
    if ( G[nx][ny] == '#' && CN[nx][ny] == 0 ){
      dfs( nx, ny, cityNumber );
    }
  }
}

void determinCityNumber(){
  int cityNumber = 1;
  for ( int i = 1; i <= row; i++ ){
    for ( int j = 1; j <= column; j++ ){
      if ( G[i][j] == '#' && CN[i][j] == 0){
	dfs( i, j, cityNumber );
	cityNumber++;
      }
    }
  }
  g = graph( cityNumber );
}

void init(){
  for ( int i = 0; i < row + 2; i++ ){
    for ( int j = 0; j < column + 2; j++ ){
      CN[i][j] = 0;
    }
  }
}

void work(){
  init();
  determinCityNumber();

  constructBridgeGraph();

  vector<int> visited( g.size()+1, 0 );
  int ncomponent = 0;
  int length = 0;
  int nbridge = 0;
  for ( int u = 1; u <= g.size()-1; u++ ){
    if ( !visited[ u ] ){
      ncomponent++;
      int dist, nb;
      prim( g, u, visited, dist, nb );
      length += dist;
      nbridge += nb;
    }
  }

  if ( nbridge == 0 ){
    if ( ncomponent < 2 ) cout << "No bridges are needed." << endl;
    else {
      cout << "No bridges are possible." << endl;
      if ( ncomponent > 1 ) cout << ncomponent << " disconnected groups" << endl;
    }
  } else {
    cout << nbridge;
    if ( nbridge == 1 ) cout << " bridge";
    else cout << " bridges";
    cout << " of total length " << length << endl;
    if ( ncomponent > 1) cout << ncomponent << " disconnected groups" << endl;
  }
  
}

bool read(){
  cin >> row >> column;
  if ( row == 0 && column == 0 ) return false;

  for ( int i  = 0; i < row + 2; i++ ){
    for ( int j = 0; j < column + 2; j++ ){
      if ( i == 0 || j == 0 || i == row + 1 || j == column + 1 ){
	G[i][j] = ' ';
      }else {
	cin >> G[i][j];
      }
    }
  }

  return true;
}

main(){
  for ( int i = 0; read(); i++ ){
    if ( i ) cout << endl;
    cout << "City " << i + 1 << endl;
    work();
  }
}
// @end_of_source_code
