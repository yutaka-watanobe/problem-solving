#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

const int GMAX = 100;

int n;
int g[GMAX][GMAX];
int f[GMAX][GMAX];
int pi[GMAX];
bool vis[GMAX];

void clear(void){
  fill(pi, pi+n, -1);
  fill(vis, vis+n, false);
}

int findAugPath(int src, int sink){
  clear();

  queue<pair<int, int> > q;
  q.push(make_pair(src, INT_MAX));
  vis[src] = true;
  while(!q.empty()){
    pair<int, int> p = q.front();
    int curr = p.first;
    q.pop();

    if(curr == sink) return p.second;

    for(int i = 0; i < n; ++i)
      if(!vis[i] && g[curr][i] - f[curr][i] > 0){
        vis[i] = true;
        pi[i] = curr;
        q.push(make_pair(i, min(p.second, g[curr][i] - f[curr][i])));
      }
  }
  return -1;
}

void flow(int curr, int inc){
  if(pi[curr] != -1){
    f[curr][pi[curr]] -= inc;
    f[pi[curr]][curr] += inc;
    flow(pi[curr], inc);
  }
}

int edmondsKarp(int src, int sink){
  int sum = 0;
  int inc = findAugPath(src, sink);
  while(inc != -1){
    sum += inc;
    flow(sink, inc);
    inc = findAugPath(src, sink);
  }
  return sum;
}

void init(void){
  for(int i = 0; i < n; ++i){
    fill(g[i], g[i] + n, 0);
    fill(f[i], f[i] + n, 0);
  }
}

int main(void){
  int m, f, t, c;
  while(cin >> n){
    cin >> m;
    init();
    for(int i = 0; i < m; ++i){
      cin >> f >> t >> c;
      g[f][t] = c;
    }
    int src, sink;
    cin >> src >> sink;

    cout << edmondsKarp(src, sink) << endl;
  }

  return 0;
}
