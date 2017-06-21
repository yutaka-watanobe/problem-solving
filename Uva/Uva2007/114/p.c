// @JUDGE_ID:  17051CA  114  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define E 0
#define N 1
#define W 2
#define S 3

int m, n;
int wcost;
int p;

vector<vector<int> > value;
vector<vector<int> > cost;
vector<vector<bool> > isPin;

int px, py, direction, life;

int play();
void rotate();

void work(){
  cin >> m >> n;
  cin >> wcost;
  cin >> p;

  value.resize(m);
  cost.resize(m);
  isPin.resize(m);
  for(int i=0; i<m; i++){
    value[i].resize(n, 0);
    cost[i].resize(n, 0);
    isPin[i].resize(n, false);
  }

  for(int i=0; i<p; i++){
    int x, y, v, c;
    cin >> x >> y >> v >> c;
    x--; y--;
    value[x][y] = v;
    cost[x][y] =  c;
    isPin[x][y] = true;
  }

  int sum = 0;
  int s;
  while(1){
    cin >> px;
    if(cin.eof()) break;
    cin >> py >> direction >> life;
    px--; py--;
    sum += play();
  }

  cout << sum << endl;
}

int play(){
//  cout << "Play " << px << " " << py << " " << direction << endl;
  int sum = 0;

  while(1){
  //  cout << "direction " << direction << endl;
    if(life<=1){
      cout << sum << endl;
      return sum;
    }
    /* move */
    int ni, nj;
    ni = px; nj = py;
    if(direction==E){
      ni = px + 1;
    }else if(direction==N){
      nj = py + 1;
    }else if(direction==W){
      ni = px - 1;
    }else if(direction==S){
      nj = py - 1;
    }

    if(ni==0 || ni==m-1 || nj==0 || nj==n-1){ /* wall */
    //  cout << "Wall " << endl;
      rotate();
      life -= wcost;
      continue;
    }

    if(isPin[ni][nj]){/* Pin */
     // cout << "Pin " << endl;
      rotate();
      life -= cost[ni][nj];
      sum += value[ni][nj];
      continue;
    }

    life--;
    px = ni; py = nj;

  }

  return 0;
}

void rotate(){
  direction--;
  if(direction==-1) direction = 3;
  life--;
}

main(){
  work();
}
// @end_of_source_code
