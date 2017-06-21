// @JUDGE_ID:  17051CA  10158  C++
// @begin_of_source_code
/* Grouping */
/* used belong table and group mapping */
/* Be careful about If statement ! */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#define NOTBELONG 0
int n; /* number of country */
vector<int> belong; /* where the country belongs to ? */
map<int, set<int> > group; /* where country the group has ? */
int current_groupID;

void inconsistent(){ cout << -1 << endl; }

void merge( int groupID1, int groupID2 ){
  set<int>::iterator pos;
  set<int> source = group[ groupID2 ];
  for ( pos = source.begin(); pos != source.end(); pos++ ){
    group[ groupID1 ].insert( *pos );
    belong[ *pos ] = groupID1;
  }
  group[ groupID2 ] = set<int>();
}

void mergeFriends( int groupID1, int groupID2 ){
  int sizeOfgroup1 = group[ groupID1 ].size() + group[ -groupID1 ].size();
  int sizeOfgroup2 = group[ groupID2 ].size() + group[ -groupID2 ].size();
  if ( sizeOfgroup1 > sizeOfgroup2 ){
    merge( groupID1, groupID2 );
    merge( -groupID1, -groupID2 );
  } else {
    merge( groupID2, groupID1 );
    merge( -groupID2, -groupID1 );
  }
}

void mergeEnemies( int groupID1, int groupID2 ){
  int sizeOfgroup1 = group[ groupID1 ].size() + group[ -groupID1 ].size();
  int sizeOfgroup2 = group[ groupID2 ].size() + group[ -groupID2 ].size();
  if ( sizeOfgroup1 > sizeOfgroup2 ){
    merge( groupID1, -groupID2 );
    merge( -groupID1, groupID2 );
  } else {
    merge( groupID2, -groupID1 );
    merge( -groupID2, groupID1 );
  }
}

void setFriends( int c1, int c2 ){
  /* valid check */
  if ( belong[ c1 ] == NOTBELONG || belong[ c2 ] == NOTBELONG ){
    if ( belong[ c1 ] == NOTBELONG && belong[ c2 ] == NOTBELONG ){
      current_groupID++;
      belong[ c1 ] = belong[ c2 ] = current_groupID;
      group[ current_groupID ].insert( c1 );
      group[ current_groupID ].insert( c2 );
    } else if ( belong[ c1 ] == NOTBELONG ){
      belong[ c1 ] = belong[ c2 ];
      group[ belong[ c2 ] ].insert( c1 );
    } else if ( belong[ c2 ] == NOTBELONG ){
      belong[ c2 ] = belong[ c1 ];
      group[ belong[ c1 ] ].insert( c2 );
    }
  } else {
    if ( belong[ c1 ] == -belong[ c2 ] ) inconsistent();
    else if ( belong[ c1 ] == belong[ c2 ] ){
      /* nothing */
    } else {
      mergeFriends( belong[c1], belong[c2] );
    }
  }
}

void setEnemies( int c1, int c2 ){
  if ( belong[ c1 ] == NOTBELONG || belong[ c2 ] == NOTBELONG ){
    if ( belong[ c1 ] == NOTBELONG && belong[ c2 ] == NOTBELONG ){
      current_groupID++;
      belong[ c1 ] = current_groupID;
      belong[ c2 ] = -current_groupID;
      group[ current_groupID ].insert( c1 );
      group[ -current_groupID ].insert( c2 );
    } else if ( belong[ c1 ] == NOTBELONG ){
      belong[ c1 ] = -belong[ c2 ];
      group[ -belong[ c2 ] ].insert( c1 );
    } else if ( belong[ c2 ] == NOTBELONG ){
      belong[ c2 ] = -belong[ c1 ];
      group[ -belong[ c1 ] ].insert( c2 );
    }
  } else {
    if ( belong[ c1 ] == belong[ c2 ] ) inconsistent();
    else if ( belong[ c1 ] == -belong[ c2 ] ){
      /* nothing */
    } else {
      mergeEnemies( belong[c1], belong[c2] );
    }
  }
}

void areFriends( int c1, int c2 ){
  if ( belong[ c1 ] == NOTBELONG || belong[ c2 ] == NOTBELONG ){
    cout << 0 << endl;
  } else {
    cout << (( belong[ c1 ] == belong[ c2 ] ) ? 1 : 0) << endl;
  }
}

void areEnemies( int c1, int c2 ){
  if ( belong[ c1 ] == NOTBELONG || belong[ c2 ] == NOTBELONG ){
    cout << 0 << endl;
  } else {
    cout << ( ( belong[ c1 ] == -belong[ c2 ] ) ? 1 : 0 ) << endl;
  }
}

void work(){
  int command, country1, country2;
  cin >> n;
  belong.resize( n, NOTBELONG );
  current_groupID = 0;
  while ( 1 ){
    cin >> command >> country1 >> country2;
    if ( command == 0 && country1 == 0 && country2 == 0 ) break;
    if ( command == 1 ){
      setFriends( country1, country2 );
    } else if ( command == 2 ){
      setEnemies( country1, country2 );
    } else if ( command == 3 ){
      areFriends( country1, country2 );
    } else if ( command == 4 ){
      areEnemies( country1, country2 );
    }
  }
}

main(){
  work();
}
// @end_of_source_code
