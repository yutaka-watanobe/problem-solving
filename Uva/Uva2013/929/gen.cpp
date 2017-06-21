#include<iostream>
using namespace std;

main(){
  int N, M;
  N = 999;
  M = 999;

  cout << "1" << endl;
  cout << N << " " << M << endl;
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < M; j++ ){
      cout << rand()%10 << " ";
    }
    cout << endl;
  }
}
