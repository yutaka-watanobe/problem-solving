// @JUDGE_ID:  17051CA  10401  C++
// @begin_of_source_code
/* Queen injured Problem */
/* Dynamic Programming !! */
/* 最後の列から計算していく (足し算のDPみたいな）*/
#include<stdio.h>
#include<iostream>
#include<string>
#define MAX 15
#define EMPTY 0
#define QUEEN 1
#define INJURED 2

int used[MAX][MAX];
long long G[MAX][MAX];

int N;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void init(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      used[i][j] = EMPTY;
      G[i][j] = 0;
    }
  }
}

/* 16 char --> int */
int hexCdec( char ch ) {
  if ( isdigit(ch) ) return ch-'0';
  else return (ch - 'A') + 10;
}

string line;

int read(){
  if(!(cin >> line)) return 0;
  N = line.size();
  
  init();
  int i;
  int ni, nj;

  for(int j=0; j<N; j++){
    if(line[j]!='?'){
      i = hexCdec(line[j])-1;

      used[i][j] = QUEEN;

      for(int r=0; r<8; r++){
	ni = i + dx[r];
	nj = j + dy[r];
	if(0 <= ni && 0 <= nj && ni < N && nj < N){
	  used[ni][nj] = INJURED;
	}
      }

      for(int r=i-1; r>=0; r--){
	used[r][j] = INJURED;
      }

      for(int r=i+1; r<N; r++){
	used[r][j] = INJURED;
      }
    }
  }
  return 1;
}

void work(){

  /* init last column */
  for(int i=0; i<N; i++) {
    if(used[i][N-1]==QUEEN) G[i][N-1] = 1;
    else if(used[i][N-1]==INJURED) G[i][N-1] = 0;
    else G[i][N-1] = 1;
  }
  
  for(int j=N-2; j>=0; j--){
    for(int i=0; i<N; i++){
      if(used[i][j]==INJURED){
	G[i][j] = 0;
      }else{
	long long sum = 0;
	for(int d=i+2; d<N; d++){
	  sum += G[d][j+1];
	}
	for(int u=i-2; u>=0; u--){
	  sum += G[u][j+1];
	}
	G[i][j] = sum;
      }
    }
  }

  long long sum = 0;
  
  for(int i=0; i<N; i++){
    sum += G[i][0];
  }

  cout << sum << endl;
}

main(){
  while(read()){
     work();
  }
}
// @end_of_source_code
