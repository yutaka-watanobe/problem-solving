// @JUDGE_ID:  17051CA  439  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>

int read();
void work();
int getI(char);
int bfs(int, int);

string s1, s2;
int visited[8][8];

int read(){
  cin >> s1 >> s2;
  if( cin.eof() ) return 0;
  return 1;
}

void work(){
  int i, j, start, end;
  j = getI(s1[0]);
  i = s1[1] - '0'; 
  i--;
  start = i*8+j;
  j = getI(s2[0]);
  i = s2[1] - '0'; 
  i--;
  end = i*8+j;
  int cost = bfs(start, end);
  cout << "To get from " << s1 << " to " << s2 << " takes " << cost << " knight moves." << endl;
}

void init(){
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      visited[i][j] = 0;
    }
  }
}

int bfs(int start, int end){
  init();
  visited[start/8][start%8] = 1;

  queue<int> q;
  int pi, pj, ni, nj, i, j;

  q.push(start);
  int u;
  int cost = 0;

  while(!q.empty()){
    u = q.front(); q.pop();
    pi = u/8; pj = u%8;
    if(u==end){
      return visited[pi][pj]-1;
    }
    for(int d=0; d<8; d++){
      i = j = 0;
      if(d==0){ i-=2; j--; }
      if(d==1){ i--; j-=2; }
      if(d==2){ i++; j-=2; }
      if(d==3){ i+=2; j--; }
      if(d==4){ i+=2; j++; }
      if(d==5){ i++; j+=2; }
      if(d==6){ i--; j+=2; }
      if(d==7){ i-=2; j++; }
      ni = i + pi; nj = j + pj;
      if(ni >=0 && nj >= 0 && ni < 8 && nj < 8){
	if(visited[ni][nj]==0){
	  visited[ni][nj] = visited[pi][pj]+1;
	  q.push(ni*8+nj);
	}
      }
    }
  }
}

int getI(char c){
  int i;
  switch(c){
  case 'a':
    return 0;
  case 'b':
    return 1;
  case 'c':
    return 2;
  case 'd':
    return 3;
  case 'e':
    return 4;
  case 'f':
    return 5;
  case 'g':
    return 6;
  case 'h':
    return 7;
  }
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
