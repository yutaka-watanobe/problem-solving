#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

int gcd(int x, int y){
  return y ? gcd(y, x%y) : x;
}

int print(int x, int y){
  int g = gcd(x, y);
  cout << x/g << "/" << y/g << endl;
}

main(){
  string in; cin >> in;
  int o, p, l, r, d;
  p = -1;
  string all, sub;
  for ( int i = 0; i < in.size(); i++ ){
    if ( in[i] == '.' ){
      o = i;
    } else if ( in[i] == '(' ) {
      p = i;
      sub = all;
    } else if ( in[i] == ')' ) {
    } else {
      all += in[i];
    }
  }
  d = in.size() - o - 1;
  l = p - o - 1;
  if ( p == -1 ){
    print(atoi(all.c_str()), pow(10, d));
  }else {
    d -= 2; // for ()
    print(atoi(all.c_str()) - atoi(sub.c_str()), pow(10, d) - pow(10, l) );
  }
}
