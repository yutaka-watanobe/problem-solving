#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define MAX 10

void play(string line, int N){
  int C[MAX];
  int B = 0;
  for (int i = 0; i < N; i++ ) C[i] = 0;

  for ( int i = 0; i < line.size(); i++ ){
    int p = i%N;
    if ( line[i] == 'M' ){
      C[p]++;
    } else if ( line[i] == 'S' ){
      C[p]++;
      B += C[p];
      C[p] = 0;
    } else if ( line[i] == 'L' ){
      C[p] += B + 1;
      B = 0;
    }
  }

  sort(C, C+N);

  for ( int i = 0; i < N; i++ ) cout << C[i] << " ";
  cout << B << endl;
}

main(){
  int N;
  string line;
  while(1){
    cin >> N;
    if ( N == 0 ) break;
    cin >> line;
    play(line, N);
  }
}
