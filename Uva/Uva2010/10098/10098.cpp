// 594:Generating Fast, Sorted Permutation:1.0:Permulation
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

void compute(string str){
  char word[12];
  int l = str.size();
  rep(i, l) word[i] = str[i];
  word[l] = '\0';
  sort(word, word+l);
  do{
    printf("%s\n", word);
  } while( next_permutation(word, word+l));
}

main(){
  int tcase; cin >> tcase;
  rep(t, tcase){
    string str; cin >> str;
    compute(str);
    cout << endl;
  }
}
