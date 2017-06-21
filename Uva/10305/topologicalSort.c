#include<stdio.h>
#include<vector>
#define MAX 7

void work();
void init();
void topo(int);

int mat[MAX][MAX];
int visited[MAX];
vector<int> path;

void init(){
  int m[MAX][MAX] = { {0, 1, 1, 0, 0, 0, 0},
		      {0, 0, 1, 0, 0, 0, 0},
		      {0, 0, 0, 1, 0, 0, 0},
		      {0, 0, 0, 0, 1, 1, 0},
		      {0, 0, 0, 0, 0, 0, 1},
		      {0, 0, 0, 0, 0, 0, 1},
		      {0, 0, 0, 0, 0, 0, 0} };
 
  memcpy(mat, m, sizeof(mat));

  for(int i=0; i<MAX; i++){
    visited[i] = 0;
  }
  path.clear();
}

void work(){
  init();
  topo(0);
  for(int i=path.size()-1; i>=0; i--){
    printf("%d ", path[i]);
  }
  printf("\n");
}

void topo(int now){
  visited[now] = 1;
  for(int i=0; i<MAX; i++){
    if( visited[i] == 0 && mat[now][i] ){
      topo(i);
    }
  }
  path.push_back(now);
}

main(){
  work();
}
