// @JUDGE_ID:  17051CA  10604  C++
// @begin_of_source_code
/* too slow !! */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<map>
#include<set>

#define MAX 10

class Reaction{
 public:
  int target, cost;
  Reaction(){}
  Reaction( int target, int cost ): target(target), cost(cost){}
};

class ChemicalReaction{
 public:
  Reaction R[MAX][MAX];

  int n, k;

  void read(){
    cin >> n;
    int target, cost;
    for ( int i = 0; i < n ; i++ ){
      for ( int j = 0; j < n; j++ ){
	cin >> target >> cost;
	R[i][j] = Reaction(target-1, cost );
      }
    }
  }

  void work(){
    char kasu;

    cin >> k; 
    vector<int> tube;

    for ( int i = 0; i < k; i++ ){
      int t;
      cin >> t;
      tube.push_back( t - 1);
    }
    cin >> kasu;
    assert( kasu == '/' || kasu == '.' );

    map<vector<int>, int> cost;
    set<vector<int> > S;

    sort( tube.begin(), tube.end() );
    cost[ tube ] = 0;

    S.insert( tube );

    set<vector<int> >::iterator pos;
    set<vector<int> > ns;

    int cnt = 0;

    for ( int step = 0; step < k - 1 ; step++ ){
      //      cout << "step " << step << endl;
      //      cout << "size = " << S.size() << endl;
      ns.clear();
      for ( pos = S.begin(); pos != S.end(); pos++ ){
	vector<int> v = *pos;

	//		assert( v.size() == k - step );
	//		for ( int l = 0; l < v.size(); l++ ) cout << v[l] + 1<< " ";
	//		cout << "  cost = " << cost[v] << endl;

		
	for ( int i = 0; i < v.size(); i++ ){
	  for ( int j = 0; j < v.size(); j++ ){
	    if ( i == j ) continue;

	    vector<int> nv(v.size()-2);
	    int pos = 0;
	    for ( int m = 0; m < v.size(); m++ ){
	      if ( m == i || m == j ) continue;
	      nv[pos++] = v[m];
	      cnt++;
	    }
	    
	    nv.push_back( R[v[i]][v[j]].target );
	    sort( nv.begin(), nv.end() );
	    
	    if ( cost.find( nv ) == cost.end() ){
	      cost[nv] = cost[v] + R[v[i]][v[j]].cost;
	      ns.insert( nv );
	    } else {
	      if ( cost[nv] > cost[v] + R[v[i]][v[j]].cost ){
		cost[nv] = cost[v] + R[v[i]][v[j]].cost;
	      }
	    }
	  }
	}
      }
      S = ns;
    }

    int minimum = INT_MAX;

    for ( pos = S.begin(); pos != S.end(); pos++ ){
      if ( cost[*pos] < minimum ) minimum = cost[*pos];
    }

    cout << minimum << endl;
  }


};

main(){
  ChemicalReaction CR;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    CR.read();
    CR.work();
  }
}

// @end_of_source_code


