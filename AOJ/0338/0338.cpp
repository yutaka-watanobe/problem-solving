#include<iostream>
#include<cassert>
using namespace std;

int gcd(int a, int b){
  if ( b == 0 ) return a;
  return gcd(b, a % b);
}

int main(){
  int W, H, C;
  cin >> W >> H >> C;
  cout << (W / gcd(W, H)) * (H / gcd(W, H)) * C;
  cout << endl;
  return 0;
}
