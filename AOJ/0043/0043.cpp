#include<iostream>
#include<string>
#include<algorithm>
#include<cassert>
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
using namespace std;

int state[10];

bool valid2(int pos){
  if (pos == 4 ) return true;

  for ( int i = 1; i <= 9; i++){
    if ( state[i] >= 3 ){
      state[i] -= 3;
      if ( valid2(pos+1) ) return true;
      state[i] += 3;
    }
    if ( i >= 8 ) continue;
    if ( state[i] > 0 && state[i+1]> 0 && state[i+2]> 0 ){
      state[i]--;
      state[i+1]--;
      state[i+2]--;
      if ( valid2(pos+1) ) return true;
      state[i]++;
      state[i+1]++;
      state[i+2]++;
    }
  }
  return false;
}

bool valid(string str){
  sort(str.begin(), str.end());

  int cnt[10];
  for ( int i = 1; i <= 9; i++ ) cnt[i] = 0;
  for ( int i = 0; i < str.size(); i++ ) cnt[str[i]-'0']++;
  for ( int i = 1; i <= 9; i++ ) if (cnt[i] > 4) return false;

  for ( int i = 0; i < str.size()-1; i++ ){
    if ( str[i] == str[i+1] ){
      rep(p, 10) state[p] = 0;
      rep(j, str.size()){
	if ( j == i || j == i+1 ) continue;
	state[str[j]-'0']++;
      }
      if ( valid2(0))	return true;

    }
  }
  return false;
}

main(){
  string number;
  while( cin >> number){
    bool f = true;
    for ( char a = '1'; a <= '9'; a++ ){
      if ( valid(number + a) ){
	if ( !f ) cout << " ";
	cout << a;
	f = false;
      }
    }
    if ( f ) cout << "0" << endl;
    else cout << endl;
  }
}
