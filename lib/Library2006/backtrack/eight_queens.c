/********************
 * 8 queens problem *
 ********************/
/* 全てんのパタンをBacktrack により 出力 */
/* 回転,対称を考慮していないので遅い */

#include<stdio.h>
#include<iostream>
#define N 6
#define SUCCESS 1
#define FAIL 0
#define FREE 1
#define NOT_FREE 0
 
int row[N], col[N], pos[2*N-1], neg[2*N-1];
int sum;
int cnt;

void print(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(row[i]==j) cout << "Q";
      else cout << ".";
    }
    cout << endl;
  }
  cout << endl;
  sum++;
}

void tryqueen(int i, int j){
  cnt++;
  if(!(col[j]==FREE && pos[i+j]==FREE && neg[i-j+N-1]==FREE))
    return;
  
  row[i] = j; 
  col[j] = NOT_FREE;
  pos[i+j] = NOT_FREE;
  neg[i-j+N-1] = NOT_FREE;
  
  if(i==N-1){ print();}
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

main(){
  for(int i=0; i<N; i++) {row[i] = -1; col[i] = FREE;}
  for(int i=0; i<2*N-1; i++){pos[i] = FREE; neg[i] = FREE;}

  sum = 0;
  cnt = 0;
  for(int j=0; j<N; j++){
    tryqueen(0, j);
  }
  
  cout << cnt << endl;
}

