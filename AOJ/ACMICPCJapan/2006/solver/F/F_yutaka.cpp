#include<iostream>
using namespace std;
#define MAX 1000
#define LIMIT 13

bool state[MAX+1];
int ans[MAX+1];
int target;

void dfs(int depth, int pre, int maxv ){
  if ( pre == target ){
    ans[target] = min( ans[target], depth );
    return;
  }
  if ( depth >= ans[target] ) return;

  int next, d = 0, p = maxv;

  while( p < target ){d++; p *= 2;}
  if ( depth + d >= ans[target] ) return;

  for ( int i = 1; i <= maxv; i++ ){
    if ( !state[i] ) continue;

    next = pre + i;
    if ( next <= MAX && !state[next] ){
      state[next] = true;
      dfs(depth+1, next, max(maxv, next));
      state[next] = false;
    }

    next = ( pre > i ) ? ( pre - i ) : (i - pre);
    if ( !state[next] ){
      state[next] = true;
      dfs(depth+1, next, max(maxv, next));
      state[next] = false;
    }
  }
}

main(){
  for ( int i = 0; i <= MAX+1; i++ ) ans[i] = LIMIT;
  while(cin >> target && target){
    for ( int i = 0; i <= MAX+1; i++ ) state[i] = false;
    state[1] = true;
    dfs(0, 1, 1);
    cout << ans[target] << endl;
  }
}
