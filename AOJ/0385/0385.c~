/*
ボゾソートをシミュレーションする解法では、O(NQ)となり制限時間内に解くことは難しい。
毎回、ソートされているかの判定を行う必要はなく、隣り合う要素の大小関係について、順番が妥\\
当でないものの個数（これをdiffとする）をキープしておけばよい。
変更が行われた要素の前後の要素それぞれについて、大小関係の変化を調べ、diffを調整する。dif\
fが０になったとき、ソート済みと判断できる。

両端に番兵を置くとことで、境界の判定を楽に書くことができる。
*/

#include <iostream>
using namespace std;
static const int INF = 2000000000;
int N, A[300002], diff;

void update(int i, int v){
  int d1 = 0, d2 = 0;
  if ( A[i-1] > A[i] ) d1++;
  if ( A[i] > A[i+1] ) d1++;
  A[i] = v;
  if ( A[i-1] > A[i] ) d2++;
  if ( A[i] > A[i+1] ) d2++;
  diff += (d2 - d1);
}

int solve(){
  int a, b, q, v1, v2;
  diff = 0;
  for ( int i = 1; i <= N; i++ ) {
    if ( A[i-1] > A[i] ) diff++;
  }

  if ( diff == 0 ) return 0;
  cin >> q;
  for ( int i = 1; i <= q; i++ ){
    cin >> a >> b;
    v1 = A[a];
    v2 = A[b];
    update(a, v2);
    update(b, v1);
    if ( diff == 0 ) return i;
  }

  return -1;
}

int main() {
  cin >> N;
  for ( int i = 1; i <= N; i++ ) cin >> A[i];
  A[0] = -INF;
  A[N+1] = INF;
  cout << solve() << endl;
  return 0;
}

