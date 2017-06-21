// @JUDGE_ID:  17051CA  10384  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define N 0
#define E 1
#define S 2
#define W 3

class Cell{
 public:
  bool n, e, s, w;
};

class Maze{
 public:
  int pos, pi, pj;
  Cell grid[24];
  int used[24];
  string path;

  Maze(){}
  Maze(int a, int b){
    pi = a; pj = b;
    pos = pi*6+pj;
    for(int i=0; i<24; i++) used[i] = false;
    path = "";
  }

  bool canMove(int d){
    int next;
    if(d==N){
      if(pi-1>=0){
	next = (pi-1)*6+pj;
	if(!used[next]){
	  if(!grid[pos].n ){move(N); return true;}
	  else{
	    if(!grid[next].n){
	      push(pos, N, false); push(next, N, true); move(N); return true;
	    }
	  }
	}
      }
    }else if(d==E){
      if(pj+1<6){
	next = pi*6+pj+1;
	if(!used[next]){
	  if(!grid[pos].e ){move(E); return true;}
	  else{
	    if(!grid[next].e){
	      push(pos, E, false); push(next, E, true); move(E); return true;
	    }
	  }
	}
      }
    }else if(d==S){
      if(pi+1<4){
	next = (pi+1)*6+pj;
	if(!used[next]){
	  if(!grid[pos].s ){move(S); return true;}
	  else{
	    if(!grid[next].s){
	      push(pos, S, false); push(next, S, true); move(S); return true;
	    }
	  }
	}
      }
    }else if(d==W){
      if(pj-1>=0){
	next = pi*6+pj-1;
	if(!used[next]){
	  if(!grid[pos].w ){move(W); return true;}
	  else{
	    if(!grid[next].w){
	      push(pos, W, false); push(next, W, true); move(W); return true;
	    }
	  }
	}
      }
    }
    return false;
  }

  void push(int p, int d, bool t){
    int i, j, next;
    i = p/6; j = p%6;
    if(d==N){
      grid[p].n = t;
      if(i-1>=0) grid[(i-1)*6+j].s = t;
    }
    if(d==E){
      grid[p].e = t;
      if(j+1<6) grid[i*6+j+1].w = t;
    }
    if(d==S){
      grid[p].s = t;
      if(i+1<4) grid[(i+1)*6+j].n = t;
    }
    if(d==W){
      grid[p].w = t;
      if(j-1>=0) grid[i*6+j-1].e = t;
    }
  }

  void move(int d){
    if(d==N) {pi--; path += "N";}
    if(d==E) {pj++; path += "E";}
    if(d==S) {pi++; path += "S";}
    if(d==W) {pj--; path += "W";}
    pos = pi*6+pj;
    used[pos] = true;
    /*    cout << path << endl;*/
  }

  bool isexit(){
    if(0 <= pos && pos <= 5){
      if(!grid[pos].n) {
	path += "N";
	return true;
      }
    }
    if(18 <= pos && pos <= 23){
      if(!grid[pos].s){
	path += "S";
	return true;
      }
    }
    if( pos%6==0 ){
      if(!grid[pos].w){
	path += "W";
	return true;
      }
    }
    if( (pos+1)%6==0 ){
      if(!grid[pos].e){
	path += "E";
	return true;
      }
    }
    return false;
  }
};

int si, sj;
string goal;
void dfs(Maze);

int read(){
  cin >> sj >> si;
  if(si==0 && sj==0) return 0;
  si--; sj--;
  return true;
}

void work(){
  Maze maze;
  Cell c;
  int v;

  maze = Maze(si, sj);
  for(int i=0; i<24; i++){
    cin >> v;
    c.n = c.e = c.w = c.s = false;
    if(v==1) {c.w = true;}
    else if(v==2){c.n = true;}
    else if(v==3){c.w = c.n = true;}
    else if(v==4){c.e = true;}
    else if(v==5){c.w = c.e = true;}
    else if(v==6){c.n = c.e = true;}
    else if(v==7){c.w = c.n = c.e = true;}
    else if(v==8){c.s = true;}
    else if(v==9){c.s = c.w = true;}
    else if(v==10){c.n = c.s = true;}
    else if(v==11){c.n = c.w = c.s = true;}
    else if(v==12){c.e = c.s = true;}
    else if(v==13){c.w = c.s = c.e = true;}
    else if(v==14){c.n = c.e = c.s = true;}
    else if(v==15){c.w = c.n = c.e = c.s = true;}
    maze.grid[i] = c;
  }

  goal = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

  dfs(maze);

  cout << goal << endl;
}

void dfs(Maze maze){
  
  if(maze.isexit()){
    if(goal.size() > maze.path.size() ){
      goal = maze.path;
      return ;
    }
  }

  Maze m;
  /* N */
  m = maze;
  if(m.canMove(N)) dfs(m);
  /* E */
  m = maze;
  if(m.canMove(E)) dfs(m);
  /* S */
  m = maze;
  if(m.canMove(S)) dfs(m);
  /* W */
  m = maze;
  if(m.canMove(W)) dfs(m);
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
