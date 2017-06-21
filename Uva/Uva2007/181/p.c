// @JUDGE_ID:  17051CA  181  C++
// @begin_of_source_code
/* Simulation - trump - Heart */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define HEART 2

class Card{
 public:
  int suit;
  int value;
  Card(){}
  Card(string str){
    switch( str[1] ){
    case 'C': 
      suit = 0; break;
    case 'D':
      suit = 1; break;
    case 'H':
      suit = 2; break;
    case 'S':
      suit = 3; break;
    }
    switch( str[0] ){
    case 'T':
      value = 10; break;
    case 'J':
      value = 11; break;
    case 'Q':
      value = 12; break;
    case 'K':
      value = 13; break;
    case 'A':
      value = 14; break;
    default:
      value = str[0] - '0';
    }
  }
};

class CardSortCriterion{
 public:
  bool operator() ( const Card &p1, const Card &p2 ) const {
    if( p1.value > p2.value ) return true;
    else if ( p1.value == p2.value ){
      if ( p1.suit > p2.suit ) return true;
      else return false;
    }else return false;
  }
};

vector<vector<Card> > D;
int trump_suit;

int read(){
  string str;
  D.clear();
  D.resize( 5 );

  Card card, t1, t2;

  for ( int i = 0; i < 50; i++ ){
    cin >> str; if ( str == "#" ) return 0;
    D[i%5].push_back( Card( str ) );
  }

  cin >> str;
  t1 = Card( str );
  cin >> str;
  t2 = Card( str );

  if ( t1.suit > t2.suit ) trump_suit = t1.suit;
  else if ( t1.suit < t2.suit ) trump_suit = t2.suit;
  else if ( t1.suit == t2.suit ){
    if ( t1.value > t2.value ) trump_suit = t1.suit;
    else trump_suit = t2.suit;
  }

  for ( int i = 0; i < 5; i++ ){
    sort( D[i].begin(), D[i].end(), CardSortCriterion() );
  }

  return 1;
}

Card Lead( int p ){
  Card candidate = D[p][0];
  int index = 0;

  if ( candidate.suit == trump_suit ) goto next;

  for ( int i = 1; i < D[p].size(); i++ ){
    if ( candidate.value != D[p][i].value ) break;
    if ( D[p][i].suit == trump_suit ){
      candidate = D[p][i];
      index = i;
      break;
    }

  }
 next:;  
  D[p].erase( D[p].begin() + index );
  return candidate;
}

Card Follow( int p, int lead_suit ){
  
  Card card;
  for ( int i = 0; i < D[p].size(); i++ ){
    if ( D[p][i].suit == lead_suit ){
      card = D[p][i];
      D[p].erase( D[p].begin() + i );
      return card;
    }
  }
  for ( int i = 0; i < D[p].size(); i++ ){
    if ( D[p][i].suit == trump_suit ){
      card = D[p][i];
      D[p].erase( D[p].begin() + i );
      return card;
    }
  }
  card = D[p][0];
  D[p].erase( D[p].begin() + 0 );
  return card;
}

bool isgreater(Card h, Card f){
  /* h < f ?? */
  if ( f.suit == trump_suit ){
    if ( h.suit == trump_suit ){
      if ( h.value < f.value ) return true;
      return false;
    }else{
      return true;
    }
  }else{
    if ( h.suit == trump_suit ){
      return false;
    }else{
      if ( h.value < f.value ) return true;
      else return false;
    }
  }
  cout << "incorrect " << endl;
}

void work(){
  int current_leader;
  int S[5];
  fill ( S, S+5, 0 );

  current_leader = 0;
  Card lead_card, followed_card, highest_card;
  int winner, score;

  for ( int k = 0; k < 10; k++ ){
    score = 0;
    lead_card = Lead( current_leader );
    if ( lead_card.suit == HEART ) score += lead_card.value;

    winner = current_leader;
    highest_card = lead_card;

    for ( int j = current_leader + 1; j < current_leader + 5; j++ ){
      int p = j % 5;
      followed_card = Follow( p, lead_card.suit );

      if ( followed_card.suit == HEART ) score += followed_card.value;

      if ( followed_card.suit != trump_suit && followed_card.suit != lead_card.suit ) continue;
      if ( isgreater( highest_card, followed_card ) ){
	winner = p;
	highest_card = followed_card;
      }
    }

    current_leader = winner;
    S[winner] += score;
  }

  for ( int i = 4; i < 9; i++ ){
    printf("%3d", S[i%5]);
  }
  cout << endl;
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
