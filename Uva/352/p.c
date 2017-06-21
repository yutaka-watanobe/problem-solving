// @JUDGE_ID:  17051CA  352  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

bool G[26][26], U[26][26];
int n;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int read(){
  string line;
  cin >> line;
  if(cin.eof()) return 0;
  n = atoi(line.c_str());
  char c;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> c;
      if(c=='1') G[i][j] = true;
      else G[i][j] = false;
      U[i][j] = false;
    }
  }
  return 1;
}

void rec(int x, int y){
  U[x][y] = true;

  int ni, nj;
  for(int i=0; i<8; i++){
    ni = x + dx[i];
    nj = y + dy[i];
    if(ni>=0 && nj>=0 && ni<n && nj<n && !U[ni][nj] && G[ni][nj]){
      rec(ni, nj);
    }
  }

}

int work(){
  int sum = 0;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(G[i][j] && !U[i][j]){
	sum++;
	rec(i, j);
      }
    }
  }

  return sum;
}

main(){
  for(int i=1; read(); i++){
    cout << "Image number " << i << " contains " << work() << " war eagles." << endl;
    work();
  }
}
// @end_of_source_code
