#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cassert>
using namespace std;
vector<long long> V[500000];

int main() {
  long long N, v;
  cin >> N;

  priority_queue<long long> Q;

  for ( int i = 0; i < N; i++ ){
    long long m;
    cin >> m;
    for ( int j = 0; j < m; j++ ){
      cin >> v;
      Q.push((-1)*v);
    }
    while(Q.size() > (i+1) ) Q.pop();
  }
  assert(Q.size() == N);
  long long sum = 0;
  while( !Q.empty() ){
    sum += Q.top()*(-1);
    Q.pop();
  }

  cout << sum << endl;

}
