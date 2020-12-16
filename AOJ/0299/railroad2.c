#include<stdio.h>
#include<stdlib.h>

int n, m, p;
int dst[10000];

//sからeへの時計回り/反時計回りでの距離
int CWDist (int s, int e) { return (e - s + n) % n; }
int CCWDist (int s, int e) { return (s - e + n) % n; }

//時計回り/反時計回りで次の買い物場所
int CWNext ( int i ) { return i == m - 1 ? dst[0] : dst[i + 1]; }
int CCWNext ( int i ) { return i == 0 ? dst[m - 1] : dst[i - 1]; }

//pからtへ時計回り tからeへ反時計回りで行ったときの距離
int CWTurn ( int p, int t, int e ) { return CWDist(p, t) + CCWDist(t, e); }

//pからtへ反時計回り tからeへ時計回りで行ったときの距離
int CCWTurn ( int p, int t, int e ) { return CCWDist(p, t) + CWDist(t, e); }

int ascend(const void *a, const void *b) {
  return *(char *)a - *(char *)b;
}

int main() {

  int i, j, s = 0, cwNext, ccwNext, dist, tmp;
  scanf("%d %d %d", &n, &m, &p);
    
  for ( i = 0; i < m; ++i ) scanf("%d", &dst[i]);

  qsort(dst, m, sizeof(int), ascend);//昇順ソート

  //買い物する駅のうち 時計回りでpの次の駅がdstの何番目か
  while ( s < m ) {
    if ( dst[s] > p ) break;
    ++s;
  }
    
  //単に反時計回り(case1)と時計回り(case2)する場合
  cwNext  = s == m ? dst[0] : dst[s];
  ccwNext = s == 0 ? dst[m - 1] : dst[s - 1];
  dist = CCWDist(p, cwNext);
  tmp = CWDist(p, ccwNext);
  if ( tmp < dist ) dist = tmp;

  //折り返すパターン２パターン(case3,case4)をM通り
  for ( i = 0; i < m; ++i ) {
    tmp = CWTurn(p, dst[i], CWNext(i));
    if ( tmp < dist ) dist = tmp;
    tmp = CCWTurn(p, dst[i], CCWNext(i));
    if ( tmp < dist ) dist = tmp;
  }

  printf("%d\n", 100 * dist);
  return 0;
}
