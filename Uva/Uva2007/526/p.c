// @JUDGE_ID:  17051CA  526  C++
// @begin_of_source_code
/* Edit Distance */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define MATCH 0 /* enumerated type symbol for match */
#define INSERT 1 /* enumerated type symbol for insert */
#define DELETE 2 /* enumerated type symbol for delete */
#define SUBSTITUTE 3

class cell{
 public:
  int cost;
  int parent;
  cell(){}
};

/**
 * Edit Distance from text s to text t;
 */
class EditDistance{
 public:
  vector<vector<cell> > M;
  vector<int> P; /* path */
  
  int counter; /* sequence number of command */

  string s, t, current;
  int cursor;

  EditDistance( string s, string t ): s(s), t(t){
    M.resize( s.size() + 1 );
    for ( int i = 0; i < M.size(); i++ ){
      M[i].resize( t.size() + 1 );
    }
  }

  int getCost(){
    return M[ s.size() - 1 ][ t.size() - 1 ].cost;
  }

  void string_compare( ){
    s = ' ' + s;
    t = ' ' + t;
    int opt[ 3 ]; /* cost of the three options */
    
    /* init */
    for ( int i = 0; i < s.size(); i++ ) {
      M[i][0].cost = i;
      M[i][0].parent = DELETE;
    }
    
    for ( int j = 0; j < t.size(); j++ ) {
      M[0][j].cost = j;
      M[0][j].parent = INSERT;
    }
    M[0][0].parent = -1;
    
    for ( int i = 1; i < s.size(); i++ ){
      for ( int j = 1; j < t.size(); j++ ){
	opt[ MATCH ] = M[i-1][j-1].cost + ( s[i] == t[j] ? 0 : 1 ); /* match */
	opt[ INSERT ] = M[i][j-1].cost + 1; /* indel(t[j]) */
	opt[ DELETE ] = M[i-1][j].cost + 1; /* indel(s[i]) */
	M[i][j].cost = opt[ MATCH ];
	M[i][j].parent = MATCH;
	for ( int k = INSERT; k <= DELETE; k++ ){
	  if ( opt[k] < M[i][j].cost ){
	    M[i][j].cost = opt[k];
	    M[i][j].parent = k;
	  }
	}
      }
    }

    cout << getCost() << endl;
    
    counter = 1;
    cursor = 1;
    reconstruct_path( s.size()-1, t.size()-1 );
  }

  void reconstruct_path( int i , int j ){
    if ( M[i][j].parent == -1 ) return;

    if ( M[i][j].parent == MATCH ) {
      reconstruct_path( i-1, j-1 );
      match_out( i, j );
      return;
    }

    if ( M[i][j].parent == INSERT ){
      reconstruct_path( i, j-1 );
      insert_out( i, j );
      return;
    }

    if ( M[i][j].parent == DELETE ){
       reconstruct_path( i-1, j );
      delete_out( i, j );
      return;
    }
  }

  void match_out( int i, int j ){

    if ( s[i] == t[j] ){
      /* cout << "M" << endl; */
    } else {
      cout << counter++ << " Replace " << cursor << "," << t[j] << endl;
    }
    cursor++;
  }

  void insert_out( int i, int j ){
    cout << counter++ << " Insert " << cursor << "," << t[j] << endl;
    cursor++;
  }

  void delete_out ( int i, int j){
    cout << counter++ << " Delete " << cursor << endl;
  }

  void testPrint(){
    for ( int i = 0; i < s.size(); i++ ){
      for ( int j = 0; j < t.size(); j++ ){
	printf("%3d", M[i][j].cost);
      }
      cout << endl;
    }
    cout << endl;
    
    for ( int i = 0; i < s.size(); i++ ){
      for ( int j = 0; j < t.size(); j++ ){
	printf("%3d", M[i][j].parent);
      }
      cout << endl;
    }
    cout << endl;
  }
};

string source, target;

bool read(){
  getline( cin, source );
  if ( cin.eof() ) return 0;
  getline( cin, target );

  return true;
}

void work(){
  EditDistance ed = EditDistance( source, target );

  ed.string_compare();
}

main(){
  for ( int i = 0; read(); i++ ){
    if ( i ) cout << endl;
    work();
  }
}
// @end_of_source_code
