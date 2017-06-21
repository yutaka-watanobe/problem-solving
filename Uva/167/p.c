// @JUDGE_ID:  17051CA  167  C++
// @begin_of_source_code
/* Backtrac 8 queens problem */

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define N 8
#define SUCCESS 1
#define FAIL 0
#define FREE 1
#define NOT_FREE 0

int grid[N][N];
vector<vector<int> > queen;

int maxK;

vector<int> row, col, pos, neg;

void checkanswer(){

  for(int q=0; q<queen.size(); q++){
    int sum = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
      if(queen[q][i]==j) sum += grid[i][j];
      }
    }
    maxK = max(maxK, sum);
  }
}

void tryqueen(int i, int j){

  if(!(col[j]==FREE && pos[i+j]==FREE && neg[i-j+N-1]==FREE))
    return;
  
  row[i] = j; 
  col[j] = NOT_FREE;
  pos[i+j] = NOT_FREE;
  neg[i-j+N-1] = NOT_FREE;
  
  if(i==N-1) {queen.push_back(row);}
  else{
    for(int z=0; z<N; z++){
      tryqueen(i+1, z);
    }
  }
  row[i] = -1;
  col[j] = FREE;
  pos[i+j] = FREE;
  neg[i-j+N-1] = FREE;
}

void read(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> grid[i][j];
    }
  }
}


void init(){
  row.resize(N, -1);
  col.resize(N, FREE);
  pos.resize(2*N-1, FREE);
  neg.resize(2*N-1, FREE);

  for(int j=0; j<N; j++){
    tryqueen(0, j);
  }
}

void work(){
  maxK = 0;
  for(int i=0; i<queen.size(); i++){
    checkanswer();
  }

  printf("%5d\n", maxK);

}

main(){
  init();
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    read();
    work();
  }
}
// @end_of_source_code
