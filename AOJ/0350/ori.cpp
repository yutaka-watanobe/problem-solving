#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int pow10(int a){
  int p = 1;
  for ( int i = 0; i < a; i++ ) p *= 10;
  return p;
}

int gcd(int x, int y){
  return y ? gcd(y, x%y) : x;
}

int print(int x, int y){
  int g = gcd(x, y);
  cout << x/g << "/" << y/g << endl;
}

main(){
  string in; cin >> in;
  int o, l, r;
  l = r = in.size(); r++;
  string all = "", sub = "";
  for ( int i = 0; i < in.size(); i++ ){
    if ( in[i] == '.' ){
      o = i;
    } else if ( in[i] == '(' ) {
      l = i;
      sub = all;
    } else if ( in[i] == ')' ){
      r = i;
    } else {
      all += in[i];
    }
  }

  if ( r-l-1 == 0 ){
    print(atoi(all.c_str()), pow10(l - o -1) );
  }else {
    print(atoi(all.c_str()) - atoi(sub.c_str()), pow10(l - o -1 + r-l-1) - pow10(l-o-1) );
  }
}
