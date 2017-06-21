#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define N 8

bool isTen(char c){
  return (c == 'T' || c == 'J' || c== 'Q' || c == 'K');
}
bool isBlackjack(char c1, char c2){
  if ( c1 == 'A' ) swap(c1, c2);
  if ( c2 == 'A' && isTen(c1) ) return true;
  return false;
}

int getValue(char ch){
  return isTen(ch) ? 10 : (ch - '0');
}

void getScore(vector<char> H, int &score, bool &check11){
  int A = 0;
  score = 0;
  check11 = false;
  for ( int i = 0; i < H.size(); i++ ){
    if ( H[i] == 'A' ) { score++; A++; }
    else { score += getValue(H[i]);}
  }
  if ( A && score <= 11 ){
    check11 = true;
    score += 10;
  }
}

void simulate(char D[N+1], char c1, char c2){
  if ( isBlackjack(c1, c2) ) { cout << "blackjack" << endl; return; }
  vector<char> H;
  H.push_back(c1);
  H.push_back(c2);
  int score = 0;
  bool check11;
  for ( int i = 0; i < N+1; i++ ){
    char c = D[i];
    getScore(H, score, check11);
    if ( score > 21 ){
      cout << "bust" << endl; return;
    }
    if ( score <= 16 || (score == 17 && check11 )){
      H.push_back(c);
    } else {
      cout << score << endl; return;
    }
  }
}

main(){
  char D[N+1], c1, c2;
  int tcase; cin >> tcase;
  for ( int i = 0; i < tcase; i++ ) {
    cin >> c1 >> c2;
    for ( int j = 0; j < N; j++ ) cin >> D[j];
    D[N] = 0;
    simulate(D, c1, c2);
  }
}
