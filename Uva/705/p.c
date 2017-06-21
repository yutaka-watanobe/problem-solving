// @JUDGE_ID:  17051CA 705  C++
// @begin_of_source_code
/* Maze DFS */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 100
#define BACK 0
#define FRONT 1
#define BORDER 2
#define TOP 0
#define BOTTOM 1

int M[MAX+2][MAX+2];
int w, h;

int TU[MAX+2][MAX+2]; /* top used */
int BU[MAX+2][MAX+2]; /* bottom used */
bool iscycle;
int sum, cnt;
int max_sum;

void dfs(int i, int j, int location ){
  if ( M[i][j] == BORDER ){
    iscycle = false;
    return;
  }

  if ( location == TOP ) TU[i][j] = 1;
  else if ( location == BOTTOM ) BU[i][j] = 1;
  sum++;
  int ni, nj;

  if ( location == TOP ){
    if ( M[i][j] == FRONT ){
      ni = i-1; nj = j;
      if ( M[ni][nj] == BORDER ) dfs ( ni, nj, BORDER );
      else if ( !BU[ni][nj] ) dfs ( ni, nj, BOTTOM );
      ni = i; nj = j-1;
      if ( M[ni][nj] == BORDER ) dfs( ni, nj, BORDER );
      else if ( M[ni][nj] == FRONT && !BU[ni][nj]) dfs (ni, nj, BOTTOM );
      else if ( M[ni][nj] == BACK && !TU[ni][nj]) dfs (ni, nj, TOP);
    }else if ( M[i][j] == BACK ){
      ni = i-1; nj = j;
      if ( M[ni][nj] == BORDER ) dfs( ni, nj, BORDER );
      else if ( !BU[ni][nj] ) dfs ( ni, nj, BOTTOM );
      ni = i; nj = j+1;
      if ( M[ni][nj] == BORDER ) dfs( ni, nj, BORDER );
      else if ( M[ni][nj] == FRONT && !TU[ni][nj]) dfs (ni, nj, TOP );
      else if ( M[ni][nj] == BACK && !BU[ni][nj]) dfs (ni, nj, BOTTOM);
    }
  }else if ( location == BOTTOM ){
    if ( M[i][j] == FRONT ){
      ni = i+1; nj = j;
      if ( M[ni][nj] == BORDER ) dfs( ni, nj, BORDER );
      else if ( !TU[ni][nj] ) dfs ( ni, nj, TOP );
      ni = i; nj = j+1;
      if ( M[ni][nj] == BORDER ) dfs( ni, nj, BORDER );
      else if ( M[ni][nj] == FRONT && !TU[ni][nj] ) dfs( ni, nj, TOP );
      else if ( M[ni][nj] == BACK && !BU[ni][nj] ) dfs( ni, nj, BOTTOM );
    }else if ( M[i][j] == BACK ){
      ni = i+1; nj = j;
      if ( M[ni][nj] == BORDER ) dfs( ni, nj, BORDER );
      else if ( !TU[ni][nj] ) dfs ( ni, nj, TOP );
      ni = i; nj = j-1;
      if ( M[ni][nj] == BORDER ) dfs( ni, nj, BORDER );
      else if ( M[ni][nj] == FRONT && !BU[ni][nj] ) dfs( ni, nj, BOTTOM );
      else if ( M[ni][nj] == BACK && !TU[ni][nj] ) dfs( ni, nj, TOP );
    }
  }
}

void start_dfs(int i, int j, int l ){
  iscycle = true;
  sum = 0;
  dfs( i, j, l );
  if ( iscycle ){
    /*   cout << sum << endl; */
    cnt++;
    max_sum = max( max_sum, sum );
  }
}

void work(){
  for ( int i = 0; i <= h+1; i++ ){
    fill ( TU[i], TU[i] + w+2, 0 );
    fill ( BU[i], BU[i] + w+2, 0 );
  }
  
  /* init */
  max_sum = 0;
  cnt = 0;
  for ( int i = 1; i <= h; i++ ){
    for ( int j = 1; j <= w; j++ ){
      if ( !TU[i][j] ) start_dfs(i, j, TOP );
      if ( !BU[i][j] ) start_dfs(i, j, BOTTOM );
    }
  }

  if ( cnt > 0 ){
    cout << cnt << " Cycles; the longest has length " << max_sum << "." << endl;
  }else{
    cout << "There are no cycles." << endl;
  }


}


int read(){
  cin >> w >> h;
  if ( w == 0 && h == 0 ) return 0;
  char ch;

  for ( int i = 0; i <= h+1; i++ ){
    for ( int j = 0; j <= w+1; j++ ){
      if ( i == 0 || j == 0 || i == h+1 || j == w+1 ){
	M[i][j] = BORDER;
      }else {
	cin >> ch;
	if ( ch == '/' ) M[i][j] = FRONT;
	else if ( ch == '\\' ) M[i][j] = BACK;
      }
    }
  }

  return 1;
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Maze #" << i << ":" << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
