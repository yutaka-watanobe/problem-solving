// @JUDGE_ID:  17051CA  462  C++
// @begin_of_source_code
/* Simulation Trump */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

class Card{
 public:
  int v, s;

  Card(){}
  Card( string str ){
    switch( str[0] ) {
    case 'T':
      v = 10; break;
    case 'J':
      v = 11; break;
    case 'Q':
      v = 12; break;
    case 'K':
      v = 13; break;
    case 'A':
      v = 14; break;
    default:
      v = str[0] - '0';
    }

    switch( str[1] ){
    case 'S':
      s = 1; break;
    case 'H':
      s = 2; break;
    case 'D':
      s = 3; break;
    case 'C':
      s = 4; break;
    }
  }

};

class CardSortCriterion{
 public:
  bool operator() ( const Card &c1, const Card &c2 ) const {
    if ( c1.s < c2.s ) return true;
    else if ( c1.s == c2.s ){
      if ( c1.v < c2.v ) return true;
      else return false;
    } else return false;
  }
};

vector< Card > C;

int read(){
  string str;
  C.clear();
  C.resize(13);
  for ( int i = 0; i < 13; i++ ){
    cin >> str;
    C[i] = Card( str );
  }
  if ( cin.eof() ) return 0;
  /* sort( C.begin(), C.end(), CardSortCriterion() ); */

  return 1;
}

void work(){
  int point = 0;
  int next_point;

  int V[15];
  int S[5];
  bool Stopped[5];

  fill( V, V+15, 0 );
  fill( S, S+5, 0 );
  fill( Stopped, Stopped+5, false );

  for ( int i = 0; i < C.size(); i++ ){
    V[ C[i].v ]++;
    S[ C[i].s ]++;
  }

  /* scheme 1 */
  point += V[14]*4;
  point += V[13]*3;
  point += V[12]*2;
  point += V[11];

  /* scheme 2, 3, 4 */
  for ( int i = 0; i < C.size(); i++ ){
    if ( C[i].v == 13 && S[ C[i].s ] == 1 ) point--;
    if ( C[i].v == 12 && S[ C[i].s ] <= 2 ) point--;
    if ( C[i].v == 11 && S[ C[i].s ] <= 3 ) point--;
  }

  next_point = point;

  for ( int i = 1; i <= 4; i++ ){
    if ( S[i] == 2 ) next_point += 1;
    if ( S[i] == 1 ) next_point += 2;
    if ( S[i] == 0 ) next_point += 2;
  }
  
  /* stopped ? */
  for ( int i = 0; i < C.size(); i++ ){
    if ( C[i].v == 14 ) Stopped[ C[i].s ] = true;
    if ( C[i].v == 13 ){
      if ( S[ C[i].s ] >= 2 ) Stopped[ C[i].s ] = true;
    }
    if ( C[i].v == 12 ){
      if ( S[ C[i].s ] >= 3 ) Stopped[ C[i].s ] = true;
    }
  }
  
  bool stopped = true;
  for ( int i = 1; i <= 4; i++ ){
    if ( !Stopped[i] ) stopped = false;
  }

  if ( point >= 16 && stopped ) cout << "BID NO-TRUMP" << endl;
  else if ( next_point >= 14 ){
    int suit = 1;
    int m = 0;
    for ( int i = 1; i <= 4; i++ ){
      if ( S[i] > m ){  m = S[i]; suit = i ;}
    }
    cout << "BID ";
    switch( suit ){
    case 1:
      cout << "S" << endl; break;
    case 2:
      cout << "H" << endl; break;
    case 3:
      cout << "D" << endl; break;
    case 4:
      cout << "C" << endl; break;
    }
  }else if ( next_point < 14 ){
    cout << "PASS" << endl;
  }

}

main(){
  while( read() ){
    work();
  }
}
// @end_of_source_code
