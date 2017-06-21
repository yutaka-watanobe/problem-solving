// @JUDGE_ID:  17051CA  131  C++
// @begin_of_source_code
/* Simulation Trump */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define HIGHEST_CARD 0
#define ONE_PAIR 1
#define TWO_PAIRS 2
#define THREE_KIND 3
#define STRAIGHT 4
#define FLUSH 5
#define FULL_HOUSE 6
#define FOUR_KIND 7
#define STRAIGHT_FLUSH 8

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

class Card{
 public:
  int v;
  int s;

  Card(){}
  Card( string str ){

    switch( str[0] ){
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
    case 'C':
      s = 1; break;
    case 'D':
      s = 2; break;
    case 'H':
      s = 3; break;
    case 'S':
      s = 4; break;
    }

  }


};

class CardSortCriterion{
 public:
  bool operator() ( const Card &c1, const Card &c2 ) const {
    if ( c1.v < c2.v ) return true;
    else if ( c1.v == c2.v ){
      if ( c1.s < c2.s ) return true;
      else return false;
    } else return false;
  }
};

string line;
vector< Card > H, D;

int read(){
  getline ( cin, line );

  if ( cin.eof() ) return 0;

  vector<string> com;
  split ( com, line );
  H.clear();
  D.clear();

  for ( int i = 0; i < 5; i++ ){
    H.push_back( Card(com[i]) );
  }
  for ( int i = 5; i < com.size(); i++ ){
    D.push_back( Card(com[i]) );
  }

  cout << "Hand: ";
  for ( int i = 0; i < 5; i++ ) cout << com[i] << " ";
  cout << "Deck: ";
  for ( int i = 5; i < 10; i++ ) cout << com[i] << " ";
  cout << "Best hand: ";

  return 1;
}

int judge(vector< Card > C){

  sort ( C.begin(), C.end(), CardSortCriterion() );

  /* straigh ? or flash ? */
  bool straight = true;
  bool flush = true;

  for ( int i = 0; i < C.size(); i++ ){
    if ( i ){
      if ( C[i-1].v != C[i].v - 1) straight = false;
      if ( C[i-1].s != C[i].s ) flush = false;
    }
  }

  /* exeption */
  if ( C[0].v == 2 && C[1].v == 3 && C[2].v == 4 && C[3].v == 5 && C[4].v == 14 ) straight = true;
  if ( C[0].v == 10 && C[1].v == 11 && C[2].v == 12 && C[3].v == 13 && C[4].v == 14 ) straight = true;

  if ( straight && flush ){
    return STRAIGHT_FLUSH;
  }
  
  /* Four of a kind ? */
  int same = 0;
  for ( int i = 0; i < C.size(); i++ ){
    if ( i ){
      if ( C[i-1].v == C[i].v ) same++;
      if ( same == 3 ){
	return FOUR_KIND;
      }
      if ( C[i-1].v != C[i].v ) same = 0;
    }
  }

  /* Full House ? */
  if ( C[0].v == C[1].v && C[1].v == C[2].v ){
    if ( C[3].v == C[4].v ){
      return FULL_HOUSE;
    }
  }
  if ( C[2].v == C[3].v && C[3].v == C[4].v ){
    if ( C[0].v == C[1].v ){
      return FULL_HOUSE;
    }
  }

  /* flush ? */
  if ( flush ) return FLUSH;

  /* straight ? */
  if ( straight ) return STRAIGHT;

  /* three of a kind ? */
  same = 0;
  for ( int i = 0; i < C.size(); i++ ){
    if ( i ){
      if ( C[i-1].v == C[i].v ) same++;
      if ( same == 2 ){
	return THREE_KIND;
      }
      if ( C[i-1].v != C[i].v ) same = 0;
    }
  }
  
  /* Tow pair ? */
  if ( C[0].v == C[1].v && C[2].v == C[3].v ){
    return TWO_PAIRS;
  }else if ( C[0].v == C[1].v && C[3].v == C[4].v ){
    return TWO_PAIRS;
  }else if ( C[1].v == C[2].v && C[3].v == C[4].v ){
    return TWO_PAIRS;
  }

  /* One pair ? */
  if ( C[0].v == C[1].v ){

  }else if ( C[1].v == C[2].v ){
    return ONE_PAIR;
  }else if ( C[2].v == C[3].v ){
    return ONE_PAIR;
  }else if ( C[3].v == C[4].v ){
    return ONE_PAIR;
  }
  
  return HIGHEST_CARD;
}

void work(){
  int hand = HIGHEST_CARD;
  vector< Card > C;
  int index;
  /* not discard */
  hand = max( hand, judge( H ) );

  /* discard 1 and discard 4 */
  for ( int i = 0; i < 5; i++ ){
    C = H;
    C[i] = D[0];
    hand = max( hand, judge( C ) );
    C = H;
    index = 0;
    for ( int j = 0; j < 5; j++ ){
      if ( i != j ) C[j] = D[index++];
    }
    hand = max( hand, judge( C ) );
  }
  
  /* discard 2 and discard 3 */
  for ( int i = 0; i < 4; i++ ){
    for ( int j = i+1; j < 5; j++ ){
      C = H;
      C[i] = D[0];
      C[j] = D[1];
      hand = max( hand, judge( C ));
      C = H;
      index = 0;
      for ( int k = 0; k < 5; k++ ){
	if ( k != i && k != j ) C[k] = D[index++];
      }
      hand = max( hand, judge( C ) );
    }
  }

  hand = max( hand, judge( D ) );

  switch( hand ){
  case STRAIGHT_FLUSH:
    cout << "straight-flush" << endl; break;
  case FOUR_KIND:
    cout << "four-of-a-kind" << endl; break;
  case FULL_HOUSE:
    cout << "full-house" << endl; break;
  case FLUSH:
    cout << "flush" << endl; break;
  case STRAIGHT:
    cout << "straight" << endl; break;
  case THREE_KIND:
    cout << "three-of-a-kind" << endl; break;
  case TWO_PAIRS:
    cout << "two-pairs" << endl; break;
  case ONE_PAIR:
    cout << "one-pair" << endl; break;
  default:
    cout << "highest-card" << endl;
  }
  
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
