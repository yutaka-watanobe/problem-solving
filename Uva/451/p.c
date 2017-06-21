// @JUDGE_ID:  17051CA  451  C++
// @begin_of_source_code
/* Simulation - Poker */
/* Fuckin input !! */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>
#define NOTHING 0
#define ONE_PAIR 1
#define TWO_PAIR 2
#define THREE_OF_A_KIND 3
#define STRAIGHT 4
#define FLUSH 5
#define FULLHOUSE 6
#define FOUR_OF_A_KIND 7
#define STRAIHGT_FLUSH 8
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

class Card{
 public:
  int rank;
  int suit;
  Card(){}
  Card( char c1, char c2 ){
    if ( c1 == 'A' ) rank = 1;
    else if ( c1 == 'X' ) rank = 10;
    else if ( c1 == 'J' ) rank = 11;
    else if ( c1 == 'Q' ) rank = 12;
    else if ( c1 == 'K' ) rank = 13;
    else{
      rank = c1 - '0';
    }
    if ( c2 == 'S' ) suit = 0;
    else if ( c2 == 'H' ) suit = 1;
    else if ( c2 == 'D' ) suit = 2;
    else if ( c2 == 'C' ) suit = 3;
  }
  
  /* ¾®¤µ¤¤½ç */
  bool operator < ( const Card &c ) const {
    if ( rank == c.rank ){
      return suit < c.suit;
    } else {
      return rank < c.rank;
    }
  }

};

Card deck[5][5];
Card currentDeck[5];
int counter[9];

void determin(){
  sort( currentDeck, currentDeck + 5 );

  int rankList[5];
  int suitList[5];
  for ( int i = 0; i < 5; i++ ){
    rankList[i] = currentDeck[i].rank;
    suitList[i] = currentDeck[i].suit;
  }

  bool isFlush = true;
  bool isStraight = true;

  /* is flush ? */
  for ( int i = 1; i < 5; i++ ){
    if ( suitList[i-1] != suitList[i] ) isFlush = false;
  }

  /* is straight ? */
  if ( currentDeck[0].rank == 1 ){
    if ( rankList[1] == 2 && rankList[2] == 3 && rankList[3] == 4 && rankList[4] == 5 ||
	 rankList[1] == 2 && rankList[2] == 3 && rankList[3] == 4 && rankList[4] == 13 ||
	 rankList[1] == 2 && rankList[2] == 3 && rankList[3] == 12 && rankList[4] == 13 ||
	 rankList[1] == 2 && rankList[2] == 11 && rankList[3] == 12 && rankList[4] == 13 ||
	 rankList[1] == 10 && rankList[2] == 11 && rankList[3] == 12 && rankList[4] == 13 ){
      /* ok */
    } else {
      isStraight = false;
    }
  } else {
    for ( int i = 1; i < 5; i++ ){
      if ( rankList[i-1] + 1 != rankList[i] ) isStraight = false;
    }
  }

  /* straight flush ? */
  if ( isFlush && isStraight ){
    counter[ STRAIHGT_FLUSH ]++;
    return ;
  }

  /* four of a kind ? */
  if ( rankList[0] == rankList[1] && rankList[1] == rankList[2] && rankList[2] == rankList[3] ||
       rankList[1] == rankList[2] && rankList[2] == rankList[3] && rankList[3] == rankList[4] ){
    counter[ FOUR_OF_A_KIND ]++;
    return ;
  }

  /* full house ? */
  if ( rankList[0] == rankList[1] && rankList[1] == rankList[2] && rankList[3] == rankList[4] ||
       rankList[0] == rankList[1] && rankList[2] == rankList[3] && rankList[3] == rankList[4] ){
    counter[ FULLHOUSE ]++;
    return ;
  }
       
  /* flush ? */
  if ( isFlush ){
    counter[ FLUSH ]++;
    return ;
  }

  /* stright ? */
  if ( isStraight ){
    counter[ STRAIGHT ]++;
    return;
  }

  /* three of a kind ? */
  if ( rankList[0] == rankList[1] && rankList[1] == rankList[2] ||
       rankList[1] == rankList[2] && rankList[2] == rankList[3] ||
       rankList[2] == rankList[3] && rankList[3] == rankList[4] ){
    counter[ THREE_OF_A_KIND ]++;
    return ;
  }
  
  /* two pair ? */
  if ( rankList[0] == rankList[1] && rankList[2] == rankList[3] ||
       rankList[0] == rankList[1] && rankList[3] == rankList[4] ||
       rankList[1] == rankList[2] && rankList[3]== rankList[4] ){
    counter[ TWO_PAIR ]++;
    return ;
  }


  /* one pair ? */
  if ( rankList[0] == rankList[1] ||
       rankList[1] == rankList[2] ||
       rankList[2] == rankList[3] ||
       rankList[3] == rankList[4] ){
    counter[ ONE_PAIR ]++;
    return ;
  }
       
  counter[ NOTHING ]++;
}


void work(){
  
  for ( int i = 0; i < 5; i++ ){
    for ( int j = 0; j < 5; j++ ){
      currentDeck[j] = deck[i][j];
    }
    determin();
  }

  for ( int j = 0; j < 5; j++ ){
    for ( int i = 0; i < 5; i++ ){
      currentDeck[i] = deck[i][j];
    }
    determin();
  }

  /* print result */
  for ( int i = 0; i < 9; i++ ){
    if ( i ) cout << ", ";
    cout << counter[i];
  }
  cout << endl;
}


bool read(){
  string line;
  vector<string> sp;

  fill ( counter, counter + 9, 0 );
  string str;
  for ( int i = 0; i < 5; i++ ){
    getline( cin, line );
    if ( line.size() == 0 || cin.eof() ) return false;
    split( sp, line );
    for ( int j = 0; j < 5; j++ ){
      string str = sp[j];
      deck[i][j] = Card( str[0], str[1] );
    }
  }
  return true;
}

main(){
  string line;
  int tcase;
  cin >> tcase;
  getline( cin, line );
  getline( cin, line );
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    while ( read() ){
      work();
    }
  }
}
// @end_of_source_code


