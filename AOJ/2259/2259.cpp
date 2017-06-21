#include<iostream>
#include<algorithm>
using namespace std;

main(){
  int M, N;
  cin >> M >> N;
  int maxv = 0;
  for ( int i= 0; i < M; i++ ){
    int x, k = 0;
    for (int j = 0; j < N; j++ ){
      cin >> x;
      if ( x ) k++;
    }
    maxv = max(maxv, k);
  }
  cout << maxv << endl;
}
