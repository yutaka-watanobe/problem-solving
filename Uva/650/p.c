// @JUDGE_ID:  17051CA  650  C++
// @begin_of_source_code
/* Simulation - Bowling */ 
/* ! PE ! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

void split ( vector<int> &d, const string &s, char c=' ' ) {
  string t = "";
  d.clear();

  for ( int i = 0; i < s.size(); i++ ){    
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back( atoi(t.c_str()) ); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back( atoi(t.c_str()) );
}

class Bowl{
 public:
  string name;
  vector<int> play;
  int score1[10];
  int score2[10];
  bool finished1[10];
  bool finished2[10];
  int bpoint[10];
  int nbonus[10];
  int firstLast, secondLast;

  void init(){
    for ( int i = 0; i < 10; i++ ){
      score1[i] = 0;
      score2[i] = 0;
      bpoint[i] = 0;
      nbonus[i] = 0;
      finished1[i] = false;
      finished2[i] = false;
    }
  }

  void addBonus( int x ){
    for ( int i = 0; i < 10; i++ ){
      if ( nbonus[i] ){
	bpoint[i] += x;
	nbonus[i]--;
      }
    }
  }
  
  void work(){
    init();

    int pos = 0;
    int first, second;
    firstLast = -1;
    secondLast = -1;

    for ( int game = 0; game < 10; game++ ){
      if ( pos >= play.size() ) goto rest;
      first = 10 - play[pos++];

      if ( first == 10 ){
	score1[ game ] += 10;
	addBonus( 10 );
	nbonus[ game ] = 2;
	finished1[ game ] = true;
	finished2[ game ] = true;
	continue;
      } else {
	score1[ game ] += first;
	finished1[ game ] = true;
	addBonus( first );
      }

      if ( pos >= play.size() ) goto rest;

      second = 10 - play[ pos++ ] - first;

      if ( first + second == 10 ){
	score2[ game ] += second;
	addBonus( second );
	nbonus[ game ] = 1;
      } else {
	score2[ game ] += second;
	addBonus( second );
      }
      finished2[ game ] = true;

    }

    /* last 2 */
    if ( pos < play.size() ){
      firstLast = 10 - play[pos++];
      addBonus( firstLast );
    }
    if ( pos < play.size() ){
      if ( firstLast == 10 ){
	secondLast = 10 - play[pos];
	addBonus( secondLast );
      } else {
	secondLast = 10 - play[pos] - firstLast;
	addBonus( secondLast );
      }
    }
    
  rest:;

    printResult();
  }
  
  char getSymbol( int x ){
    if ( x == 10 ) return 'X';
    else if ( x == 0 ) return '-';
    else return x + '0';
  }

  void printResult(){
    int total = 0;
    while ( name.size() < 12 ) name += ' ';
    cout << name;

    for ( int i = 0; i < 10; i++ ){
      if ( !finished1[i] ) goto next1;
      cout << " ";
      cout << getSymbol( score1[i] );

      if ( !finished2[i] ) goto next1;

      if ( score1[i] == 10 ){
	if ( i != 9 ) cout << ' ';
      }else{
	if ( score1[i] + score2[i] == 10 ) cout << '/';
	else cout << getSymbol( score2[i] );
      }
      if ( i != 9 ) cout << " ";
    }

    /* last 2 */
    if ( firstLast != -1 ) cout << getSymbol( firstLast );
    if ( secondLast != -1 ){
      if ( firstLast == 10 ) cout << getSymbol( secondLast );
      else if ( firstLast + secondLast == 10 ) cout << '/';
      else cout << getSymbol( secondLast );
    }

  next1:;
    cout << endl;


    cout << "            ";
    for ( int i = 0; i < 10; i++ ){
      if ( !( finished1[i] && finished2[i] && nbonus[i] == 0 ) ) goto next2;
      total += score1[i] + score2[i] + bpoint[i];
      printf(" %3d", total );
    }
  next2:;
    cout << endl;

  }

  bool read(){
    string line;
    if ( !(cin >> name) ) return false;
    getline ( cin, line );
    split( play, line );
    return true;
  }

};

main(){
  Bowl B;
  for ( int i = 0; B.read(); i++ ){
    if ( i ) cout << endl;
    B.work();
  }
}

// @end_of_source_code


