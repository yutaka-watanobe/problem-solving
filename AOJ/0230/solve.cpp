#include<iostream>
#include<queue>
#include<map>
#include<cassert>

using namespace std;

const int MAX_HEIGHT = 100;
const int MIN_HEIGHT = 3;

class State{
public:
  int build;
  int h;
  int cost;

  bool operator<(const State &state)const{
    if(build != state.build)
      return build < state.build;
    if(h != state.h)
      return h < state.h;
    return false;
  }
};

int h;
int field[2][MAX_HEIGHT];

int bfs(){
  queue<State> qu;
  State state,temp;
  map<State,bool> isExist;

  state.cost = 0;
  state.h = 0;
  for(int i = 0;i<2;i++){
    state.build = i;
    qu.push(state);
  }

  while(!qu.empty()){
    state = qu.front();
    qu.pop();

    if(field[state.build][state.h] == 1){
      while(state.h < h && field[state.build][state.h] == 1)
	state.h++;
      state.h--;
    }
    
    if(field[state.build][state.h] == 2){
      while(state.h >= 0 && field[state.build][state.h] == 2)
	state.h--;
    }
    
    if(isExist[state] == false){
      isExist[state] = true;

      if(state.h == h-1)
	return state.cost;

      for(int i = 0;i<=2;i++){
	temp = state;
	temp.cost++;
	temp.h += i;
	if(temp.h >= h)
	  temp.h = h-1;
	temp.build = (int)( state.build == 0 ? 1 : 0);
	qu.push(temp);
      }
    }
  }
  return -1;
}
	
main(){
  while(cin >> h && h){
    assert( MIN_HEIGHT <= h && h <= MAX_HEIGHT);

    for(int j = 0;j<2;j++)
      for(int i = 0;i<h;i++)
	cin >> field[j][i];

    int ans = bfs();

    if(ans == -1)
      cout << "NA" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
