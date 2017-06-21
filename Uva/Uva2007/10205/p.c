// @JUDGE_ID:  17051CA  10205  C++
// @begin_of_source_code
/* Simulation Card */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

vector<pair<int, int> > D; /* initial deck */
vector<pair<int, int> > S; /* curretn deck */
vector<vector<int> > P; /* patern of shuffle */
string line;

void init(){
  D.clear();
  for ( int suit = 1; suit <= 4; suit++ ){
    for ( int value = 2; value <= 14; value++ ){
      D.push_back( pair<int, int>(suit, value) );
    }
  }
  sort( D.begin(), D.end() );
}

string getValue(int v){
  if( 2 <= v && v <= 10 ){
    char a[20];
    sprintf(a, "%d", v);
    return string(a);
  }

  if ( v == 11 ) return "Jack";
  else if ( v == 12 ) return "Queen";
  else if ( v == 13 ) return "King";
  else if ( v == 14 ) return "Ace";
}

string getSuit(int s){
  if ( s == 1 ) return "Clubs";
  else if ( s == 2 ) return "Diamonds";
  else if ( s == 3 ) return "Hearts";
  else if ( s == 4 ) return "Spades";
}

int read(){
  /* init */
  P.clear();
  S = D;

  int k;
  getline( cin, line );
  k = atoi( line.c_str() );

  for ( int i = 0; i < k; i++ ){
    vector<int> v;
    v.resize(52);
    for ( int j = 0; j < 52; j++ ){
      cin  >> v[j];
    }
    P.push_back(v);
  }


}

void shuffle( int k ){
  vector<int> p;
  p = P[k-1];

  vector<pair<int, int> > tmp;
  tmp = S;

  for ( int i = 0; i < 52; i++ ){
    S[i] = tmp[ p[i]-1 ];
  }

}

void work(){
  int k;
  getline( cin, line ); /* line */

  while( 1 ){
    getline( cin, line );
    if( cin.eof() || line.empty() ) break;

    k = atoi( line.c_str() );
    
    shuffle( k );
  }
  
  for ( int i = 0; i < S.size(); i++){
    cout << getValue( S[i].second ) << " of " << getSuit( S[i].first) << endl;
  }

}

main(){
  init();

  int t;
  getline( cin, line);
  t = atoi( line.c_str() );

  getline(cin, line); /* line */ 

  for ( int i = 0; i < t; i++ ){
    if( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
