// @JUDGE_ID:  17051CA  532  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>

class Point{
 public:
  int i, j, k;
  Point(){}
  Point(int a, int b, int c){
    i = a;
    j = b;
    k = c;
  }
};

int read();
void work();
void init();
int bfs(Point, Point);

int i, j, k;
char dungeon[35][35][35];
int visited[35][35][35];

int read(){
  cin >> k >> i >> j;
  if( k==0 && i==0 && j==0) return 0;
  return 1;
}

void work(){
  string line;
  Point start, end;
  for(int c=0; c<k; c++){
    for(int a=0; a<i; a++){
      cin >> line;
      for(int b=0; b<j; b++){
	dungeon[a][b][c] = line[b];
	if(line[b]=='S'){
	  start = Point(a, b, c);
	}else if(line[b]=='E'){
	  end = Point(a, b, c);
	}
      }
    }
  }

  int cost = bfs(start, end);

  if(cost==-1){
    cout << "Trapped!" << endl;
  }else{
    cout << "Escaped in " << cost << " minute(s)." << endl;
  }
}

void init(){
  for(int c=0; c<k; c++){
    for(int a=0; a<i; a++){
      for(int b=0; b<j; b++){
	visited[a][b][c] = 0;
      }
    }
  }
}

int bfs(Point s, Point e){
  queue<Point> q;

  q.push(s);
  Point u, t;

  int ii, jj, kk, ni, nj, nk, pi, pj, pk;

  init();
  visited[s.i][s.j][s.k] = 1;

  while(!q.empty()){
    u = q.front(); q.pop();
    pi = u.i; pj = u.j; pk = u.k;
    
    if(pi == e.i && pj == e.j && pk == e.k){
      return visited[pi][pj][pk] - 1;
    }
     
    for(int d=0; d<6; d++){
      ii = jj = kk = 0;
      if(d==0)ii++;
      if(d==1)ii--;
      if(d==2)jj++;
      if(d==3)jj--;
      if(d==4)kk++;
      if(d==5)kk--;
      ni = ii+pi; nj = jj+pj; nk = kk+pk;
      if(ni >= 0 && nj >=0 && nk >= 0 && ni < i && nj < j && nk < k){
	if( visited[ni][nj][nk]== 0 && dungeon[ni][nj][nk] != '#'){
	  t = Point(ni, nj, nk);
	  visited[ni][nj][nk] = visited[pi][pj][pk] + 1;
	  q.push(t);
	}
      }
    }
  }

  return -1;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
