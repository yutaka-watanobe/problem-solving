// 11069:A Graph Problem:2.0:DP
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define MAX 80

main(){
  int T[MAX];
  T[0] = 0;
  T[1] = 1;
  T[2] = 2;
  T[3] = 2;
  T[4] = 3;
  T[5] = 4;

  for ( int i = 6; i < MAX; i++ ){
    T[i] = T[i-2] + T[i-3];
  }

  int n;
  while( cin >> n ) cout << T[n] << endl;
}
