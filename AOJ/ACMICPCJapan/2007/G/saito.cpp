#include <iostream>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <vector>
#include <map>
#include <queue>
#include <string>

//#define cin fin

using namespace std;

//ifstream fin("G.in");

const int NMAX = 16;
const int ST = 1 << 3;
const int DNUM = 4;
const int DR[DNUM] = {-1, 1, 0, 0};
const int DC[DNUM] = {0, 0, -1, 1};

int row, col, n;
int table[NMAX*NMAX][NMAX*NMAX][NMAX*NMAX];
char g[NMAX][NMAX];

#define GENE(a, b) ((a)*col + (b))

class St{
public:
  int a, b, c;

  St(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c){
  }
  
};

bool isInside(int r, int c){
  return 0 <= r && r < row && 0 <= c && c < col;
}

map<char, int> id;
int poss[3], goals[3];

St encode(void){
  St st;
  if(n >= 1) st.a = poss[0];
  if(n >= 2) st.b = poss[1];
  if(n >= 3) st.c = poss[2];
  return st;
}

void decode(St st){
  if(n >= 1) poss[0] = st.a;
  if(n >= 2) poss[1] = st.b;
  if(n >= 3) poss[2] = st.c;
}

int getID(char ch){
  if(id.find(tolower(ch)) == id.end())
    id.insert(make_pair(tolower(ch), id.size()));
  return id[tolower(ch)];
}

void init(void){
  for(int i = 0; i < row*col; ++i)
    for(int j = 0; j < row*col; ++j)
      fill(table[i][j], table[i][j]+row*col, -1);
}

bool goaled(St st){
  if(n >= 3) return st.a == goals[0] && st.b == goals[1] && st.c == goals[2];
  if(n >= 2) return st.a == goals[0] && st.b == goals[1];
  if(n >= 1) return st.a == goals[0];
}

bool check(const St &st, const St &prev){
  if(n >= 3) return (st.a != st.b && (prev.a != st.b || prev.b != st.a) &&
		     st.b != st.c && (prev.b != st.c || prev.c != st.b) &&
		     st.a != st.c && (prev.a != st.c || prev.c != st.a));
  if(n >= 2) return st.a != st.b && (prev.a != st.b || prev.b != st.a);
  return true;
}

void mkBranch(int depth, const vector<vector<int> > &vs, queue<St> &q, St st, int step, const St &prev){
  if(depth == vs.size()){
    if(check(st, prev)){
      if(table[st.a][st.b][st.c] == -1){
	table[st.a][st.b][st.c] = step;
	q.push(st);
      }
    }
  }
  else{
    for(int j = 0; j < vs[depth].size(); ++j){
      if(depth == 0) st.a = vs[depth][j];
      if(depth == 1) st.b = vs[depth][j];
      if(depth == 2) st.c = vs[depth][j];

      mkBranch(depth+1, vs, q, st, step, prev);
    }
  }
}

vector<int> next(int cur){
  int r = cur / col;
  int c = cur % col;

  vector<int> res;
  res.push_back(cur);
  for(int i =0; i < DNUM; ++i){
    int nr = r + DR[i], nc = c + DC[i];
    if(isInside(nr, nc) && g[nr][nc] != '#')
      res.push_back(GENE(nr, nc));
  }
  return res;
}

int bfs(St st){
  queue<St> q;
  q.push(st);
  table[st.a][st.b][st.c] = 0;
  while(!q.empty()){
    st = q.front();
    q.pop();

    int step = table[st.a][st.b][st.c];
    
//     cout << "  " << st.a << ',' << st.b << ',' << st.c << " : " << step << endl;

    if(goaled(st)) return step;

    vector<vector<int> > states;
    for(int i = 0; i < n; ++i){
      if(i == 0) states.push_back(next(st.a));
      if(i == 1) states.push_back(next(st.b));
      if(i == 2) states.push_back(next(st.c));
    }

    /*/
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < states[i].size(); ++j)
	cout << states[i][j] << ' ';
      cout << endl;
    }
    //*/
    
    mkBranch(0, states, q, st, step+1, st);
  }
  return -1;
}

int main(void){
  string line;
  while(cin >> col >> row >> n){
    if((col|row|n) == 0) break;

    getline(cin, line);

    init();
    for(int i = 0; i < row; ++i){
      for(int j = 0; j < col; ++j){
	g[i][j] = cin.get();
	if(islower(g[i][j])){
	  int my = getID(g[i][j]);
	  g[i][j] = ' ';
	  poss[my] = GENE(i, j);
	}
	else if(isupper(g[i][j])){
	  int my = getID(g[i][j]);
	  g[i][j] = ' ';
	  goals[my] = GENE(i, j);
	}
      }
      getline(cin, line);
    }
    
    cout << bfs(encode()) << endl;
  }
  return 0;
}

