// @JUDGE_ID:  17051CA  10315  C++
// @begin_of_source_code
/* Simulation Trump */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define TIE 0
#define BLACK 1
#define WHITE 2

#define HIGH_CARD 0
#define PAIR 1
#define TWO_PAIRS 2
#define THREE_OF_A_KIND 3
#define STRAIGHT 4
#define FLUSH 5
#define FULL_HOUSE 6
#define FOUR_OF_A_KIND 7
#define STRAIGHT_FLUSH 8

class Card{
 public:
  int value;
  int suit;
  
  Card(){}
  Card(string s){
    value = getValue( s[0] );
    suit = getSuit( s[1] );
  }

  int getValue(char c){
    if ( isdigit(c) ) {
      return c - '0';
    } else if ( c == 'T' ){
      return 10;
    } else if ( c == 'J' ){
      return 11;
    } else if ( c == 'Q' ){
      return 12;
    } else if ( c == 'K' ){
      return 13;
    } else if ( c == 'A' ){
      return 14;
    }
  }

  int getSuit(char c){
    if ( c == 'C') return 1;
    else if ( c == 'D' ) return 2;
    else if ( c == 'H' ) return 3;
    else if ( c == 'S' ) return 4;
  }

};

class CardSortCriterion{
 public:
  bool operator() ( const Card &c1, const Card &c2 ) const {
    if( c1.value < c2.value ) return true;
    else if ( c1.value == c2.value ){
      if ( c1.suit < c2.suit ) return true;
      else return false;
    }else return false;
  }
};

vector<Card> B, W;

int read(){
  W.clear();
  B.clear();
  W.resize(5);
  B.resize(5);
  string s;

  for ( int i = 0; i < 5; i++ ){
    cin >> s;
    B[i] = Card( s );
  }

  if ( cin.eof() ) return 0;

  for ( int i = 0; i < 5; i++ ){
    cin >> s;
    W[i] = Card( s );
  }

  sort ( B.begin(), B.end(), CardSortCriterion() );
  sort ( W.begin(), W.end(), CardSortCriterion() );
  return 1;
}

