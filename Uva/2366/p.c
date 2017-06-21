// @JUDGE_ID:  17051CA  2366  C++
// @begin_of_source_code
/* Simple Graph Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<stl.h>
#define MAX 51

int M[ MAX ][ MAX ]; /* graph matrix */

class Table{
 public:
  string dump, neutralize;
  set<char> output;
  map<string, bool> U; /* used flag */

  Table(){}

  Table( string s1, string s2){
    if ( s1 == "." ) dump = "";
    else dump = s1;
    if ( s2 == "." ) neutralize;
    else neutralize = s2;
    output.clear();
  }

  

};

vector< Table > T;  /* list of Table instance */
int n;

void read(){
  cin >> n;
  T.clear();
  T.resize( n );

  string s1, s2;
  for ( int i = 0; i < n; i++ ){
    cin >> s1 >> s2;
    T[i] = Table( s1, s2 );
  }

  /* init */
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      M[i][j] = 0;
    }
  }

  int source, target;
  while ( 1 ){
    cin >> source >> target;
    if ( source == 0 && target == 0 ) break;
    M[ source - 1 ][ target - 1 ] = 1;
  }

}

void dfs( int x, string dust ){
  T[x].U[ dust ] = true;
  
  /* clearn */
  string neut = T[x].neutralize;

  for ( int j = 0; j < neut.size(); j++ ){
    for ( int i = 0; i < dust.size(); i++ ){
      if ( dust[i] == neut[j] ){
	dust.erase( dust.begin() + i );
	i--;
      }
    }
  }

  for ( int i = 0; i < dust.size(); i++ ){
    T[x].output.insert( dust[i] );
  }

  for ( int j = 0; j < n; j++ ){
    if ( M[x][j] && !T[j].U[ dust ] && dust.size() ){
      dfs( j, dust );
    }
  }

}

void printResult(){

  for ( int i = 0; i < T.size(); i++ ){
    cout << ":";
    set<char> out = T[i].output;
    set<char>::iterator pos;
    for ( pos = out.begin(); pos != out.end(); pos++ ){
      cout << *pos;
    }
    cout << ":" << endl;
  }

}

void work(){
  for ( int i = 0; i < n; i++ ){
    dfs( i, T[i].dump );
  }
  printResult();
}

main(){
  int t_case;
  cin >> t_case;
  for ( int i = 0; i < t_case; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
