#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100
int T[MAX], N;

void compute(){
  vector<pair<int, int> > ans;
  for ( int y = 0; ; y++ ){
    for ( int x = y; ; x++ ){
      if ( T[x] - T[y] > N ) break;
      if ( T[x] - T[y] == N ){
	ans.push_back(make_pair(y, x));
      }
    }
    if ( T[y+1] - T[y] > N ) break;
  }
  sort( ans.begin(), ans.end() );
  if ( ans.size() == 0 ) cout << "No solution" << endl;
  else {
    cout << ans[0].second << " " << ans[0].first << endl;
  }
}

main(){
  for ( int i = 1; i < MAX; i++ ) T[i] = i*i*i;
  while( cin >> N && N ) compute();
}
