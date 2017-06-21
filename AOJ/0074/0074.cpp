#include<iostream>
using namespace std;

void p(int x){
  if ( x < 10 ) cout << 0;
  cout << x;
}
void print(int r){
  int h = r/3600; r %= 3600;
  int m = r/60; r %= 60;
  int s = r;
  p(h); cout << ":";
  p(m); cout << ":";
  p(s); cout << endl;
}

main(){
  int h, m, s, r;
  while(1){
    cin >> h >> m >> s;
    if ( h < 0 ) break;
    r = 7200 - (3600*h+60*m+s);
    print(r);print(r*3);
  }
}
