// @JUDGE_ID:  17051CA  2355  C++
// @begin_of_source_code
/* Relation (Sorting) + DFS */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define MAX 27
#define NOTYET 0
#define INCONSISTENT 1
#define DETERMINED 2

int M[ MAX ][ MAX ];
int n, m;
int current;
int nrelation;
int decided;

void dfs( int u, vector<int> &U ){
  for ( int v = 0; v < n; v++ ){
    if ( M[u][v] && !U[v] ){
      U[v] = 1;
      dfs( v, U );
    }
  }
}

void checkDetermin( int source, int target ){
  if ( target == source ){
    decided = INCONSISTENT;
    nrelation = current;
    return ;
  }

  if ( M[target][source] ){
    decided = INCONSISTENT;
    nrelation = current;
    return ;
  }

  if ( M[ source ][ target ] ) return ;

  M[ source ][ target ] = 1;
  
  int nedge = 0;
  int allEdge = n*(n - 1)/2; /* summation of 1 to ( n - 1 ) = all possible relation */

  for ( int u = 0; u < n; u++ ){
    vector<int> U;
    U.resize( n, 0 );
    U[ u ] = 1;
   
    dfs( u, U );
    
    for ( int v = 0; v < n; v++ ){
      if ( U[ v ] && u != v ) {
	M[u][v] = 1;
	nedge++;
      }
    }
  }

  if ( nedge == allEdge ){
    decided = DETERMINED;
    nrelation = current;
  }
}

void printResult(){
  vector<pair<int, int> > deg( n, make_pair(0, 0 ) );

  for ( int u = 0; u < n; u++ ){
    deg[u].second = u;
    for ( int v = 0; v < n; v++ )
      if ( M[u][v] ) deg[u].first--;
  }
  sort( deg.begin(), deg.end() );
  
  for ( int i = 0; i < n; i++ ){
    cout << (char)(deg[i].second + 'A' );
  }
}

void work(){
  char ch1, ch2, op;
  decided = NOTYET;
  
  for ( int i = 1; i <= m; i++ ){
    cin >> ch1 >> op >> ch2;
    int source = ch1 - 'A';
    int target = ch2 - 'A';
    if ( decided > 0 ) continue;
    current = i;
    checkDetermin( source, target );
  }

  if ( decided == DETERMINED ){
    cout << "Sorted sequence determined after " << nrelation << " relations: ";
    printResult();
    cout << "." << endl;
  } else if ( decided == INCONSISTENT ){
    cout << "Inconsistency found after " << nrelation << " relations." << endl;
  } else {
    cout << "Sorted sequence cannot be determined." << endl;
  }
}

void init(){
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      M[i][j] = 0;
    }
  }
}

bool read(){
  cin >> n >> m;
  if ( n == 0 && m == 0 ) return false;
  init();
  return true;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
