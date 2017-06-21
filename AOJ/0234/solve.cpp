#include<iostream>
#include<queue>
#include<vector>
#include<map>

using namespace std;

const int MAX_ROW = 10;
const int MAX_COLUMN = 10;
const int MAX_LIMITOFOXYGEN = 50;
const int MAX_NUMOFOXIGYGEN = 50;
const int dy[3] = {1,0,0};
const int dx[3] = {0,1,-1};
int field[MAX_ROW][MAX_COLUMN];
bool isOxygenCell[MAX_ROW][MAX_COLUMN];
int MD[MAX_ROW][MAX_COLUMN];
int r,c;
int olim,money;

class State{
public:
  int cost;
  int oxy;
  int y;
  int x;
  int visited[MAX_COLUMN];
  
  bool operator>(const State &state)const{
    
    return cost + getMD() > state.cost + state.getMD();
  }

  bool operator<(const State &state)const{
    if(y != state.y)
      return y < state.y;
    if(x != state.x)
      return x < state.x;
    if(oxy != state.oxy)
      return oxy < state.oxy;

    if(y == state.y)
      for(int i = 0;i<c;i++)
	if(visited[i] != state.visited[i] && (visited[i] == 0 || state.visited[i] == 0) && isOxygenCell[y][i])
	  return visited[i] < state.visited[i];

    return false;
  }

  bool isInside(int y,int x)const{
    return 0 <= x && x < c && 0 <= y && y < r;
  }

  int getMD()const{
    return isInside(y,x) ? MD[y][x] : MD[y+1][x];
  }
};

bool isInside(int y,int x){
  return 0 <= x && x < c && 0 <= y && y < r;
}

class DijkstraState{
public:
  int cost;
  int y;
  int x;

  bool operator>(const DijkstraState &state)const{
    return cost > state.cost;
  }
};

void setMD(){
  priority_queue<DijkstraState,vector<DijkstraState>,greater<DijkstraState> > qu;
  DijkstraState state,temp;
  bool visited[r][c];

  for(int i = 0;i<r;i++)
    for(int j = 0;j<c;j++)
      visited[i][j] = false;

  state.cost = 0;
  state.y = r-1;
  for(int i = 0;i<c;i++){
    state.x = i;
    qu.push(state);
  }

  while(!qu.empty()){
    state = qu.top();
    qu.pop();

    if(visited[state.y][state.x] == false){
      visited[state.y][state.x] = true;
      MD[state.y][state.x] = state.cost;

      for(int i = 0;i<3;i++){
	int X = state.x+dx[i],Y = state.y-dy[i];
	if(isInside(Y,X)){
	  temp = state;
	  temp.cost += (int)(!isOxygenCell[state.y][state.x])*field[state.y][state.x];
	  temp.y = Y;
	  temp.x = X;
	  qu.push(temp);
	}
      }
    }
  }
}

int Astar(int so){
  priority_queue<State,vector<State>,greater<State> > qu;
  State state,temp;
  map<State,bool> isExist;
  
  state.cost = 0;
  state.oxy = so;
  for(int i = 0;i<c;i++)
    state.visited[i] = 0;
  state.y = -1;
  for(int j = 0;j<c;j++){
    state.x = j;
    qu.push(state);
  }

  while(!qu.empty()){
    state = qu.top();
    qu.pop();

    //cout << "y = " << state.y << ", x = " << state.x << ", oxygen = " << state.oxy << ", cost = " << state.cost << ", MD = " << state.getMD() << endl;

    if(isExist[state] == false && state.oxy > 0 && state.cost + state.getMD() <= money){
      //cout << "y = " << state.y << ", x = " << state.x << ", oxygen = " << state.oxy << ", cost = " << state.cost << endl;
      
      if(state.y == r-1)
	return state.cost;

      if(state.visited[state.x] == 1 && isOxygenCell[state.y][state.x])
	state.oxy = min(state.oxy+field[state.y][state.x],olim);

      for(int i = 0;i<3;i++){
	int Y = state.y+dy[i],X = state.x+dx[i];
	if(isInside(Y,X)){
	  temp = state;
	  if(!isOxygenCell[Y][X] && (i == 0 || state.visited[X] == 0))
	    temp.cost += field[Y][X];
	  temp.oxy--;
	  temp.y = Y;
	  temp.x = X;
	  if(i == 0)
	    for(int j = 0;j<c;j++)
	      temp.visited[j] = 0;
	  temp.visited[X]++;
	  qu.push(temp);
	}
      }
    }
  }
  return -1;
}
	
main(){
  while(cin >> c >> r && c){
    int o;
    cin >> money >> olim >> o;
    for(int i = 0;i<r;i++)
      for(int j = 0;j<c;j++){
	int num;
	cin >> num;
	if(num < 0)
	  field[i][j] = -num;
	else
	  field[i][j] = num;
	isOxygenCell[i][j] = (bool)(num > 0);
      }
    setMD();
    int ans = Astar(o);
    if(ans == -1)
      cout << "NA" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
