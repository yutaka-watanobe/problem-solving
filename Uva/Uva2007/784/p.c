// @JUDGE_ID:  17051CA  784  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

char maze[35][90];
vector<string> v;

void work();
void init();
void rec(int, int);

void init(){
  for(int i=0; i<35; i++){
    for(int j=0; j<90; j++){
      maze[i][j] = ' ';
    }
  }
}

void work(){
  string line;
  char buf[100];
  v.clear();
  while(1){
    cin.getline(buf, 100);
    line = buf;
    v.push_back(line);
    if( line[0]=='_' ){
      bool isEnd = true;
      for(int i=0; i<line.size(); i++){
	if( line[i]!='_') isEnd = false;
      }
      if(isEnd) break;
    }
  }

  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v[i].size(); j++){
      maze[i][j] = v[i][j];
    }
  }

  for(int i=0; i<35; i++){
    for(int j=0; j<90; j++){
      if( maze[i][j] == '*') rec(i, j);
    }
  }

  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v[i].size(); j++){
      v[i][j] = maze[i][j];
    }
  }

  for(int i=0; i<v.size(); i++){
    cout << v[i] << endl;
  }
}

void rec(int i, int j){
  maze[i][j] = '#';
  int ii, jj, ni, nj;
  for(int d=0; d<4; d++){
    ii = jj = 0;
    if(d==0) ii++;
    if(d==1) ii--;
    if(d==2) jj++;
    if(d==3) jj--;
    ni = ii+i; nj = jj+j;
    if( ni>=0 && nj>=0 && ni<35 && nj<90 ){
      if(maze[ni][nj]==' ') rec(ni, nj);
    }
  }
}

main(){
  char buf[1000];
  cin.getline(buf, 1000);
  int n;
  n = atoi(buf);
  for(int i=0; i<n; i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
