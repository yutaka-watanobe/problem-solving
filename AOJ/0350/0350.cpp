#include<iostream>
#include<cmath>
using namespace std;

int gcd(int x, int y){ return y ? gcd(y, x % y) : x; }

void print(int x, int y){
  int g = gcd(x, y);
  cout << x / g << "/" << y / g << endl;
}

int main(){
  string in; cin >> in;
  int o, p, l, r, d;
  string all, sub;
  o = in.find('.');
  p = in.find('(');
  d = in.size() - o - 1;
  if ( p == string::npos ){
    all = in.substr(0, o) + in.substr(o + 1, in.size() - o);
    print(stoi(all.c_str()), pow(10, d));
  } else {
    sub = in.substr(0, o) + in.substr(o + 1, p - o - 1);
    all = sub + in.substr(p + 1, in.size() - p - 2);
    l = p - o - 1;
    d -= 2; // ()の分を引く
    print(stoi(all.c_str()) - stoi(sub.c_str()), pow(10, d) - pow(10, l));
  }
  return 0;
}
