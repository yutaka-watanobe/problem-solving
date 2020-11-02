#include <iostream>
using namespace std;
static const int INF = 2000000000;
int N, A[300002], diff;

void update(int i, int v){
  if ( A[i - 1] > A[i] ) diff--;
  if ( A[i] > A[i + 1] ) diff--;
  A[i] = v;
  if ( A[i - 1] > A[i] ) diff++;
  if ( A[i] > A[i + 1] ) diff++;
}

int sort(){
  diff = 0;
  for ( int i = 1; i <= N; i++ ) 
    if ( A[i - 1] > A[i] ) diff++;

  if ( diff == 0 ) return 0;
  
  int Q; cin >> Q;
  for ( int i = 1; i <= Q; i++ ){
    int x, y; cin >> x >> y;
    int v1 = A[x];
    int v2 = A[y];
    update(x, v2);
    update(y, v1);
    if ( diff == 0 ) return i;
  }

  return -1;
}

int main() {
  cin >> N;
  for ( int i = 1; i <= N; i++ ) cin >> A[i];
  A[0] = -INF;
  A[N + 1] = INF;
  cout << sort() << endl;
  return 0;
}

