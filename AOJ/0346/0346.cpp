#include<iostream>
using namespace std;
static const int N = 12;
int e[N];

bool check(){
  // 選択ソート
  for ( int i = 0; i < N - 1; i++ ){
    int minj = i;
    for ( int j = i + 1; j < N; j++ )
      if ( e[j] < e[minj] ) minj = j;
    swap(e[minj], e[i]);
  }
  
  for ( int i = 0; i < N; i += 4)
    if ( e[i] != e[i + 3] ) return false;
  return true;
}

int main(){
  for ( int i = 0; i < N; i++ ) cin >> e[i];
  cout << (check() ? "yes" : "no") << endl;
  return 0;
}
