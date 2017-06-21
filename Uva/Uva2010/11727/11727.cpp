#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define rep(i, n) for ( int i = 0; i < (int)n; i++)


int main(){
  int tcase; cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    cout << "Case " << i+1 << ": ";
    int v[3];
    rep(j, 3) cin >> v[j];
    sort(v, v+3);
    cout << v[1] << endl;
  }
  return 0;
}