void poker( pair<int, int> &hand, vector<Card> C, vector<int> &next_hand ){
  int suit, value;
  int pre_v, pre_s;
  int max_v;
  bool straight, flush; 
  /* straigh ? or flash ? */
  max_v = 0;
  straight = true;
  flush = true;
  for ( int i = 0; i < C.size(); i++ ){
    if ( i ){
      if ( pre_v != C[i].value - 1 ) straight = false;
      if ( pre_s != C[i].suit ) flush = false;
    }
    pre_v = C[i].value;
    pre_s = C[i].suit;
    max_v = max( max_v, C[i].value );
  }

  if ( straight && flush ){
    hand.first = STRAIGHT_FLUSH;
    hand.second = max_v;
    return ;
  }

  /* straight ? */
  if ( straight ){
    hand.first = STRAIGHT;
    hand.second = max_v;
    return ;
  }

  /* flush ? */
  if ( flush ){
    hand.first = FLUSH;
    hand.second = HIGH_CARD;
    return ;
  }
  
  /* Four of a kind ? */
  max_v = 0;
  int same = 0;
  for ( int i = 0; i < C.size(); i++ ){
    if ( i ){
      if ( pre_v == C[i].value ) same++;
      if ( same == 3 ){
	hand.first = FOUR_OF_A_KIND;
	hand.second = C[i].value;
	return ;
      }
      if ( pre_v != C[i].value ) same = 0;
    }
    pre_v = C[i].value;
  }

  /* Full House ? */
  if ( C[0].value == C[1].value && C[1].value == C[2].value ){
    if ( C[3].value == C[4].value ){
      hand.first = FULL_HOUSE;
      hand.second = C[0].value;
      return ;
    }
  }

  if ( C[2].value == C[3].value && C[3].value == C[4].value ){
    if ( C[0].value == C[1].value ){
      hand.first = FULL_HOUSE;
      hand.second = C[4].value;
      return ;
    }
  }

  /* three of a kind ? */
  max_v = 0;
  same = 0;
  for ( int i = 0; i < C.size(); i++ ){
    if ( i ){
      if ( pre_v == C[i].value ) same++;
      if ( same == 2 ){
	hand.first = THREE_OF_A_KIND;
	hand.second = C[i].value;
	return ;
      }
      if ( pre_v != C[i].value ) same = 0;
    }
    pre_v = C[i].value;
  }
  
  /* Tow pair ? */
  if ( C[0].value == C[1].value && C[2].value == C[3].value ){
    hand.first = TWO_PAIRS;
    next_hand.push_back( max( C[0].value, C[2].value ) );
    next_hand.push_back( min( C[0].value, C[2].value ) );
    next_hand.push_back( C[4].value );
    return ;
  }else if ( C[0].value == C[1].value && C[3].value == C[4].value ){
    hand.first = TWO_PAIRS;
    next_hand.push_back( max( C[0].value, C[3].value ) );
    next_hand.push_back( min( C[0].value, C[3].value ) );
    next_hand.push_back( C[2].value );
    return ;
  }else if ( C[1].value == C[2].value && C[3].value == C[4].value ){
    hand.first = TWO_PAIRS;
    next_hand.push_back( max( C[1].value, C[3].value ) );
    next_hand.push_back( min( C[1].value, C[3].value ) );
    next_hand.push_back( C[0].value );
    return ;
  }

  /* One pair ? */

  if ( C[0].value == C[1].value ){
    hand.first = PAIR;
    next_hand.push_back( C[0].value );
    for ( int i = C.size()-1; i >= 0; i-- ){
      if ( i != 0 && i != 1 ) next_hand.push_back( C[i].value );
    }
    return ;
  }else if ( C[1].value == C[2].value ){
    hand.first = PAIR;
    next_hand.push_back( C[1].value );
    for ( int i = C.size()-1; i >= 0; i-- ){
      if ( i != 1 && i != 2 ) next_hand.push_back( C[i].value );
    }
    return ;
  }else if ( C[2].value == C[3].value ){
    hand.first = PAIR;
    next_hand.push_back( C[2].value );
    for ( int i = C.size()-1; i >= 0; i-- ){
      if ( i != 2 && i != 3 ) next_hand.push_back( C[i].value );
    }
    return ;
  }else if ( C[3].value == C[4].value ){
    hand.first = PAIR;
    next_hand.push_back( C[3].value );
    for ( int i = C.size()-1; i >= 0; i-- ){
      if ( i != 3 && i != 4 ) next_hand.push_back( C[i].value );
    }
    return ;
  }

  hand.first = HIGH_CARD;
  
}


void work(){

  pair<int, int> b_hand, w_hand;
  vector<int> b_next_hand, w_next_hand;
  poker( b_hand, B , b_next_hand);
  poker( w_hand, W , w_next_hand);
  
  int winner = TIE;
  
  if ( b_hand.first > w_hand.first ){
    winner = BLACK;
  } else if ( b_hand.first == w_hand.first ){
    int hand = b_hand.first;
    
    if ( hand == STRAIGHT_FLUSH || hand == FOUR_OF_A_KIND ||
	 hand == THREE_OF_A_KIND || hand == STRAIGHT || hand == FULL_HOUSE){
      if ( b_hand.second > w_hand.second ){
	winner = BLACK;
      }else if ( b_hand.second == w_hand.second ){
	winner = TIE;
      }else{
	winner = WHITE;
      }
      goto end;
    }
    
    if ( hand == TWO_PAIRS || hand == PAIR ){
      for ( int i = 0; i < b_next_hand.size(); i++ ){
	if ( b_next_hand[i] == w_next_hand[i] ) continue;
	if ( b_next_hand[i] > w_next_hand[i] ){
	  winner = BLACK;
	  goto end;
	}else{
	  winner = WHITE;
	  goto end;
	}
      }
    }
    
    /* High card rules*/
    if ( hand == HIGH_CARD || hand == FLUSH ){
      for ( int i = 4; i >= 0; i-- ){
	if ( B[i].value == W[i].value ) continue;
	if ( B[i].value > W[i].value ){
	  winner = BLACK;
	  goto end;
	}else{
	  winner = WHITE;
	  goto end;
	}
      }
    }
  } else {
    winner = WHITE;
  }

 end:;
  if ( winner == BLACK ) cout << "Black wins." << endl;
  else if ( winner == WHITE ) cout << "White wins." << endl;
  else cout << "Tie." << endl;
}

main(){
  while( read() ){
    work();
  }
}
// @end_of_source_code
