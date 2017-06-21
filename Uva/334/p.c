// @JUDGE_ID:  17051CA  334  C++
// @begin_of_source_code
/* Transitive Closure */
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<vector>
#define MAX 100

class ConcurrentEvents{
 public:
  short M[ MAX ][ MAX ];
  map<string, int> NtoI;
  map<int, string> ItoN;
  int current;
  
  void warshall (){
    int n = current;
    for ( int y = 0; y < n; y++ ){
      for ( int x = 0; x < n; x++ ){
	if ( M[x][y] ){
	  for ( int i = 0; i < n; i++ ){
	    if ( M[y][i] )  M[x][i] = 1;
	  }
	}
      }
    }
  }

  int getIndex( string name ){
    if ( NtoI.find( name ) == NtoI.end() ){
      NtoI[ name ] = current;
      ItoN[ current ] = name;
      current++;
      return current - 1;
    } else {
      return NtoI[ name ];
    }
  }

  void work(){
    int n = current;

    warshall();

    int sum = 0;

    vector<pair<string, string> > v;

    for ( int i = 0; i < n; i++ ){
      for ( int j = i + 1; j < n; j++ ){
	if ( i == j ) continue;
	if ( !M[i][j] && !M[j][i] ){
	  sum++;
	  v.push_back( make_pair( ItoN[i], ItoN[j] ) );
	}
      }
    }

    if ( sum == 0 ) cout << "no concurrent events." << endl;
    else if ( sum == 1 ){
      cout << "1 concurrent events:" << endl;
      cout << "(" << v[0].first << "," << v[0].second << ") " << endl;
    } else if ( sum >= 2 ){
      cout << sum << " concurrent events:" << endl;
      cout << "(" << v[0].first << "," << v[0].second << ")" << " ";
      cout << "(" << v[1].first << "," << v[1].second << ") " << endl;
    }

  }

  void init(){
    current = 0;
    NtoI.clear();
    ItoN.clear();
    for ( int i = 0; i < MAX; i++ ){
      for ( int j = 0; j < MAX; j++ ) M[i][j] = 0;
    }
  }

  bool read(){
    init();
    int NC, NM, k;
    int pre, ev;
    string name, name1, name2;

    cin >> NC;
    if ( NC == 0 ) return false;

    for ( int i = 0; i < NC; i++ ){
      cin >> k;
      for ( int j = 0; j < k; j++ ){
	cin >> name;
	ev = getIndex( name );
	if ( j ){
	  M[ pre ][ ev ] = 1;
	}
	pre = ev;
      }
    }
    
    cin >> NM;
    for ( int i = 0; i < NM; i++ ){
	cin >> name1 >> name2;
	M[ NtoI[name1] ][ NtoI[name2] ] = 1;
    }

    return true;
  }
};

main(){
  ConcurrentEvents CE;
  for ( int i = 1; CE.read(); i++ ){
    cout << "Case " << i << ", ";
    CE.work();
  }
}

// @end_of_source_code


