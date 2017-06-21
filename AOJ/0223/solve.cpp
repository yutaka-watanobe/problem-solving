#include<iostream>
#include<queue>
#include<map>
#include<cassert>

using namespace std;

const int dy[4] = {1,0,-1,0};
const int dx[4] = {0,1,0,-1};
const int MAX_SIZE = 50;
const int MIN_SIZE = 2;

class State{
public:
  int cost;
  int ay;
  int ax;
  int by;
  int bx;

  bool operator<(const State &state)const{
    if(ay != state.ay)
      return ay < state.ay;
    if(ax != state.ax)
      return ax < state.ax;
    if(by != state.by)
      return by < state.by;
    if(bx != state.bx)
      return bx < state.bx;
    return false;
  }
};

int r,c;
bool field[MAX_SIZE][MAX_SIZE];

bool isInside(int y,int x){
  return 0 <= y && y < r && 0 <= x && x < c;
}

void bfs(int ax,int ay,int bx,int by){
  queue<State> qu;
  State temp,state;
  map<State,bool> isExist;

  state.cost = 0;
  state.ay = ay;
  state.ax = ax;
  state.by = by;
  state.bx = bx;
  qu.push(state);

  while(!qu.empty()){
    state = qu.front();
    qu.pop();

    if(isExist[state] == false){
      isExist[state] = true;

      if(state.ay == state.by && state.bx == state.ax){
	cout << state.cost << endl;
	return;
      }

      for(int i = 0;i<4;i++){
	int aY = state.ay+dy[i],aX = state.ax+dx[i];
	int bY = state.by-dy[i],bX = state.bx-dx[i];
	if(!isInside(aY,aX) || !field[aY][aX]){
	  aY = state.ay;
	  aX = state.ax;
	}
	if(!isInside(bY,bX) || !field[bY][bX]){
	  bY = state.by;
	  bX = state.bx;
	}
	temp.cost = state.cost + 1;
	temp.by = bY;
	temp.bx = bX;
	temp.ax = aX;
	temp.ay = aY;
	qu.push(temp);
      }
    }
  }
  cout << "NA" << endl;
}

main(){
  while(cin >> c >> r && c){
    int ax,ay,bx,by;
    
    assert(MIN_SIZE <= r && r <= MAX_SIZE);
    assert(MIN_SIZE <= c && c <= MAX_SIZE);
    
    cin >> ax >> ay >> bx >> by;
    assert(1 <= ax && ax <= c);
    assert(1 <= ay && ay <= r);
    assert(1 <= bx && bx <= c);
    assert(1 <= by && by <= r);
    
    for(int i = 0;i<r;i++)
      for(int j = 0;j<c;j++){
	int inp;
	cin >> inp;
	assert(!(i+1 == ay && j+1 == ax && inp == 1));
	assert(!(i+1 == by && j+1 == bx && inp == 1));
	field[i][j] = inp != 1;
      }
    bfs(ax-1,ay-1,bx-1,by-1);
  }
  return 0;
}
