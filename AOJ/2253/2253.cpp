#include<iostream>
#include<queue>
#include<cassert>
#include<cmath>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define mp(a, b) make_pair(a, b)
typedef pair<pair<int, int>, int> State;

static const int MAX = 60;
static const int N =  2*MAX+1;
static const int dx[6] = {1, 1, 0, -1, -1, 0};
static const int dy[6] = {0, 1, 1, 0, -1, -1};
main(){
  bool O[N][N];
  int t, n, x, y, sx, sy;
  while(1){
    cin >> t >> n;
    assert( t <= 30 );

    if ( t == 0 && n == 0 ) break;
    rep(i, N) rep(j, N) O[i][j] = false;
    rep(i, n){
      cin >> x >> y;
      O[x+MAX][y+MAX] = true;
      assert( abs(x) <= 30 );
      assert( abs(y) <= 30 );
    }
    cin >> sx >> sy;
    sx += MAX;
    sy += MAX;
    queue<State> Q;
    State u;
    Q.push(mp(mp(sx, sy), 0));
    O[sx][sy] = true;
    int cnt = 0;
    while(!Q.empty()){
      u = Q.front(); Q.pop();

      cnt++;
      for ( int r = 0; r < 6; r++ ){
	int nx = u.first.first + dx[r];
	int ny = u.first.second + dy[r];
	if ( O[nx][ny] || u.second+1 > t) continue;
	O[nx][ny] = true;
	Q.push(mp(mp(nx, ny), u.second+1));
      }
    }
    cout << cnt << endl;
  }

}
