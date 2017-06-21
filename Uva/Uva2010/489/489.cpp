// 489:Hangman Judge:1.0:Simulation
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

bool used[256];

bool isWrongGuess(string word, char ch){
  if ( used[ch] ) return false;
  rep(i, word.size() ){
    if ( word[i] == ch ) return false;
  }
  used[ch] = true;
  return true;
}

bool solved(string cur){
  rep(i, cur.size() ) if ( cur[i] != ' ' ) return false;
  return true;
}

string compute(string word, string guess){
  int fail = 0;
  string cur = word;

  rep(i, 256) used[i] = false;

  for ( int i = 0; i < guess.size(); i++ ){
    char ch = guess[i];
    if ( isWrongGuess(word, ch) ) fail++;
    else {
      rep(s, word.size()){
	if( word[s] == ch ) cur[s] = ' ';
      }
    }

    if ( solved(cur) ) return "You win.";
    if ( fail >= 7 ) return "You lose.";
  }
  return "You chickened out.";
}

main(){
  string round, word, guess;
  while(1){
    cin >> round;
    if ( round=="-1") break;
    cout << "Round " << round << endl;
    cin >> word >> guess;
    cout << compute(word, guess) << endl;
  }
}
