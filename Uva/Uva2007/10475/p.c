// @JUDGE_ID:  17051CA  10475  C++
// @begin_of_source_code
/* Recursive */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stl.h>
#define MAX 20

class Topic{
 public:
  string topic;
  int size;

  Topic(){}
  Topic( string topic ): topic(topic){
    size = topic.size();
  }

  bool operator < ( const Topic &t ) const{
    if ( size == t.size ){
      return topic < t.topic;
    } else {
      return size > t.size;
    }
  }
};

void toupper(string &s){
  for(int i=0; i<s.size(); i++)
    s[i] = toupper(s[i]);
}

class HelpTheLeaders{
 public:
  vector<Topic> T;
  map<int, string> ItoS;
  map<string, int> StoI;

  int P[ MAX ][ MAX ];
  bool used[ MAX ];
  int path[ 6 ];

  int t, p, s;


  bool prohibited( int index ){
    
    for ( int i = 0; i < t; i++ ){
      if ( !P[index][i] ) continue;
      
      if ( used[ i ] ) return true;

    }
    return false;
  }

  void recursive( int pos, int index ){

    if ( pos >= s ){
      for ( int i = 0; i < s; i++ ){
	if ( i ) printf(" ");
	printf("%s", ItoS[ path[i] ].c_str() );
      }
      printf("\n" );
      return;
    }

    for ( int i = index; i < t; i++ ){
      if ( !prohibited( i ) ){
	path[pos] = i;
	used[i] = true;
	recursive( pos + 1, i + 1 );
	used[i] = false;
      }
    }

  }

  void work(){
    for ( int i = 0; i < t; i++ ) used[i] = false;
    recursive( 0, 0 );
  }
  
  void init(){
    T.clear();
    T.resize( t );
    StoI.clear();
    ItoS.clear();
    for ( int i = 0; i < t; i++ ){
      for ( int j = 0; j < t; j++ ){
	P[i][j] = 0;
      }
    }
  }

  void read(){
    string line;
    cin >> t >> p >> s;
    init();

    for ( int i = 0; i < t; i++ ){
      cin >> line;
      toupper( line );
      T[i] = Topic( line );
    }
    sort( T.begin(), T.end() );

    for ( int i = 0; i < t; i++ ){
      string topic = T[i].topic;
      ItoS[ i ] = topic;
      StoI[ topic ] = i;      
    }

    /* prohibited pair */
    string p1, p2;
    for ( int i = 0; i < p ; i++ ){
      cin >> p1 >> p2;
      toupper( p1 );
      toupper( p2 );
      P[ StoI[p1] ][ StoI[p2] ] = 1;
      P[ StoI[p2] ][ StoI[p1] ] = 1;
    }


  }

};


main(){
  HelpTheLeaders HTL;
  int tcase;
  cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    printf("Set %d:\n", i );
    HTL.read();
    HTL.work();
    printf("\n");
  }

}

// @end_of_source_code


