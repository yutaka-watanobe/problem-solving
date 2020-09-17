#include<stdio.h>

/* src から dst までの最短距離を求める */
int dist(int src, int dst) {
  int answer = 0;
  if (src == dst) return 0;
  if (src % 2 != 0) { answer++; src++; }
  if (dst % 2 != 0) { answer++; dst--; }
  answer += dist(src / 2, dst / 2);
  return answer;
}

int main(){
  int N, s, d, i;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ){
    scanf("%d %d", &s, &d);
    printf("%d\n", dist(s, d));
  }
  return 0;
}
