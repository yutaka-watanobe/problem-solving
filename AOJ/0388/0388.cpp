/*
２点を決め打ちして、2点を通る直線上にある点の個数を数えるO( N^3 )のアルゴリズムが考えられ\
ますが、時間制限になってしまいます。


起点を全探索し、各起点について、起点を中心として残りの点を偏角ソートし、偏角が同じ点の個\\
数をO(N)で数えることができます。
N個の起点に対するソートにはO(N log N) かかってしまいますが、O(N^2 log N) のアルゴリズムと\
なります。
*/

#include<iostream>
#include<algorithm>
using namespace std;

#define N_MAX 3000
class Point{
public:
  int x, y;
  Point(int x = 0, int y = 0):x(x), y(y){

  }
};

int N, K;
Point P[N_MAX];
Point T[N_MAX];

bool compX(const Point &p1, const Point &p2){
  if ( p1.x == p2.x ) return p1.y < p2.y;
  return p1.x < p2.x;
}

bool compA(const Point &p1, const Point &p2){
  return p2.x*p1.y < p1.x*p2.y;
}

bool eq(const Point &p1, const Point &p2){
  return p2.x*p1.y == p1.x*p2.y;
}

int check(int p, int M){
  sort(T, T + M, compA);
  int maxl = 1;
  int l = 1;
  Point pre = T[0];
  for ( int i = 1; i < M; i++ ){
    if ( eq(pre, T[i]) ){
      l++;
      maxl = max(maxl, l);
    } else {
      l = 1;
    }
    pre = T[i];
  }
  return maxl;
}


bool solve(){
  for ( int i = 0; i < N; i++ ){ // origin
    int k = 0;
    int v = 0;
    for ( int j = i+1; j < N; j++ ){
      if ( P[i].x == P[j].x ){
	v++;
      } else {
	T[k] = P[j];
	T[k].x -= P[i].x;
	T[k].y -= P[i].y;
	k++;
      }
    }
    if ( 1 + v >= K ) return true;
    if ( 1 + check(i, k) >= K ) return true;
  }

  return false;
}

main(){
  cin >> N >> K;
  for ( int i = 0; i < N; i++ ) cin >> P[i].x >> P[i].y;
  sort(P, P + N, compX);

  cout << solve() << endl;

  return 0;
}


bool solve(){
  for ( int i = 0; i < N; i++ ){ // origin
    int k = 0;
    int v = 0;
    for ( int j = i+1; j < N; j++ ){
      if ( P[i].x == P[j].x ){
	v++;
      } else {
	T[k] = P[j];
	T[k].x -= P[i].x;
	T[k].y -= P[i].y;
	k++;
      }
    }
    if ( 1 + v >= K ) return true;
    if ( 1 + check(i, k) >= K ) return true;
  }

  return false;
}

main(){
  cin >> N >> K;
  for ( int i = 0; i < N; i++ ) cin >> P[i].x >> P[i].y;
  sort(P, P + N, compX);

  cout << solve() << endl;

  return 0;
}

