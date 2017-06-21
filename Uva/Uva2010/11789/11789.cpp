// 11789:Texas hold'em Poker Solitaire:4.0:Simulation, Poker
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

static const string CD[10] = {"", "Straight Flush", "Four of a Kind", "Full House", "Flush", "Straight", "Three of a Kind", "Two Pair", "One Pair", "High Cards"};

string IN[7][7];
string T[7];
string ansT[7];
string contT[5];

int getValue(int ch){
  if ( ch == 'A' ) return 14;
  if ( ch == 'K' ) return 13;
  if ( ch == 'Q' ) return 12;
  if ( ch == 'J' ) return 11;
  if ( ch == 'T' ) return 10;
  return (ch - '0');
}

bool isHigh(string card[5], int tie[5]){
  int v[5];
  rep(i, 5) v[i] = getValue(card[i][0]);
  sort(v, v+5);
  reverse(v, v+5);
  rep(i, 5) tie[i] = v[i];
  return true;
}

bool isOne(string card[5], int tie[5]){
  int v[5];
  rep(i, 5) v[i] = getValue(card[i][0]);
  sort(v, v+5);
  reverse(v, v+5);

  for ( int i = 0; i < 4; i++ ){
    if ( v[i] == v[i+1] ){ 
      int p = 0;
      rep(k, 5) if ( v[k] == v[i] ) tie[p++] = v[k];
      rep(k, 5) if ( v[k] != v[i] ) tie[p++] = v[k];
      assert(p==5);
      return true;
    }
  }
  return false;
}

bool isTwo(string card[5], int tie[5]){
  int v[5];
  rep(i, 5) v[i] =  getValue(card[i][0]);
  sort(v, v+5);
  reverse(v, v+5);

  if ( v[0] == v[1] && v[2] == v[3] ){
    tie[0] = v[0];
    tie[1] = v[2];
    tie[2] = v[4];
    return true;
  }
  if ( v[1] == v[2] && v[3] == v[4] ){
    tie[0] = v[1];
    tie[1] = v[3];
    tie[2] = v[0];
    return true;
  }
  if ( v[0] == v[1] && v[3] == v[4] ){
    tie[0] = v[0];
    tie[1] = v[3];
    tie[2] = v[2];
    return true;
  }
  return false;
}

bool isThree(string card[5], int tie[5]){
  int v[5];
  rep(i, 5) v[i] = getValue(card[i][0]);
  sort(v, v+5);
  reverse(v, v+5);

  if ( v[0] == v[1] && v[1] == v[2] ){
    tie[0] = v[0];
    tie[1] = v[3];
    tie[2] = v[4];
    return true;
  }
  if ( v[1] == v[2] && v[2] == v[3] ){
    tie[0] = v[1];
    tie[1] = v[0];
    tie[2] = v[4];
    return true;
  }
  if ( v[2] == v[3] && v[3] == v[4]) {
    tie[0] = v[2];
    tie[1] = v[0];
    tie[2] = v[1];
    return true;
  }
  return false;
}

bool isFour(string card[5], int tie[5]){
  int v[5];
  rep(i, 5) v[i] = getValue(card[i][0]);
  sort(v, v+5);
  reverse(v, v+5);

  if ( v[0] == v[1] && v[1] == v[2] && v[2] == v[3] ){
    tie[0] = v[0];
    tie[1] = v[4];
    return true;
  }
  if ( v[1] == v[2] && v[2] == v[3] && v[3] == v[4]) {
    tie[0] = v[1];
    tie[1] = v[0];
    return true;
  }
  return false;
}

bool isS(string card[5], int tie[5]){
  int v[5];
  rep(i, 5) v[i] = getValue(card[i][0]);
  sort(v, v+5);
  reverse(v, v+5);

  bool st = true;
  for ( int i = 1; i < 5; i++ ){
    if ( v[i-1] - 1 != v[i] ) st = false;
  }
  if ( st ) { 
    rep(i, 5) tie[i] = v[i];
    return true; 
  }

  rep(i, 5) if ( v[i] == 14 ) v[i] = 1;

  sort( v, v + 5);
  reverse( v, v + 5);
  
  st = true;
  for ( int i = 1; i < 5; i++ ){
    if ( v[i-1] - 1 != v[i] ) st = false;
  }
  if ( st ) {
    //rep(i, 5) if ( v[i] == 1 ) v[i] = 14;
    //sort(v, v+5); reverse( v, v+5);
    rep(i, 5) tie[i] = v[i];
    return true; 
  }
  return false;
}

bool isFlush(string card[5], int tie[5] ){
  int v[5];
  rep(i, 5) v[i] = getValue(card[i][0]);
  sort(v, v+5);
  reverse(v, v+5);

  char ch = card[0][1];
  for ( int i = 1; i < 5; i++ ){
    if ( ch != card[i][1] ) return false;
  }
  rep(i, 5) tie[i] = v[i];

  return true;
}

bool isFH(string card[5], int tie[5]){
  int v[5];
  rep(i, 5) v[i] = getValue(card[i][0]);
  sort(v, v+5);
  reverse(v, v+5);

  if ( v[0] == v[1] && v[1] == v[2] && v[3] == v[4]){
    tie[0] = v[0];
    tie[1] = v[3];
    return true;

  } 
  if ( v[0] == v[1] && v[2] == v[3] && v[3] == v[4] ){
    tie[0] = v[2];
    tie[1] = v[0];
    return true;

  }
  return false;
}

bool isSF(string card[5], int tie[5]){
 int v[5];
  rep(i, 5) v[i] = getValue(card[i][0]);
  sort(v, v+5);
  reverse(v, v+5);

  int tt[5];
  if (isS(card, tt) && isFlush(card, tt)){
    rep(i, 5) tie[i] = v[i];
    return true;
  }
  return false;
}

