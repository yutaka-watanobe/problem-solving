#include<iostream>
#include<set>
using namespace std;

int main(){
  int N, M, h, m, t;
  set<int> S;
  cin >> N;
  for ( int i = 0; i < N; i++ ){
    cin >> h >> m;
    S.insert(h*60 + m);
  }
  cin >> M;
  for ( int i = 0; i < M; i++ ){
    cin >> h >> m;
    S.insert(h*60 + m);
  }

  int j = 0;
  for ( set<int>::iterator it = S.begin(); it != S.end(); it++, j++){
    if ( j ) cout << " ";
    t = *it;
    cout << t/60 << ":";
    t %= 60;
    if ( t < 10 ) cout << "0";
    cout << t;
  }
  cout << endl;

  return 0;
}
