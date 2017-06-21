// 11629:Ballot evaluation:2.0:Simulation, Parse, String split
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
#include<sstream>
using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

bool guess(string exp, map<string, int> &M){
  int left = 0, right = 0;
  string op;

  stringstream sin(exp);

  string name;
  while(1){
    sin >> name >> op;
    left += M[name];
    if ( op != "+" ) break;
  }
  sin >> right;
  right *= 10;
  
  if ( op == "<" ) return left < right;
  else if ( op == "<=" ) return left <= right;
  else if ( op == ">=" ) return left >= right;
  else if ( op == ">" ) return left > right;
  else if ( op == "=" ) return left == right;
}

main(){
  string line, name;
  int p, g, value, d, f;
  char ch;
  cin >> p >> g; getline(cin, line);
  map<string, int> M;

  rep(i, p){
    getline(cin, line);
    stringstream sin(line);
    sin >> name >> d >> ch >> f;
    value = d*10 + f;
    M[name] = value;
  }

  rep(i, g){
    getline(cin, line);
    string result = (guess(line, M)?"correct":"incorrect");
    cout << "Guess #" << i+1 << " was " << result << "." << endl;
  }


}
