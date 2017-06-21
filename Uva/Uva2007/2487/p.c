// @JUDGE_ID:  17051CA  2487  C++
// @begin_of_source_code
/* LIS ぽく */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

vector<pair<int, int> > T; /* input list */
string problemTitle;
int days;
int maxDayIndex;
int maxLollies;

void lis(){
  vector<int> L( days, 0 );
  vector<int> P( days, -1 ); /* pi */

  L[0] = T[0].first;

  maxDayIndex = -1;
  maxLollies = 0;

  for ( int i = 1; i < days; i++ ){
    int max_value = 0;
    int max_index = -1;
    for ( int j = 0; j <= i - 1; j++ ){
      if ( j + T[j].second > i ) continue; /* 日が十分にたっていない */
      if ( L[j] > max_value ){
	max_value = L[j];
	max_index = j;
      }
    }
    L[i] = T[i].first + max_value;
    P[i] = max_index;
    
    if( L[i] > maxLollies ){
      maxLollies = L[i]; maxDayIndex = i;
    }
  }

  /* print result */
  vector<int> path;
  int p = maxDayIndex;
  while ( 1 ){
    path.push_back( p );
    p = P[ p ];
    if ( p == -1 ) break;
  }
  reverse( path.begin(), path.end() );

  cout << "In " << problemTitle << " " << maxLollies;
  if ( maxLollies > 1 ) cout << " lollies ";
  else cout << " lolly ";
  cout << "can be obtained:" << endl;
  for ( int i = 0; i < path.size(); i++ ){
    cout << "On day " << path[i] + 1 ;
    int nlolly = T[ path[i] ].first;
    cout << " collect " << nlolly;
    if ( nlolly > 1 ) cout << " lollies." << endl;
    else cout << " lolly." << endl;
  }
}

void work(){
  lis();
}

bool read(){
  cin >> problemTitle;
  if ( problemTitle == "#" ) return false;

  T.clear();

  char ch;
  while ( 1 ){
    cin >> ch; cin.unget();
    if( !isdigit( ch ) ) {
      break;
    }

    int lolly, day;
    cin >> lolly >> day;
    T.push_back( make_pair( lolly, day ) );
  }

  days = T.size();
  return true;
}

main(){
  for ( int i = 0; read(); i++ ){
    if ( i ) cout << endl;
    work();
  }
}


// @end_of_source_code


