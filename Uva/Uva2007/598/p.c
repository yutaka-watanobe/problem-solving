// @JUDGE_ID:  17051CA  598  C++
// @begin_of_source_code
/* Recursive */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 15

void split ( vector<string> &d, const string &s, char c=' ' ) {
  string t = "";
  d.clear();

  for ( int i = 0; i < s.size(); i++ ){    
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back(t);
}

class BundlingNewspaper {
 public:
  string P[ MAX ]; /* paper */
  int path[ MAX ];
  int npaper;
  vector<string> command;
  int size;

  void recursive( int pos, int len ){

    if ( len >= size ){
      for ( int i = 0; i < len; i++ ){
	if ( i ) printf(", ");
	printf("%s", P[path[i]].c_str() );
      }
      printf("\n");
      return;
    }

    for ( int i = pos ; i < npaper; i++ ){
      path[len] = i;
      recursive( i + 1, len + 1 );
    }


  }

  void work(){
    /* sort( P, P + npaper ); */
    
    if ( command.size() == 1 ){
      if ( command[0] == "*" ){
	for ( int s = 1; s <= npaper; s++ ){
	  printf("Size %d\n", s );
	  size = s;
	  recursive( 0, 0 );
	  printf("\n");
	}
      } else {
	int s = atoi( command[0].c_str() );
	printf("Size %d\n", s );
	size = s;
	recursive( 0, 0 );
	printf("\n");
      }
    } else if ( command.size() == 2 ) {
      int start = atoi( command[0].c_str() );
      int end = atoi( command[1].c_str() );
      for ( int s = start; s <= end; s++ ){
	size = s;
	printf("Size %d\n", s );
	recursive( 0, 0 );
	printf("\n");
      }
    } else {
      assert( false );
    }
  }

  bool read(){
    string line;
    getline( cin, line );
    command.clear();
    split( command, line );

    npaper = 0;
    while ( 1 ){
      getline( cin , line );
      if ( line.size() == 0 || cin.eof() ) return false;
      P[ npaper++ ] = line;
    }
  }

};

main(){
  int tcase;
  BundlingNewspaper BN;
  string line;
  cin >> tcase;

  getline( cin, line );
  getline( cin, line );

  for ( int i = 0; i < tcase; i++ ){
    if ( i ) printf("\n");
    BN.read();
    BN.work();
  }
}

// @end_of_source_code


