// @JUDGE_ID:  17051CA  572  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

int read();
void work();
void rec(int, int);

char grid[110][110];
int n, m;

int read(){
  cin >> n >> m;
  if( n==0 && m==0 ) return 0;
  return 1;
}

void work(){
  string line;
  for(int i=0; i<n; i++){
    cin >> line;
    for(int j=0; j<m; j++){
      grid[i][j] = line[j];
    }
  }

  int count = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(grid[i][j]=='@'){
	rec(i, j);
	count++;
      }
    }
  }

  cout << count << endl;
}

void rec(int i, int j){
  int ii, jj, ni, nj;
  for(int d=0; d<8; d++){
    ii = jj = 0;
    if(d==0) {ii++;}
    if(d==1) {jj++;}
    if(d==2) {ii--;}
    if(d==3) {jj--;}
    if(d==4) {ii++; jj++;}
    if(d==5) {ii++; jj--;}
    if(d==6) {ii--; jj++;}
    if(d==7) {ii--; jj--;}
    ni = ii + i; nj = jj + j;
    if( ni >=0 && nj >=0 && ni < n && nj < m){
      if(grid[ni][nj]=='@'){
	grid[ni][nj] = '*';
	rec(ni, nj);
      }
    }
  }
}
main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
