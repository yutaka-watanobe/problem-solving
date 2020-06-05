#include<stdio.h>

char G[1000][1000];
int N;

int next(int i){ return ((N-i-1)+N)%N;}

int getState(int i, int j){
  return  G[i][j] == G[i][next(j)] &&
    G[i][j] == G[next(i)][j] &&
    G[i][j] == G[next(i)][next(j)];
}

int getInit(){
  int i, j, dcnt = 0;
  for ( i = 0; i < N/2; i++ ){
    for ( j = 0; j < N/2; j++ ){
      if (!getState(i, j)) dcnt++;
    }
  }
  return dcnt;
}

int main(){
  int i, j, k, r, c, C, dcnt, ans = 0, pre, post;
  char str[1001];
  scanf("%d %d", &C, &N);

  for ( i = 0; i < N; i++ ){
    scanf("%s", str);
    for ( j = 0; j < N; j++ ){
      G[i][j] = str[j];
    }
  }
  
  dcnt = getInit();
  if (dcnt == 0 ) ans++;
  for ( i = 0; i < C-1; i++ ){
    scanf("%d", &k);
    for (  j = 0; j < k; j++ ){
      scanf("%d %d", &r, &c); r--; c--;
      pre = getState(r, c);
      G[r][c] = G[r][c]=='1'?'0':'1';
      post = getState(r, c);
      if ( !pre && post ) dcnt--;
      else if ( pre && !post ) dcnt++;
    }
    if ( dcnt == 0 ) ans++;
  }

  printf("%d\n", ans);
  return 0;
}
