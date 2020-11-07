#include<iostream>
using namespace std;

bool overlap(int a, int b, int c, int d){
  if ( d <= a ) return false;
  if ( b <= c ) return false;
  return true;
}

int main(){
  int a, b, s, f, n;
  cin >> a >> b >> n;
  for ( int i = 0; i < n; i++ ){
    cin >> s >> f;
    if ( overlap(a, b, s, f) ){
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}

