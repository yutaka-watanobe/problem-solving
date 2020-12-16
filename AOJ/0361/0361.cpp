#include<iostream>
using namespace std;

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

int main(){
  int x, y;
  cin >> x >> y;
  cout << (x + 1) + (y + 1) - (gcd(x, y) - 1) - 2 << endl;
  return 0;
}
