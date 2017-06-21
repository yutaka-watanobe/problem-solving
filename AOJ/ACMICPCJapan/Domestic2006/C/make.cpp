#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<pair<int,int > > snake_t;
int ans;
int n;
vector<pair<int,int> > rocks;
int rock_size;
pair<int,int> goal;

set<snake_t> found;
set<snake_t> c_set,n_set;


int wx[] = {1,1,0,0,-1,-1};
int wy[] = {0,-1,1,-1,0,1};

bool connect(const pair<int,int> &p1,const pair<int,int> &p2){
  int dx = p1.first  - p2.first;
  int dy = p1.second - p2.second;
  for(int i=0;i<6;i++){
    if(dx == wx[i] && dy == wy[i]) return true;
  }
  return false;
}

bool next(snake_t &snake, int idx){
  if(idx >= n){
    if(found.find(snake) == found.end()){
      found.insert(snake);
      n_set.insert(snake);
    }
    if(snake[0] == goal) return true;
    else return false;
  }
  
  for(int i=0;i<6;i++){
    pair<int,int> np;
    np.first  = snake[idx].first  + wx[i];
    np.second = snake[idx].second + wy[i];
    if(idx != 0   && !connect(np,snake[idx-1])) continue;
    if(idx != n-1 && !connect(np,snake[idx+1])) continue;
    bool kabenonakaniiru = false;
    for(int j=0;j<rock_size;j++){
      if(rocks[j] == np){
	kabenonakaniiru = true;
	break;
      }
    }
    if(kabenonakaniiru) continue;
    bool dead = false;
    for(int j=0;j<=idx-2;j++){
      
      if(snake[j] == np || connect(np,snake[j])){
	dead = true;
	break;
      }
    }
    if(dead) continue;
    
    pair<int,int> backup = snake[idx];
    snake[idx] = np;
    if(next(snake,idx+2))
      return true;
    snake[idx] = backup;
  }
  // dont move;
  pair<int,int> np = snake[idx];
  bool dead = false;
  for(int j=0;j<=idx-2;j++){
    if(np == snake[j] || connect(np,snake[j])){
      dead = true;
      break;
    }
  }
  if(dead) return false;
  return next(snake,idx+1);
}
int main(void){
  while(true){
    snake_t snake;
    cin >> n;
    if(n==0) break;
    snake.resize(n);
    for(int i=0;i<n;i++)
      cin >> snake[i].first >> snake[i].second;
    cin >> rock_size;
    rocks.resize(rock_size);
    for(int i=0;i<rock_size;i++)
      cin >> rocks[i].first >> rocks[i].second;
    cin >> goal.first >> goal.second;
    found.clear();
    found.insert(snake);
    n_set.clear();
    n_set.insert(snake);
    ans = 0;
    while(true){
      ans++;
      if(ans >= 21) break;
      c_set.swap(n_set);
      n_set.clear();
      //cout << ans << " " << c_set.size() <<endl;
      bool found = false;
      for(set<snake_t>::iterator p = c_set.begin(); p != c_set.end(); p++){
	snake_t snk = *p;
	if(next(snk,0)){
	  found = true;
	  break;
	}
      }
      if(found) break;
    }
    cout << ans << endl;
  }
  return 0;
}

