// @JUDGE_ID:  17051CA  841  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

#define MAX 20
#define SPACE 0
#define WALL 1
#define EGG 2

int grid[MAX][MAX];
int egg_cnt;
int N;

class Snake{
 public:
  int pi, pj, pos;
  vector<int> vbody;
  vector<vector<bool> > body;
  vector<vector<bool> > egg;
  vector<vector<bool> > visited;
  int e_cnt, cost;

  Snake(){}
  Snake(int s){
    body.resize(s);
    egg.resize(s);
    visited.resize(s);
    for(int i=0; i<s; i++){
      body[i].resize(s, false);
      egg[i].resize(s, false);
      visited[i].resize(s, false);
    }
    vbody.clear();
    vbody.push_back(0);
    body[0][0] = true;
    e_cnt = 0;
    cost = 0;
    pos = 0;
    pi = pj = 0;
  }

  void move(int i, int j){
    body[i][j] = true;
    vbody.insert(vbody.begin(), i*N+j);
    int tail = vbody[vbody.size()-1];
    body[tail/N][tail%N] = false;
    vbody.erase(vbody.end()-1);
    cost++;
    pi = i; pj = j;
  }

  void eat(int i, int j){
    body[i][j] = true;
    vbody.insert(vbody.begin(), i*N+j);
    egg[i][j] = false;
    e_cnt++; cost++;
    pi = i; pj = j;
    clear();
  }

  void clear(){
    visited.clear();
    visited.resize(N);
    for(int i=0; i<N; i++){
      visited[i].resize(N, false);
    }
  }

};


int goal;
void dfs(Snake);

void work(){
  string line;
  char c;
  Snake snake;
  cin >> N;
  egg_cnt = 0;
  snake = Snake(N);

  for(int i=0; i<N; i++){
    cin >> line;
    for(int j=0; j<N; j++){
      c = line[j];
      if(c=='-'){
	grid[i][j] = SPACE;
      }else if(c=='x'){
	grid[i][j] = WALL;
      }else if(c=='o'){
	grid[i][j] = SPACE;
	snake.egg[i][j] = true;
	egg_cnt++;
      }
    }
  }
  
  goal = INT_MAX;

  dfs(snake);

  if(goal==INT_MAX) cout << "NO" << endl;
  else cout << goal << endl;

}

void dfs(Snake snake){
//  cout << snake.pi << ", " << snake.pj << endl;
  Snake tmp;
  snake.visited[snake.pi][snake.pj] = true;
  if(snake.e_cnt==egg_cnt){
    if(goal>snake.cost) goal = snake.cost;
    return;
  }
  
  int ii, jj, ni, nj;
  for(int d=0; d<4; d++){
    ii = jj = 0;
    if(d==0) ii++;
    if(d==1) ii--;
    if(d==2) jj++;
    if(d==3) jj--;
    ni = snake.pi + ii; nj = snake.pj + jj;
    if(ni >=0 && nj >= 0 && ni < N && nj < N){
      if(grid[ni][nj]==SPACE && !snake.visited[ni][nj] && !snake.body[ni][nj]){
	if(snake.egg[ni][nj]){
	  tmp = snake;
	  tmp.eat(ni, nj);
	  dfs(tmp);
	}else{
	  tmp = snake;
	  tmp.move(ni, nj);
	  dfs(tmp);
	}
      }
    }
  }
}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    work();
  }
}
// @end_of_source_code
