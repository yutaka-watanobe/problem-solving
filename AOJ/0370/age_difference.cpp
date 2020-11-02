#include<iostream>
using namespace std;

int main() {
  pair<int, pair<int,int>> p1, p2;

  cin >> p1.first >> p1.second.first
      >> p1.second.second;
  cin >> p2.first >> p2.second.first
      >> p2.second.second;

  if ( p1 > p2 ) swap(p1, p2);

  int ans = p2.first - p1.first;
  if (p1.second < p2.second) ans++;
  cout << ans << endl;
    
  return 0;
}
