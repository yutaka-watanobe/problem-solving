#include<iostream>
using namespace std;

int G[][2] = {{1, 2}, {-1, 3}, {1, -1}, {4, 5}, {5, 2}, {2, 1}}; // 地図

int main(){
  string p;
  while(1){
    cin >> p;
    if ( p[0] == '#' ) break;
    int cur = 0; // A市を出発
    for ( char c : p ){
      if ( cur == -1 ) break;
      cur = G[cur][c - '0'];
    }
    cout << (cur == 5 ? "Yes" : "No") << endl; // B市か判定
  }
  return 0;
}
