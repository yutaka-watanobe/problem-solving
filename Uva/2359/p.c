// @JUDGE_ID:  17051CA  2359  C++
// @begin_of_source_code
/* All Pair Shortest Path */
#include<stdio.h>
#include<iostream>
#include<string>
#include<climits>
#include<stl.h>
#include<vector>

class Candidate{
 public:
  string name;
  double distance;
  int mile;
  Candidate(){};
  Candidate( string name, double distance ): name(name), distance(distance){
    mile = (int)( distance + 0.5 );
  }

  bool operator < ( const Candidate &c ) const{
    if ( mile < c.mile ) return true;
    else if ( mile == c.mile ){
      return name < c.name;
    } else {
      return false;
    }
  }
};

/*
 * All-Pairs Shortest Path
 *
 *    d[i][j]:  shortest path from i to j
 *    pi[i][j]: the previout node of j, of d[i][j]
 * if d[x][x] is negative, then x is on a negative cycles.
 * check if there exist a path 1 - > v - > a 
 * where v is a vertex on negative cycle!
 * Solved 10449,
 */
void floyd(vector<vector<double> > &m, vector<vector<int> > &pi, vector<vector<double> > &d){
  int n = m.size();
  d = m;

  pi.assign( n, vector<int>( n, -1));

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      pi[i][j] = i;
      if(i!=j && d[i][j]==0) d[i][j] = INT_MAX;
    }
  }
  for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
      if(d[i][k]==INT_MAX) continue;
      for(int j=0; j<n; j++){
	if(d[k][j]==INT_MAX) continue;
	
	if(d[i][j]==INT_MAX || d[i][k]+d[k][j] < d[i][j]){
	  d[i][j] = d[i][k]+d[k][j];
	  pi[i][j] = pi[k][j];
	}
      }
    }
  }
}

vector<vector<double> > M;
vector<vector<int> > pi;
vector<vector<double > > d;
map<int, string> CM; /* city map */

int read(){
  int n, m, k;
  cin >> n >> m >> k;
  
  M.clear();
  M.resize( n );
  for ( int i = 0; i < n; i++ ) M[i].resize( n, 0.0 );
  CM = map<int, string>();
  
  int source, target;
  double dist;
  string city;

  for ( int i = 0; i < m; i++ ){
    cin >> source >> target >> dist;
    M[ source ][ target ] = dist;
    M[ target ][ source ] = dist;
  }

  for ( int i = 0; i < k; i++ ){
    cin >> source >> city;
    CM[ source ] = city;
  }
  
}

void searchCity( int start, int end, double dist){

  vector<Candidate> candidates;

  map<int, string>::iterator pos;

  for ( pos = CM.begin(); pos != CM.end(); pos++ ){
    int target = pos->first;

    int p = target;
    bool able = false;
    while ( 1 ){
      if ( p == start ) break;
      if ( p == end && pi[start][p] == start ) able = true;
      p = pi[start][p];
    }
    
    if ( able ){
      candidates.push_back( Candidate( pos->second, d[start][target] - dist ) );
    }
  }

  sort( candidates.begin(), candidates.end() );

  for ( int i = 0; i < candidates.size(); i++ ){
    string name = candidates[i].name;
    while ( name.size() < 20 ) name += ' ';
    cout << name << candidates[i].mile << endl;
  }

}

void work(){

  pi.clear();
  d.clear();

  floyd( M, pi, d );

  int query;
  int start, end;
  double dist;

  cin >> query;

  for ( int i = 0; i < query; i++ ){
    cin >> start >> end >> dist;
    if ( i ) cout << endl;
    searchCity( start, end, dist );
  }

}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
