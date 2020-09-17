#include<iostream>
using namespace std;

// src から dst までの最短距離を求める
int dist(int src, int dst) {
  if (src == dst) return 0;
  int answer = 0;
  if (src % 2 != 0) { answer++; src++; }
  if (dst % 2 != 0) { answer++; dst--; }
  answer += dist(src / 2, dst / 2);
  return answer;
}

int main(){
  int N, s, d;
  cin >> N;
  for ( int i = 0; i < N; i++ ){
    cin >> s >> d;
    cout << dist(s, d) << endl;
  }
}
