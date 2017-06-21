#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 500;

const int NONE = 0;
const int LEFT = 1;
const int UP = 2;

string str1, str2;

int cost[3][MAX+1][MAX+1];

template<typename T>
const T &max(const T &a, const T &b, const T &c){
  return max(a, max(b, c));
}

void compute(void){
  int n = str1.size(), m = str2.size();
  cost[NONE][0][0] = cost[LEFT][0][0] = cost[UP][0][0] = 0;
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      if(cost[NONE][i][j] == -INT_MAX)
        cost[NONE][i][j] = max(cost[LEFT][i][j], cost[UP][i][j]);
      if(cost[LEFT][i][j] == -INT_MAX)
        cost[LEFT][i][j] = max(cost[NONE][i][j], cost[UP][i][j]);
      if(cost[UP][i][j] == -INT_MAX)
        cost[UP][i][j] = max(cost[LEFT][i][j], cost[NONE][i][j]);
      
      if(i < n && j < m){
        if(str1[i] == str2[j])
          cost[NONE][i+1][j+1] =
            max(cost[NONE][i][j], cost[LEFT][i][j], cost[UP][i][j]) + 2;
        else
          cost[NONE][i+1][j+1] =
            max(cost[NONE][i][j], cost[LEFT][i][j], cost[UP][i][j]) - 1;
      }
      if(j < m)
        cost[LEFT][i][j+1] =
          max(cost[NONE][i][j] - 5, cost[LEFT][i][j] - (j>0?1:5), cost[UP][i][j] - 5);
      
      if(i < n)
        cost[UP][i+1][j] =
          max(cost[NONE][i][j] - 5, cost[LEFT][i][j] - 5, cost[UP][i][j] - (i>0?1:5));
    }
  }
}

void output(void){
  int n = str1.size(), m = str2.size();
  cout << max(cost[NONE][n][m], max(cost[LEFT][n][m], cost[UP][n][m])) << endl;
}

void init(void){
  int n = str1.size(), m = str2.size();
  for(int i = 0; i <= n; ++i)
    for(int j = 0; j <= m; ++j)
      cost[NONE][i][j] = cost[LEFT][i][j] = cost[UP][i][j] = -INT_MAX;
}

int main(void){
  while(cin >> str1 >> str2){
    init();
    compute();
    output();
  }
  return 0;
}
