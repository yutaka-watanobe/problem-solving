#include <iostream>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

const int CMAX = 1000;
const int STMAX = 10000;
const int TMAX = 1260;

int n, m;
map<int, int> use[CMAX][STMAX];
bool a[STMAX][TMAX];

void init(void){
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      use[i][j].clear();
  for(int i = 0; i < m; ++i)
    fill(a[i], a[i]+TMAX, false);
}

int main(void){
  int r;
  while(cin >> n>> m){
    if((n|m) == 0) break;
    init();

    cin >> r;
    for(int i = 0; i < r; ++i){
      int t, com, st, s;
      cin >> t >> com >> st >> s;
      --com, --st;

      if(s == 1){ // login
	use[com][st].insert(make_pair(t, INT_MAX));
      }
      else{
	map<int, int>::iterator iter = use[com][st].upper_bound(t);
	--iter;
	iter->second = t;

	for(int j = iter->first; j < iter->second; ++j)
	  a[st][j] = true;
      }
    }

    cin >> r;
    for(int i = 0; i < r; ++i){
      int ts, te, st;
      cin >> ts >> te >> st;
      --st;

      int ans = 0;
      for(int j = ts; j < te; ++j)
	if(a[st][j])
	  ++ans;
      cout << ans << endl;
    }
  }
  return 0;
}
