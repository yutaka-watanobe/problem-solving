#include<stdio.h>

int G[][2] = {{1, 2}, {-1, 3}, {1, -1}, {4, 5}, {5, 2}, {2, 1}}; /* 地図 */

int main(){
  char p[101];
  int cur, i;
  while(1){
    scanf("%s", p);
    if ( p[0] == '#' ) break;
    cur = 0; /* A市を出発 */
    for ( i = 0; p[i] != '\0'; i++ ){
      if ( cur == -1 ) break;
      cur = G[cur][p[i] - '0'];
    }
    printf(cur == 5 ? "Yes\n" : "No\n"); /* B市か判定 */
  }
  return 0;
}
