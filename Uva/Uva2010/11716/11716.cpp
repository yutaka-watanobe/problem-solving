#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#define EPS (1e-8)
using namespace std;

#define rep(i, n) for ( int i = 0; i < (int)n; i++)

bool isSquare(int x){
  double d = sqrt(x) + EPS;
  return x == (int)d*(int)d;
}

string convert(string str){
  int n = str.size();
  if ( !isSquare(n) ) return "INVALID";
  int c = (int)(sqrt(n)+EPS);
  int p = 0;
  string con = "";
  for ( int i = 0; i < c; i++){
    for ( int j = i; j < n; j += c){
      con += str[j];
    }
  }
  return con;
}

main(){
  int tcase; cin >> tcase;
  string line;
  getline(cin, line);
  rep(t, tcase){
    getline(cin, line);
    cout << convert(line) << endl;
  }
}