bool cmp( int ties[5], int tiet[5], int si ){
  static const int st[10] = {0, 1, 2, 2, 5, 1, 3, 3, 5, 5};
  int n = st[si];
  rep(i, n){
    if ( ties[i] == tiet[i] ) continue;
    return ties[i] > tiet[i];
  }
  return false;
}

int getScore( string tmp[5], int tief[5]){
  string cur[5];
  int hs = 1000;

  int tiet[5], ties[5];

  REP(a, 0, 3) REP(b, a+1, 4) REP(c, b+1, 5) REP(d, c+1, 6) REP(e, d+1, 7){
    cur[0] = T[a];
    cur[1] = T[b];
    cur[2] = T[c];
    cur[3] = T[d];
    cur[4] = T[e];
    
    if ( isSF(cur, ties) ){
      if ( 1 < hs || (1 == hs && cmp(ties,  tiet, 1) )){
	rep(i, 5) tmp[i] = cur[i]; 
	rep(i, 5) tiet[i] = ties[i];
	hs = 1;
      }
    } else if ( isFour(cur, ties) ){
      if ( 2 < hs || (2 == hs && cmp(ties, tiet, 2) )){
	rep(i, 5) tmp[i] = cur[i]; 
	rep(i, 5) tiet[i] = ties[i];
	hs = 2;
      }
    } else if ( isFH(cur, ties) ){
      if ( 3 < hs || (3 == hs && cmp(ties, tiet, 3) )){
	rep(i, 5) tmp[i] = cur[i];
	rep(i, 5) tiet[i] = ties[i];
	hs = 3;
      }
    } else if ( isFlush(cur, ties) ){
      if ( 4 < hs || (4 == hs && cmp(ties, tiet, 4) )){
	rep(i, 5) tmp[i] = cur[i]; 
	rep(i, 5) tiet[i] = ties[i];
	hs = 4;
      }
    } else if ( isS(cur, ties) ){
      if ( 5 < hs || (5 == hs && cmp(ties, tiet, 5) )){
	rep(i, 5) tmp[i] = cur[i]; 
	rep(i, 5) tiet[i] = ties[i];
	hs = 5;
      }
    } else if ( isThree(cur, ties) ){
      if ( 6 < hs || (6 == hs && cmp(ties, tiet, 6) )){
	rep(i, 5) tmp[i] = cur[i]; 
	rep(i, 5) tiet[i] = ties[i];
	hs = 6;
      }
    } else if ( isTwo(cur, ties) ){
      if ( 7 < hs || (7 == hs && cmp(ties, tiet,7) )){
	rep(i, 5) tmp[i] = cur[i]; 
	rep(i, 5) tiet[i] = ties[i];
	hs = 7;
      }
    } else if ( isOne(cur, ties) ){
      if ( 8 < hs || (8 == hs && cmp(ties, tiet, 8) )){
	rep(i, 5) tmp[i] = cur[i]; 
	rep(i, 5) tiet[i] = ties[i];
	hs = 8;
      }
    } else if ( isHigh(cur, ties) ){
      if ( 9 < hs || (9 == hs && cmp(ties, tiet, 9) )){
	rep(i, 5) tmp[i] = cur[i]; 
	rep(i, 5) tiet[i] = ties[i];
	hs = 9;
      }
    }
  }

  rep(i, 5) tief[i] = tiet[i];
  return hs;

}


void compute(){
  rep(i, 7) rep(j, 7) cin >> IN[i][j];
  int maxscore = 1000;
  int score;
  string tmp[5];
  int ties[5];
  int tiet[5];

  rep(i, 7){
    rep(j, 7) T[j] = IN[i][j];

    score = getScore(tmp, ties);
    if ( score < maxscore || (score == maxscore && cmp(ties, tiet, score) )){
      maxscore = score;
      rep(k, 5) contT[k] = tmp[k];
      rep(k, 7) ansT[k] = T[k];
      rep(i, 5) tiet[i] = ties[i];
    }
  }
  rep(j, 7){
    rep(i, 7) T[i] = IN[i][j];
    score = getScore(tmp, ties);
    if ( score < maxscore || (score == maxscore && cmp(ties, tiet, score) )){
      maxscore = score;
      rep(k, 5) contT[k] = tmp[k];
      rep(k, 7) ansT[k] = T[k];
      rep(i, 5) tiet[i] = ties[i];

    }
  }

  rep(j, 7) T[j] = IN[j][j];
  score = getScore(tmp, ties);
  if (  score < maxscore || (score == maxscore && cmp(ties, tiet, score) )){
    maxscore = score;
    rep(k, 5) contT[k] = tmp[k];
    rep(k, 7) ansT[k] = T[k];
    rep(i, 5) tiet[i] = ties[i];
  }

  rep(j, 7) T[j] = IN[7-j-1][j];
  score = getScore(tmp, ties);
  if (  score < maxscore || (score == maxscore && cmp(ties, tiet, score) )){
    maxscore = score;
    rep(k, 5) contT[k] = tmp[k];
    rep(k, 7) ansT[k] = T[k];
    rep(i, 5) tiet[i] = ties[i];
  }


  rep(i, 7){
    if ( i ) cout << " ";
    cout << ansT[i];
  }
  cout << "  ";
  rep(i, 5){
    if ( i ) cout << " ";
    cout << contT[i];
  }
  cout << "  ";
  cout << CD[maxscore] << endl;
  
}

main(){
  int tcase; cin >> tcase;
  rep(t, tcase) compute();
}
