// @JUDGE_ID:  17051CA  601  C++
// @begin_of_source_code
/* シミュレーション on Grid */

#include<stdio.h>
#include<iostream>
#include<string>
#define EMPTY 0
#define WHITE 1
#define BLACK 2
#define MAX 84

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int N;
int B[MAX][MAX], tmpB[MAX][MAX];
bool used[MAX][MAX];

int player;
bool has_winning_path;
bool has_one_move;
bool success;

void crear(){
  for(int i=0; i<MAX; i++){
    for(int j=0; j<MAX; j++){
      B[i][j] = EMPTY;
    }
  }
}

int read(){
  cin >> N;
  if(N==0) return 0;
  char ch;
  crear();
  for(int i=0; i<=N+1; i++){
    for(int j=0; j<=N+1; j++){
      if(i==0 || i==N+1 || j==0 || j==N+1){
	B[i][j] = EMPTY;
      }else{
	cin >> ch;
	if(ch=='W') B[i][j] = WHITE;
	else if(ch=='B') B[i][j] = BLACK;
	else B[i][j] = EMPTY;
      }
    }
  }
  return 1;
}

void init(){
  for(int i=0; i<=N+1; i++){
    for(int j=0; j<=N+1; j++){
      used[i][j] = false;
    }
  }
}

void dfs(int i, int j){

  used[i][j] = true;

  if(player==WHITE){
    if(j==N){
      success = true;
      return;
    }
  }else{
    if(i==N){
      success = true;
      return;
    }
  }

  int ni, nj;
  for(int d=0; d<4; d++){
    ni = i + dx[d];
    nj = j + dy[d];
    if(!used[ni][nj] && tmpB[ni][nj]==player ){
      dfs(ni, nj);
    }
  }
}

void work(){

  /* white has winning path ?? */
  player = WHITE;
  success = false;
  tmpB = B;
  for(int i=1; i<=N; i++){
    init();
    if(B[i][1]==player) dfs(i, 1);
    if(success){ cout << "White has a winning path." << endl; return;}
  }

  /* blac has winning path ?? */
  player = BLACK;
  success = false;
  tmpB = B;
  for(int j=1; j<=N; j++){
    init();
    if(B[1][j]==player) dfs(1, j);
    if(success){ cout << "Black has a winning path." << endl; return;}
  }

  /* white can win in one move ?? */
  player = WHITE;
  success = false;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if(B[i][j]==EMPTY){
	tmpB = B;
	tmpB[i][j] = player;
	for(int ii=1; ii<=N; ii++){
	  init();
	  if(tmpB[ii][1]==player) dfs(ii, 1);
	  if(success){ cout << "White can win in one move." << endl; return;}
	}
      }
    }
  }

  /* black can win in one move ?? */
  player = BLACK;
  success = false;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if(B[i][j]==EMPTY){
	tmpB = B;
	tmpB[i][j] = player;
	for(int jj=1; jj<=N; jj++){
	  init();
	  if(tmpB[1][jj]==player) dfs(1, jj);
	  if(success){ cout << "Black can win in one move." << endl; return;}
	}
      }
    }
  }

  cout << "There is no winning path." << endl;
}

main(){
  while(read()) {
    work();
    cout << endl;
  }
}
// @end_of_source_code
