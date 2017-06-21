#include<stdio.h>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define MAX 20
#define EGG 2
#define SPACE 0
#define BLOCK 1

int n;
int grid[MAX][MAX];

class Snake{
 public:
  vector<int> body;
  bool visited[MAX];
  vector<int> eatList;
  int eat, cost;

  Snake(){
    body.clear();
    eatList.clear();
    body.push_back(0);
    eat = 0; cost = 0;
    init();
  }
  
  void init(){
    for(int i=0; i<n*n; i++){
      visited[i] = false;
    }
  }

  int move(int d){
    int i, j, ii, jj, ni, nj, npos;
    i = body[0]/n; j = body[0]%n; jj=0; ii=0;
    if(d==0) ii++;
    if(d==1) ii--;
    if(d==2) jj++;
    if(d==3) jj--;
    ni = ii+i; nj = jj+j; npos = ni*n+nj;
    if( ni>=0 && nj>=0 && ni<n && nj<n ){
      if(!isBody(npos) && !visited[npos] && !hasEat(npos)&& grid[ni][nj]!=BLOCK){
	if(grid[ni][nj]==EGG){
	  eat++; cost++;
	  body.insert(body.begin(), npos);
	  eatList.push_back(npos);
	  init();
	  visited[npos] = true;
	  return 2;
	}else{
	  cost++;
	  moveB(npos);
	  visited[npos] = true;
	  return 1;
	}
      }
    }
    return 0;
  }
  
  void moveB(int pos){
    for(int i=body.size()-1; i>=1; i--){
      body[i] = body[i-1];
    }
    body[0] = pos;
  }

  bool hasEat(int pos){
    for(int i=0; i<eatList.size(); i++){
      if(pos==eatList[i]) return true;
    }
    return false;
  }

  bool isBody(int pos){
    for(int i=0; i<body.size(); i++){
      if(pos==body[i]) return true;
    }
    return false;
  }
};


int goal, egg;
void work();
void bfs(Snake s);

void work(){
  string line;
  /* read */
  egg = 0;

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> line;
    for(int j=0; j<n; j++){
      if( line[j]=='o'){egg++;	grid[i][j] = EGG;}
      else if( line[j]=='x'){ grid[i][j] = BLOCK;}
      else {grid[i][j] = SPACE;}
    }
  }
			
  Snake snake = Snake();
  goal = 100000;
  snake.visited[0] = true;
  bfs(snake);
  
  if(goal==100000 ) cout << "NO" << endl;
  else{
    cout << goal << endl;
  }
}


void bfs(Snake snake){
  Snake s, u;
  queue<Snake> q;
  q.push(snake);
  int sig;
  while( !q.empty() ){
    u = q.front(), q.pop();
    if( u.eat == egg ){
      if( goal > u.cost ) {goal = u.cost; return;}
    }
    for(int d=0; d<4; d++){
      s = u;
      sig = s.move(d);
      if( sig == 1 ) q.push(s);
      else if(sig == 2 ){
	bfs(s);
      }
    }
  }


}

main(){
  int caseN;
  cin >> caseN;
  for(int i=0; i<caseN; i++){
    if(i!=0) cout << endl;
    work();
  }
}
