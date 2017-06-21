// @JUDGE_ID:  17051CA  10305  C++ "topological sort"
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>

#define MAX 105

int read();
void work();
void init();
void topo(int);

int mat[MAX][MAX];
int visited[MAX];
vector<int> path;

int n, m;

int read(){
  cin >> n >> m;
  if( n == 0 && m == 0 ) return 0;
  else return 1;
}

void init(){
  for(int i=0; i<MAX; i++){
    for(int j=0; j<MAX; j++){
      mat[i][j] = 0;
    }
  }
  for(int i=0; i<MAX; i++){
    visited[i] = 0;
  }
  path.clear();
}

void work(){
  init();
  int i, j;
  for(int a=0; a<m; a++){
    cin >> i >> j;
    mat[i-1][j-1] = 1;
  }

  for(int u=0; u<n; u++){
    if( visited[u] == 0 ) topo(u);
  }
  
  for(int i=path.size()-1; i>=0; i--){
    printf("%d ", path[i]+1);
  }
  printf("\n");
}

void topo(int now){
  visited[now] = 1;
  for(int i=0; i<n; i++){
    if( visited[i] == 0 && mat[now][i] ){
      topo(i);
    }
  }
  path.push_back(now);
}

main(){
  while(read()){
    work();
  }
}

// @end_of_source_code
