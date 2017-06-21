#include<iostream>
using namespace std;
#define INFTY (1<<20)
#define MAX 1000

struct State{
  bool flag[2*MAX+2];
  int pre, maxv;
};

int ans[MAX+2];
int target;
int limit;

State state;

void dfs(int depth ){
  if ( state.pre == target ){
    ans[target] = min( ans[target], depth );
    return;
  }
  if ( depth >= ans[target] ) return;

  int d = 0;
  int p = state.maxv;
  while( p < target ){
    d++; p *= 2;
  }
  if ( depth + d >= ans[target] ) return;

  int next;
  State tmp = state;

  //  for ( int i = state.maxv; i >= 0; i-- ){
  for ( int i = 0; i <= state.maxv; i++ ){
    if ( !state.flag[i] ) continue;

    next = state.pre + i;
    if ( next <= MAX && !state.flag[next] ){
      state.flag[next] = true;
      state.pre = next;
      state.maxv = max( state.maxv, next );
      dfs(depth+1);
      state = tmp;
    }

    next = state.pre - i;
    if ( next >= 0 && !state.flag[next] ){
      state.flag[next] = true;
      state.pre = next;
      state.maxv = max( state.maxv, next );
      dfs(depth+1);
      state = tmp;
    }

    next = i - state.pre;
    if ( next >= 0 && !state.flag[next] ){
      state.flag[next] = true;
      state.pre = next;
      state.maxv = max( state.maxv, next );
      dfs(depth+1);
      state = tmp;
    }
  }
}


main(){
  for ( int i = 0; i <= MAX+1; i++ ) ans[i] = 13;
  int n;
  while(1){
    cin >> n;
    target = n;
    if ( n == 0 ) break;
    for ( int i = 0; i <= MAX+1; i++ ) state.flag[i] = false;
    state.flag[1] = true;
    state.maxv = 1;
    state.pre = 1;
    dfs(0);
    cout << ans[target] << endl;
  }
}
