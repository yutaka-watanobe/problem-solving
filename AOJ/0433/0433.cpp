#include<iostream>
#include<algorithm>
using namespace std;

string P[12] = {"RBYG", "RGBY", "RYGB", "YGRB", "YBGR", "YRBG",
                "BYRG", "BGYR", "BRGY", "GBRY", "GYBR", "GRYB"};
int main(){
  char c1, c2;
  int x, y, n;
  cin >> c1 >> c2 >> n;
  for ( int i = 0; i < n; i++ ){
    cin >> x >> y;
    x %= 4;
    y %= 2;
    if ( y == 1 ) x = 3 - x;
    for (string p : P){
      if (p[0] == c1 && p[1] == c2 ){
        cout << p[x] << endl;
        break;
      }
    }
  }
  return 0;
}
