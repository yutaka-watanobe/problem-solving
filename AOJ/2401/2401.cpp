#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
string leftf, rightf, exp;
bool T[11], state;
int pos;

bool formula(){
  if ( exp[pos] == '-' ){
    pos++;
    return !formula();
  } else if ( exp[pos] == '(' ){
    pos++;
    bool x = formula();
    bool y, v;
    if ( exp[pos] == '+' ){
      pos++;
      y = formula();
      v = (x || y );
    } else if ( exp[pos] == '*' ){
      pos++;
      y = formula();
      v = (x && y );
    } else if ( exp[pos] == '-') {
      pos+=2;
      y = formula();
      v = (x&&!y)?false:true;
    }
    pos++; // )

    return v;
  } else if ( exp[pos] == 'T' ) {
    pos++;
    return true;
  } else if ( exp[pos] == 'F' ) {
    pos++;
    return false;
  } else {
    char ch = exp[pos];
    pos++;
    return T[ch-'a'];
  }
}

void rec(int p){
  if ( p == 11 ) {
    pos = 0;
    exp = leftf;
    bool l = formula();
    pos = 0;
    exp = rightf;
    bool r = formula();
    if ( l != r ) state = false;
    return;
  }
  T[p] = true;
  rec(p+1);
  T[p] = false;
  rec(p+1);
}

void solve(){
  state = true;
  rec(0);
  if ( state ) cout << "YES" << endl;
  else cout << "NO" << endl;
}

main(){
  string line;
  while(1){
    cin >> line;
    if ( line == "#" ) break;
    leftf = line.substr(0, line.find("="));
    rightf = line.substr(line.find("=")+1, line.size());
    solve();
  }
}
