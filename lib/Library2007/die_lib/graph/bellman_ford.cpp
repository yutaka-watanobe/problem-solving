#include <iostream>
#include <algorithm>

using namespace std;

const int GMAX = 100;

int n;
int g[GMAX][GMAX];
int minCost[GMAX];

// O(V^3) ( O(VE) にもできる )
bool bellmanFord(int s){
  minCost[s] = 0;
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      if(minCost[i] != INT_MAX)
        for(int j = 0; j < n; ++j)
          if(g[i][j] != INT_MAX && minCost[j] > minCost[i] + g[i][j])
            minCost[j] = minCost[i] + g[i][j];
  for(int i = 0; i < n; ++i)
    if(minCost[i] != INT_MAX)
      for(int j = 0; j < n; ++j)
        if(g[i][j] != INT_MAX && minCost[j] > minCost[i] + g[i][j])
          return true;
  return false;
}

void init(void){
  for(int i = 0; i < n; ++i)
    fill(g[i], g[i]+n, INT_MAX);
  fill(minCost, minCost+n, INT_MAX);
}

int main(void){
  n = 3;
  init();
  g[0][1] = 3;
  g[1][2] = 3;
  g[2][0] = -7;

  cout << bellmanFord() << endl;
  
  return 0;
}
